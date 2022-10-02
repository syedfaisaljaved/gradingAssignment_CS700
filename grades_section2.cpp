/*****************************
 * Module Name: Calculating Average subject score and grades for every subject of every student.
 * @author Faisal Javed
 * @date 28th September, 2022
 * Purpose: CS-700 Assignment 1
 * Student ID: 200491169
 ****************************/

#include <iostream> /// library that controls reading from and writing to the standard streams.
#include <fstream> /// library that implements high-level input/output operations on file based streams.
#include <vector> /// library called vectors are sequence containers representing arrays that can change in size.
#include "grades_section2.h" ///!< user-defined header to propagate declarations to code file.

/**
 * 'namespace' is used to organise the names of program entities.
 * The below statement declares that program will be accessing entities whose name are the part of namespace called std.
 * */
using namespace std;

/**
 * Module Name: Calculating Average subject score and grades for every subject of every student.
 * Author: Faisal Javed
 * Date of Creation: 28th September, 2022
 * Purpose: Inline Function to get the name of input file.
 *         @param [in] void
 *         @return [out] string
 * */
inline string getSecondFileInputName() {
    /// returns the filename
    return "grades_Section2.txt";
}

/**
 * Module Name: Calculating Average subject score and grades for every subject of every student.
 * Author: Faisal Javed
 * Date of Creation: 28th September, 2022
 * Purpose: Inline Function to get the name of output file.
 *         @param [in] void
 *         @return [out] string
 * */
inline string getSecondFileOutputName() {
    /// returns the filename
    return "output_Grades_Section2.txt";
}

/**
 * Module Name: Calculating Average subject score and grades for every subject of every student.
 * Author: Faisal Javed
 * Date of Creation: 28th September, 2022
 * Purpose: Function to write the processed data to an output file in a well formatted fashion.
 *          @param [in] student @fn StudentDataCollection
 *          @return [out] void
 * */
void writeStudentTableToFile(StudentDataCollection &student) {

    /**
     * creating an object of output file stream to perform write operations.
     * passed @ getSecondFileOutputName function as a @c string argument which returns the file name.
     * */
    ofstream outputStream(getSecondFileOutputName());

    /**
     * calling this function to write the header of the table to an output file.
     * takes @a StudentDataCollection.numberOfSubjects and @c outputStream as arguments.
     * */
    writeTableHeaderToSecondFile(student.numberOfSubjects, outputStream);

    /// using 2 for loops to iterate over 2D array and write student name and each subject score along with grade.
    /// this loops will run until i is equal to length of @a StudentDataCollection.numberOfStudents
    for (int i = 0; i < student.numberOfStudents; i++) {

        /**
        * using @c left keyword to left-align the data.
        * using @c setw to have a well-formatted output with spacing of the specified width.
        * writing the output to an output file using @c outputStream
        * */
        outputStream << left << setw(2) << "| " << setw(24) << student.studentNamesArr[i];

        /// this loops will run until j is equal to length of @a StudentDataCollection.numberOfSubjects
        for (int j = 0; j < student.numberOfSubjects; j++) {
            /**
             * using @c left keyword to left-align the data.
             * using @c setw to have a well-formatted output with spacing of the specified width.
             * using pipe '|' to separate columns.
             * writing the output to an output file using @c outputStream
             * */
            outputStream << left << setw(12) << "| " + to_string(student.eachExamScoresArr[i][j]) << setw(2) << "| "
                         << setw(8) << student.gradeForEachExamArr[i][j];
        }

        /**
         * using pipe '|' to separate columns.
         * writing the output to an output file using @c outputStream
         * using @c endl to go to next line.
         * */
        outputStream << "  |" << endl;
    }

    /**
     * calling this function to write horizontal divider to output file.
     * takes @c outputStream as argument
     * */
    insertHorizontalDividerLine(outputStream);

    outputStream.close(); /// closing the @c outputStream after performing the write operations.
}

