/*****************************
 * Module Names: Calculating Average score and Grades of Students.
 * Author: Faisal Javed
 * Date of Creation: 25rd September, 2022
 * Purpose: CS-700 Assignment 1
 * Student ID: 200491169
 ****************************/

#include <iostream> /// library that controls reading from and writing to the standard streams.
#include <vector> /// library called vectors are sequence containers representing arrays that can change in size.
#include <iomanip> /// library which helps us in manipulating the output of the program.
#include "grades_section1.h" /// user-defined header @file which contains all function prototypes.

/**
 * 'namespace' is used to organise the names of program entities.
 * The below statement declares that program will be accessing entities whose name are the part of namespace called std.
 * */
using namespace std;

/**
 * Module Names: Calculating Average score and Grades of Students.
 * Author: Faisal Javed
 * Date of Creation: 25rd September, 2022
 * Purpose: Inline Function to get the name of input file,
 *          so the file name can be changed in future without letting the client know.
 *         It takes no Parameters.
 *         Return type: @string
 * */
inline string getFileInputName(){
    return "grades.txt";
}

/**
 * Module Names: Calculating Average score and Grades of Students.
 * Author: Faisal Javed
 * Date of Creation: 25rd September, 2022
 * Purpose: Inline Function to get the name of output file,
 *          so the file name can be changed in future without letting the client know.
 *         It takes no Parameters.
 *         Return type: @string
 * */
inline string getFileOutputName(){
    return "output_Grades.txt";
}

/**
 * Module Names: Calculating Average score and Grades of Students.
 * Author: Faisal Javed
 * Date of Creation: 25rd September, 2022
 * Purpose: Function to read the contents of a file line by line and
 *          storing the string lines to a string vector.
 *          Parameter: @vector<string> by reference
 *          Return type: void
 * */
void readContentFromFile(vector<string> &fileContent) {
    /**
     * creating an object of input file stream to perform read operations.
     * takes @getFileInputName function as an argument which returns the file name.
     * */
    ifstream fileStream(getFileInputName());

    /// Checks if the file is NOT opened then throw an error and stop the program.
    if (!fileStream.is_open()) {
        /**
         * throw is a keyword to define custom exceptions.
         * We will throw an exception if the file is unable to open.
         * */
        throw invalid_argument("Unable to read file.");
    }

    string line; /// to store a line read from the input file.

    /**
     * use while loop to traverse through all lines in a file.
     * takes @getline function as an argument.
     * returns false if reached EOF else return true.
     * */
    while (getline(fileStream, line)) {
        /// storing each line read from input file to string vector
        fileContent.push_back(line);
    }

    /// closing the input file stream after reading the file.
    fileStream.close();
}

/**
 * Module Names: Calculating Average score and Grades of Students.
 * Author: Faisal Javed
 * Date of Creation: 25rd September, 2022
 * Purpose: Function to print data to the console and write data in a formatted fashion
 *          to an output file after calculating the average score and grades.
 *          Parameter: @vector<string> by reference
 *          Return type: void
 * */
void extractDataAndWriteToFile(const vector<string> &fileContent) {

    /**
     * creating an object of output file stream to perform write operations.
     * takes @getFileOutputName function as an argument which returns the file name.
     * */
    ofstream outputStream(getFileOutputName());

    /// Checks if the file is NOT opened then throw an error and stop the program.
    if (!outputStream.is_open()) {
        /**
         * throw is a keyword to define custom exceptions.
         * We will throw an exception if the file is unable to open.
         * */
        throw invalid_argument("Unable to open a file to write operations.");
    }

    printTableHeaderToConsole(); /// calling this function to print the header of the table to console.

    /**
     * calling this function to write the header of the table to an output file.
     * takes @outputStream as argument.
     * */
    writeTableHeaderToFile(outputStream);

    Student student; /// declaration of struct named Student

    /// using range based loop to iterate over lines read stored in string vector to
    /// perform stream parsing operations to get name and subject scores.
    for (const auto &line: fileContent) {

        /**
         * creating an object of @istringstream class to stream the string into different variables.
         * Takes a string as an argument.
         * */
        istringstream streamParser(line);

        string firstName, lastName; /// to store students first and last name.

        streamParser >> firstName >> lastName; /// streaming the string to store respective values in the variables.

        student.name = firstName.append(" ").append(lastName); /// using @append to store it as full name in the name member of @Student struct.

        /**
         * Logic: now we will stream the next value from the stream into an integer.
         * It can be either a integer or a string as some student name has an initial after the last name.
         * An integer can be parsed as a string but not vice-versa.
         * So if we encounter a string the below code will get a parse error,
         * letting us know there is a string then we can re-parse it accordingly.
         * e.g -> ABC PQR 11 (successfully parses it)
         *        LMN XYZ P 4 (fails to parse this as P is not an integer)
         * */
        streamParser >> student.numberOfSubjects;

        /**
         * returns [true] if either (or both) failbit or the badbit error state flags is set for the stream.
         * If we encounter a string it will return true as it failed to parse it as an integer.
         * */
        if (streamParser.fail()) {
            streamParser.clear(); /// we will clear the error state flags and re-parse the stream properly.
            string lastInitial; /// to store the next occurrence of string in the string stream.

            streamParser >> lastInitial >> student.numberOfSubjects; /// parsing the string and integer respectively.

            student.name.append(" ").append(lastInitial); /// appending the last initial into the fullname on name member of @Student struct
        }

        /**
         * calling this function to calculate the average and grades of students.
         * takes @Student struct and @istringstream as arguments.
         * */
        calculateAverageAndGradesOfStudents(student, streamParser);

        /**
         * calling this function to print the data on console.
         * takes @Student struct as argument.
         * */
        printDataOnConsole(student);

        /**
         * calling this function to write the data to an output file in a formatted fashion.
         * takes @Student struct and @outputStream as arguments.
         * */
        writeDataToFile(student, outputStream);
    }

    printHorizontalDivider(); /// calling this function calculate to print horizontal dash divider on console.

    /**
     * calling this function to write the horizontal divider to an output file.
     * takes @outputStream as argument.
     * */
    insertHorizontalDivider(outputStream);

    outputStream.close(); /// closing the @outputStream after performing the write operations.

}

