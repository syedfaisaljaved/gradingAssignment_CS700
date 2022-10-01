#include <iostream>
#include <vector>
#include <iomanip>
#include "grades_section1.h"

using namespace std;


inline string getFileInputName(){
    return "grades.txt";
}

inline string getFileOutputName(){
    return "output_Grades.txt";
}

void readContentFromFile(vector<string> &fileContent) {
    ifstream fileStream(getFileInputName());

    if (!fileStream.is_open()) {
        throw invalid_argument("Unable to read file.");
    }

    string line;
    while (getline(fileStream, line)) {
        fileContent.push_back(line);
    }

    fileStream.close();
}

void extractDataAndWriteToFile(const vector<string> &fileContent) {

    ofstream outputStream(getFileOutputName());

    if (!outputStream.is_open()) {
        throw invalid_argument("Unable to open a file to write operations.");
    }

    printTableHeaderToConsole();
    writeTableHeaderToFile(outputStream);

    Student student;

    for (const auto &line: fileContent) {

        istringstream streamParser(line);

        string firstName, lastName;

        streamParser >> firstName >> lastName;

        student.name = firstName.append(" ").append(lastName);

        streamParser >> student.numberOfSubjects;

        if (streamParser.fail()) {
            streamParser.clear();
            string lastInitial;

            streamParser >> lastInitial >> student.numberOfSubjects;

            student.name.append(" ").append(lastInitial);
        }

        readStudentSubjectMarks(student, streamParser);

        printDataOnConsole(student);

        writeDataToFile(student, outputStream);
    }

    printHorizontalDivider();
    insertHorizontalDivider(outputStream);

    outputStream.close();

}

void readStudentSubjectMarks(Student &student, istringstream &streamParser) {
    int sumOfSubjectMarks = 0;
    for (int i = 0; i < student.numberOfSubjects; i++) {
        int subjectMarks;
        streamParser >> subjectMarks;
        student.allSubjectMarks.push_back(subjectMarks);
        sumOfSubjectMarks += student.allSubjectMarks[i];
    }

    student.averageOfSubjectMarks = calculateMarksAverage((float) sumOfSubjectMarks, (float) student.numberOfSubjects);

    student.grade = calculateGrade(student.averageOfSubjectMarks);
}

void printDataOnConsole(Student &student) {
    cout << left << "| " << setw(25) << student.name << setw(5) << setw(2) << "|" << setw(18) << setprecision(5)
         << student.averageOfSubjectMarks << setw(2) << "|" << setw(6) << student.grade << setw(2) << "|" << endl;
}

void printTableHeaderToConsole() {
    printHorizontalDivider();
    cout << left << setw(27) << "| Student Name" << setw(20) << "| Average Score" << setw(20) << "| Grade |" << endl;
    printHorizontalDivider();
}

inline void printHorizontalDivider() {
    cout << "________________________________________________________" << endl;
}

void writeDataToFile(Student &student, ofstream &outputStream) {
    outputStream << left << "| " << setw(25) << student.name << setw(5) << setw(2) << "|" << setw(18) << setprecision(5)
                 << student.averageOfSubjectMarks << setw(2) << "|" << setw(6) << student.grade << setw(2) << "|"
                 << endl;
}

void writeTableHeaderToFile(ofstream &outputStream) {
    insertHorizontalDivider(outputStream);
    outputStream << left << setw(27) << "| Student Name" << setw(20) << "| Average Score" << setw(20) << "| Grade |"
                 << endl;
    insertHorizontalDivider(outputStream);
}

inline void insertHorizontalDivider(ofstream &outputStream) {
    outputStream << "________________________________________________________" << endl;
}

inline float calculateMarksAverage(float totalMarks, float numberOfSubjects) {
    return totalMarks / numberOfSubjects;
}

string calculateGrade(float marks) {
    if (marks > 95 && marks <= 100) {
        return "A";
    } else if (marks > 91.67 && marks <= 95) {
        return "A-";
    } else if (marks > 88.3 && marks <= 91.67) {
        return "B+";
    } else if (marks > 85 && marks <= 88.3) {
        return "B";
    } else if (marks > 81.67 && marks <= 85) {
        return "B-";
    } else if (marks > 78.33 && marks <= 81.67) {
        return "C+";
    } else if (marks > 75 && marks <= 78.33) {
        return "C";
    } else if (marks > 71.67 && marks <= 75) {
        return "C-";
    } else if (marks > 68.33 && marks <= 71.67) {
        return "D+";
    } else if (marks > 65 && marks <= 68.33) {
        return "D";
    } else if (marks > 61.67 && marks <= 65) {
        return "D-";
    } else if (marks > 0 && marks <= 61.67) {
        return "F";
    } else {
        return "";
    }
}