/**
 * Module Name: Calculating Average subject score and grades for every subject of every student.
 * Author: Faisal Javed
 * Date of Creation: 28th September, 2022
 * Purpose: Function to write table header to an output file.
 *         @param [in] numberOfSubjects @param [in] outputStream
 *         @return [out] void
 * */
void writeTableHeaderToSecondFile(int &numberOfSubjects, ofstream &outputStream) {

    /**
     * calling this function to write horizontal divider to output file.
     * takes @c outputStream as argument
     * */
    insertHorizontalDividerLine(outputStream);

    /**
     * using @c left keyword to left-align the data.
     * using @c setw to have a well-formatted output with spacing of the specified width.
     * writing the output to an output file using @c outputStream
     * */
    outputStream << left << setw(25) << "| Student Name";

    /// this loops will run until j is equal to length of @a StudentDataCollection.numberOfSubjects
    for (int j = 0; j < numberOfSubjects; j++) {
        /**
         * using @c left keyword to left-align the data.
         * using @c setw to have a well-formatted output with spacing of the specified width.
         * writing the output to an output file using @c outputStream
         * */
        outputStream << left << setw(12) << " | Subject " + to_string(j + 1) << setw(10)
                     << " | Grade " + to_string(j + 1);
    }

    /**
     * using pipe '|' to separate columns.
     * writing the output to an output file using @c outputStream
     * using @c endl to go to next line.
     * */
    outputStream << " |" << endl;

    /**
     * calling this function to write horizontal divider to output file.
     * takes @c outputStream as argument
     * */
    insertHorizontalDividerLine(outputStream);
}

/**
 * Module Name: Calculating Average subject score and grades for every subject of every student.
 * Author: Faisal Javed
 * Date of Creation: 28th September, 2022
 * Purpose: Inline Function to write a horizontal divider line to an output file.
 *         @param [in] outputStream
 *         @return [out] void
 * */
inline void insertHorizontalDividerLine(ofstream &outputStream) {
    /// writing horizontal line using underscore '_' to output file using @c outputStream.
    /// using @c endl to go to next line.
    outputStream
            << "_________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________"
            << endl;
}

/**
 * Module Name: Calculating Average subject score and grades for every subject of every student.
 * Author: Faisal Javed
 * Date of Creation: 28th September, 2022
 * Purpose: Function to calculate grade for each subject score of every student.
 *          @param [in] student @fn StudentDataCollection
 *          @return [out] void
 * */
void calculateGradeForEachExamScore(StudentDataCollection &student) {

    /**
     * Initializing 2D @c char pointer array.
     * In a two dimensional array, we can access each element by using two subscripts,
     * where first subscript represents the row number and second subscript represents the column number.
     * @c char ** array point to a @c char * array which holds a pointer to an @c char value for each element.
     * */
    student.gradeForEachExamArr = new char *[student.numberOfStudents];

    /// using 2 for loops to traverse over @a StudentDataCollection.eachExamScoresArr and @a StudentDataCollection.averageScoreForEachExamArr to calculate and store grade in @a StudentDataCollection.gradeForEachExamArr
    /// this loops will run until i is equal to length of numberOfStudents
    for (int i = 0; i < student.numberOfStudents; i++) {

        /**
         * Initializing a @c  char pointer array.
         * @c char * array holds a pointer to an @c char value for each element.
         * */
        student.gradeForEachExamArr[i] = new char[student.numberOfSubjects];

        /// this loops will run until j is equal to length of @a StudentDataCollection.numberOfSubjects
        for (int j = 0; j < student.numberOfSubjects; j++) {

            /**
             * CALCULATING GRADE OF EACH SUBJECT SCORE OF EVERY STUDENT IN RESPECT WITH THE AVERAGE SCORE OF EACH SUBJECT.
             * Type Casting integer values of @a StudentDataCollection.eachExamScoresArr to float.
             * Type Casting integer values of @a StudentDataCollection.averageScoreForEachExamArr to float.
             * */
            float difference = (float) student.eachExamScoresArr[i][j] - (float) student.averageScoreForEachExamArr[j];

            /**
             * @if this is if conditions
             * */
            if (difference > 15.0) {
                /// if difference is greater than 15 then assign grade A.
                student.gradeForEachExamArr[i][j] = 'A';
            } else if (difference < -15.0) {
                /// if difference is less than -15 then assign grade F.
                student.gradeForEachExamArr[i][j] = 'F';
            } else if (difference > 5.0) {
                /// if difference is greater than 5 then assign grade B.
                student.gradeForEachExamArr[i][j] = 'B';
            } else if (difference < -5.0) {
                /// if difference is less than -5 then assign grade D.
                student.gradeForEachExamArr[i][j] = 'D';
            } else {
                /// if difference is within -5 and 5 then assign grade C.
                student.gradeForEachExamArr[i][j] = 'C';
            } /// @endif
        }
    }
}