/**
 * Module Names: Calculating Average score and Grades of Students.
 * Author: Faisal Javed
 * Date of Creation: 25rd September, 2022
 * Purpose: Function to calculate average marks and grades.
 *          Parameter: @Student by reference, @istringstream by reference
 *          Return type: void
 * */
void calculateAverageAndGradesOfStudents(Student &student, istringstream &streamParser) {
    int sumOfSubjectMarks = 0; /// initializing with 0 to avoid garbage value.

    /// using for loop to calculate sum of all subject scores and storing each subject scores.
    for (int i = 0; i < student.numberOfSubjects; i++) {
        int subjectMarks; /// to store subject score.
        streamParser >> subjectMarks; /// streamed subject score into the variable.
        sumOfSubjectMarks += subjectMarks; /// adding up the sum of each subject score.
    }

    /**
     * calling @calculateMarksAverage to calculate Average score and storing in @Student structs' @averageOfSubjectMarks member variable.
     * type casting the integers to float to get the decimal values.
     * */
    student.averageOfSubjectMarks = calculateMarksAverage((float) sumOfSubjectMarks, (float) student.numberOfSubjects);

    /**
     * calling @calculateGrade to calculate Average score and storing in @Student structs' @grade member variable.
     * */
    student.grade = calculateGrade(student.averageOfSubjectMarks);
}


/**
 * Module Names: Calculating Average score and Grades of Students.
 * Author: Faisal Javed
 * Date of Creation: 25rd September, 2022
 * Purpose: Function to calculate average marks and grades.
 *          Parameter: @Student by reference
 *          Return type: void
 * */
void printDataOnConsole(Student &student) {
    /**
     * using @left keyword to left-align the data.
     * using @setw to have a well-formatted output with spacing of the specified width.
     * using @setprecision = 5 to set the decimal values upto 5 digits.
     * using pipe '|' to separate columns.
     * */
    cout << left << "| " << setw(25) << student.name << setw(5) << setw(2) << "|" << setw(18) << setprecision(5)
         << student.averageOfSubjectMarks << setw(2) << "|" << setw(6) << student.grade << setw(2) << "|" << endl;
}


/**
 * Module Names: Calculating Average score and Grades of Students.
 * Author: Faisal Javed
 * Date of Creation: 25rd September, 2022
 * Purpose: Function to calculate average marks and grades.
 *          No Parameter
 *          Return type: void
 * */
void printTableHeaderToConsole() {

    printHorizontalDivider(); /// calling this function to print horizontal divider on console.

    /**
     * using @left keyword to left-align the data.
     * using @setw to have a well-formatted output with spacing of the specified width.
     * using pipe '|' to separate columns.
     * printing the output to console using @outputStream
     * */
    cout << left << setw(27) << "| Student Name" << setw(20) << "| Average Score" << setw(20) << "| Grade |" << endl;

    printHorizontalDivider(); /// calling this function to print horizontal divider on console.
}


/**
 * Module Names: Calculating Average score and Grades of Students.
 * Author: Faisal Javed
 * Date of Creation: 25rd September, 2022
 * Purpose: Inline Function to calculate average marks and grades.
 *          No Parameter
 *          Return type: void
 * */
inline void printHorizontalDivider() {
    /// printing horizontal line using underscore '_' on console.
    cout << "________________________________________________________" << endl;
}


/**
 * Module Names: Calculating Average score and Grades of Students.
 * Author: Faisal Javed
 * Date of Creation: 25rd September, 2022
 * Purpose: Function to write the processed data to output file in a well formatted fashion.
 *          Parameter: @struct by reference, @ofstream by reference
 *          Return type: void
 * */