/**
 * Module Name: Calculating Average subject score and grades for every subject of every student.
 * Author: Faisal Javed
 * Date of Creation: 28th September, 2022
 * Purpose: Function to calculate average score for every subject.
 *          @param [in] student @fn StudentDataCollection
 *          @return [out] void
 * */
void calculateAverageScoreForEachSubject(StudentDataCollection &student) {

    /**
     * Initializing a @c float pointer array.
     * @c float * array holds a pointer to an @c float value for each element.
     * */
    student.averageScoreForEachExamArr = new float[student.numberOfSubjects];

    /// using 2 for loops to traverse a 2D pointer array @a StudentDataCollection.eachExamScoresArr and calculate average score of each subject.
    /// this loops will run until i is equal to length of @a StudentDataCollection.numberOfSubjects
    for (int i = 0; i < student.numberOfSubjects; i++) {
        student.averageScoreForEachExamArr[i] = 0; /// initializing with 0 to avoid garbage value.

        /// this loops will run until j is equal to length of @a StudentDataCollection.numberOfStudents
        for (int j = 0; j < student.numberOfStudents; j++) {
            /**
             * CALCULATING AVERAGE BY DIVIDING EACH SUBJECT SCORE WITH TOTAL NO. OF STUDENTS AND THEN ADDING UP ALL.
             * Type Casting integer values of @a StudentDataCollection.eachExamScoresArr to float.
             * Type Casting @a StudentDataCollection.numberOfStudents to float.
             * */
            float average = (float) student.eachExamScoresArr[j][i] / (float) student.numberOfStudents;

            /// adding up all the values to get actual average of each subject.
            student.averageScoreForEachExamArr[i] = student.averageScoreForEachExamArr[i] + average;
        }
    }
}

/**
 * Module Name: Calculating Average subject score and grades for every subject of every student.
 * Author: Faisal Javed
 * Date of Creation: 28th September, 2022
 * Purpose: Function to first line from an input file.
 *          @param [in] student @fn StudentDataCollection
 *          @return [out] void
 * */
void readFirstLineFromFile(StudentDataCollection &student) {

    /**
     * creating an object of input file stream to perform read operations.
     * takes @a StudentDataCollection.getSecondFileInputName function as a @c string argument which returns the file name.
     * */
    ifstream fileStream(getSecondFileInputName());

    /// @if Checks if the file is NOT opened then throw an error and stop the program.
    if (!fileStream.is_open()) {
        /**
         * throw a keyword to define custom exceptions.
         * We will @throw runtime_error exception if the file is unable to open.
         * */
        throw runtime_error("Unable to read file.");
    } /// @endif

    /// streaming the string to store number of students and number of subjects in @a StudentDataCollection.numberOfStudents and @a StudentDataCollection.numberOfSubjects variables respectively.
    fileStream >> student.numberOfStudents >> student.numberOfSubjects;

    /// closing the input file stream after reading the file.
    fileStream.close();
}

/**
 * Module Name: Calculating Average subject score and grades for every subject of every student.
 * Author: Faisal Javed
 * Date of Creation: 28th September, 2022
 * Purpose: Function to read names and exam scores from an input file.
 *          @param [in] student @fn StudentDataCollection
 *          @return [out] void
 * */
void readNameAndScoresFromFile(StudentDataCollection &student) {

    /**
     * creating an object of input file stream to perform read operations.
     * takes @c getSecondFileInputName function as a @c string argument which returns the file name.
     * */
    ifstream fileStream(getSecondFileInputName());

    /// Checks if the file is NOT opened then throw an error and stop the program.
    if (!fileStream.is_open()) {
        /**
         * throw is a keyword to define custom exceptions.
         * We will @throw runtime_error exception if the file is unable to open.
         * */
        throw invalid_argument("Unable to read file.");
    }

    string line; /// to store a line read from the input file.

    /// to skip the first line as we have already processed it using @c readFirstLineFromFile function.
    getline(fileStream, line);

    /**
     * Initializing 2D @c int pointer array.
     * In a two dimensional array, we can access each element by using two subscripts,
     * where first subscript represents the row number and second subscript represents the column number.
     * @c int ** array point to a @c int * array which holds a pointer to an @c int value for each element.
     * */
    student.eachExamScoresArr = new int *[student.numberOfStudents];

    /**
     * Initializing a @c string pointer array.
     * @c string * array holds a pointer to an @c string value for each element.
     * */
    student.studentNamesArr = new string[student.numberOfStudents];

    int iterator = 0; /// to iterate over while loop

    /**
     * use while loop to traverse through all lines in a file.
     * takes @c getline function as an argument.
     * returns false if reached EOF else return true.
     * */
    while (getline(fileStream, line)) {

        /**
         * Initializing a @c int pointer array.
         * @c int * array holds a pointer to an @c int value for each element.
         * */
        student.eachExamScoresArr[iterator] = new int[student.numberOfSubjects];

        /**
         * creating an object of @c istringstream class to stream the string into different variables.
         * Takes a string as an argument.
         * */
        istringstream streamParser(line);

        string firstName, lastName; /// to store students first and last name.

        streamParser >> firstName >> lastName; /// streaming the string to store respective values in the variables.

        student.studentNamesArr[iterator] = firstName.append(" ").append(lastName); /// using @c append to store it as full name in the name member of @a StudentDataCollection struct.

        /// this loops will run until j is equal to length of @a StudentDataCollection.numberOfSubjects
        for (int j = 0; j < student.numberOfSubjects; j++) {

            /**
             * Logic: now we will stream the next value from the stream into an integer.
             * It can be either a integer or a string as some student name has an initial after the last name.
             * An integer can be parsed as a string but not vice-versa.
             * So if we encounter a string the below code will get a parse error,
             * letting us know there is a string then we can re-parse it accordingly.
             * e.g -> ABC PQR 11 (successfully parses it)
             *        LMN XYZ P 4 (fails to parse this as P is not an integer)
             * */
            streamParser >> student.eachExamScoresArr[iterator][j];

            /**
             * returns [true] if either (or both) failbit or the badbit error state flags is set for the stream.
             * If we encounter a string it will return true as it failed to parse it as an integer.
             * */
            if (streamParser.fail()) {
                streamParser.clear(); /// we will clear the error state flags and re-parse the stream properly.
                string initial; /// to store the next occurrence of string in the string stream.
                streamParser >> initial >> student.eachExamScoresArr[iterator][j]; /// parsing the string and integer respectively.
                student.studentNamesArr[iterator].append(" ").append(initial); /// appending the last initial into the fullname on name member of @a StudentDataCollection struct
            }
        }

        iterator++; /// incrementing the iterator.
    }

    /// closing the input file stream after reading the file.
    fileStream.close();
}