void writeDataToFile(Student &student, ofstream &outputStream) {
    /**
     * using @left keyword to left-align the data.
     * using @setw to have a well-formatted output with spacing of the specified width.
     * using pipe '|' to separate columns.
     * writing the output to an output file using @outputStream
     * */
    outputStream << left << "| " << setw(25) << student.name << setw(5) << setw(2) << "|" << setw(18) << setprecision(5)
                 << student.averageOfSubjectMarks << setw(2) << "|" << setw(6) << student.grade << setw(2) << "|"
                 << endl;
}

/**
 * Module Names: Calculating Average score and Grades of Students.
 * Author: Faisal Javed
 * Date of Creation: 25rd September, 2022
 * Purpose: Function to write table header to an output file in a well formatted fashion.
 *         Parameter: @ofstream by reference (stream operations to store data to a file).
 *         Return type: void
 * */
void writeTableHeaderToFile(ofstream &outputStream) {
    /**
     * calling this function to write horizontal divider to output file.
     * takes @outputStream as argument
     * */
    insertHorizontalDivider(outputStream);

    /**
     * using @left keyword to left-align the data.
     * using @setw to have a well-formatted output with spacing of the specified width.
     * using pipe '|' to separate columns.
     * writing the output to an output file using @outputStream
     * */
    outputStream << left << setw(27) << "| Student Name" << setw(20) << "| Average Score" << setw(20) << "| Grade |"
                 << endl;

    /**
     * calling this function to write horizontal divider to output file.
     * takes @outputStream as argument
     * */
    insertHorizontalDivider(outputStream);
}

/**
 * Module Names: Calculating Average score and Grades of Students.
 * Author: Faisal Javed
 * Date of Creation: 25rd September, 2022
 * Purpose: Inline Function to write a horizontal dashed line to an output file.
 *         Parameter: @ofstream by reference (stream operations to store data to a file).
 *         Return type: void
 * */
inline void insertHorizontalDivider(ofstream &outputStream) {
    /// writing horizontal line using underscore '_' to output file using @outputStream.
    outputStream << "________________________________________________________" << endl;
}

/**
 * Module Names: Calculating Average score and Grades of Students.
 * Author: Faisal Javed
 * Date of Creation: 25rd September, 2022
 * Purpose: Inline Function to calculate the average scores of students.
 *          Parameters: @float by value, @float by value
 *          Return type: @float
 * */
inline float calculateMarksAverage(float totalMarks, float numberOfSubjects) {
    /// returns the average calculated as a float.
    return totalMarks / numberOfSubjects;
}

/**
 * Module Names: Calculating Average score and Grades of Students.
 * Author: Faisal Javed
 * Date of Creation: 25rd September, 2022
 * Purpose: Function to calculate grades of students.
 *          Parameter: @float by reference
 *          Return type: @string
 * */
string calculateGrade(float &marks) {

    if (marks > 95 && marks <= 100) {
        /// if the scores are greater than 95 and less than equal to 100, then return grade 'A'
        return "A";
    } else if (marks > 91.67 && marks <= 95) {
        /// if the scores are greater than 91.67 and less than equal to 95, then return grade 'B'
        return "A-";
    } else if (marks > 88.3 && marks <= 91.67) {
        /// if the scores are greater than 88.3 and less than equal to 91.67, then return grade 'B+'
        return "B+";
    } else if (marks > 85 && marks <= 88.3) {
        /// if the scores are greater than 85 and less than equal to 88.3, then return grade 'B'
        return "B";
    } else if (marks > 81.67 && marks <= 85) {
        /// if the scores are greater than 81.67 and less than equal to 85, then return grade 'B-'
        return "B-";
    } else if (marks > 78.33 && marks <= 81.67) {
        /// if the scores are greater than 78.33 and less than equal to 81.67, then return grade 'C+'
        return "C+";
    } else if (marks > 75 && marks <= 78.33) {
        /// if the scores are greater than 75 and less than equal to 78.33, then return grade 'C'
        return "C";
    } else if (marks > 71.67 && marks <= 75) {
        /// if the scores are greater than 71.67 and less than equal to 75, then return grade 'C-'
        return "C-";
    } else if (marks > 68.33 && marks <= 71.67) {
        /// if the scores are greater than 68.33 and less than equal to 71.67, then return grade 'D+'
        return "D+";
    } else if (marks > 65 && marks <= 68.33) {
        /// if the scores are greater than 65 and less than equal to 68.33, then return grade 'D'
        return "D";
    } else if (marks > 61.67 && marks <= 65) {
        /// if the scores are greater than 61.67 and less than equal to 65, then return grade 'D-'
        return "D-";
    } else if (marks > 0 && marks <= 61.67) {
        /// if the scores are greater than 0 and less than equal to 61.67, then return grade 'F'
        return "F";
    } else {
        /// this is unreachable condition, only provided to return a value in all control paths.
        return "";
    }
}
