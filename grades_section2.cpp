#include <iostream>
#include <fstream>
#include <vector>
#include "grades_section2.h"

using namespace std;

inline string getSecondFileInputName(){
    return "grades_Section2.txt";
}

inline string getSecondFileOutputName(){
    return "output_Grades_Section2.txt";
}

int **Initialize2DIntArray(StudentDataCollection &student) {
    static int **array = new int *[student.numberOfStudentDataCollections];
    for (int i = 0; i < student.numberOfStudentDataCollections; i++) {
        array[i] = new int[student.numberOfSubjects];
    }
    return array;
}

char **Initialize2DCharArray(StudentDataCollection &student) {
    static char **array = new char *[student.numberOfStudentDataCollections];
    for (int i = 0; i < student.numberOfStudentDataCollections; i++) {
        array[i] = new char[student.numberOfSubjects];
    }
    return array;
}

void displayStudentTable(StudentDataCollection &student) {
    ofstream outputStream(getSecondFileOutputName());

    writeTableHeaderToSecondFile(student.numberOfSubjects, outputStream);
    for (int i = 0; i < student.numberOfStudentDataCollections; i++) {
        outputStream << left << setw(26) << student.studentNamesArr[i];
        for (int j = 0; j < student.numberOfSubjects; j++) {
            outputStream << left << setw(12) << "| " + to_string(student.eachExamScoresArr[i][j]) << setw(2) << "| " << setw(8) << student.gradeForEachExamArr[i][j];
        }
        outputStream << "  |" << endl;
    }

    insertHorizontalDividerLine(outputStream);
    outputStream.close();
}

void writeTableHeaderToSecondFile(int &numberOfSubjects, ofstream & outputStream) {
    insertHorizontalDividerLine(outputStream);
    outputStream << left << setw(25) << "| Student Name";
    for (int j = 0; j < numberOfSubjects; j++) {
        outputStream << left << setw(12) << " | Subject " + to_string(j + 1) << setw(10) << " | Grade " + to_string(j + 1);
    }
    outputStream << " |" << endl;
    insertHorizontalDividerLine(outputStream);
}

inline void insertHorizontalDividerLine(ofstream & outputStream) {
    outputStream
            << "_________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________"
            << endl;
}

void calculateGradeForEachExamScore(StudentDataCollection &student) {
    student.gradeForEachExamArr = Initialize2DCharArray(student);

    for (int i = 0; i < student.numberOfSubjects; i++) {
        for (int j = 0; j < student.numberOfStudentDataCollections; j++) {

            float difference = (float) student.eachExamScoresArr[j][i] - (float) student.averageScoreForEachExamArr[i];

            if (difference > 15.0) {
                student.gradeForEachExamArr[j][i] = 'A';
            } else if (difference < -15.0) {
                student.gradeForEachExamArr[j][i] = 'F';
            } else if (difference > 5.0) {
                student.gradeForEachExamArr[j][i] = 'B';
            } else if (difference < -5.0) {
                student.gradeForEachExamArr[j][i] = 'D';
            } else {
                student.gradeForEachExamArr[j][i] = 'C';
            }
        }
    }
}

void calculateAverageScoreForEachSubject(StudentDataCollection &student) {
    student.averageScoreForEachExamArr = new float[student.numberOfSubjects];
    for (int i = 0; i < student.numberOfSubjects; i++) {
        student.averageScoreForEachExamArr[i] = 0;
        for (int j = 0; j < student.numberOfStudentDataCollections; j++) {
            float average = (float) student.eachExamScoresArr[j][i] / (float) student.numberOfStudentDataCollections;
            student.averageScoreForEachExamArr[i] = student.averageScoreForEachExamArr[i] + average;
        }
    }
}

void readFirstLineFromFile(StudentDataCollection &student) {
    ifstream fileStream(getSecondFileInputName());

    if (!fileStream.is_open()) {
        throw invalid_argument("Unable to read file.");
    }

    fileStream >> student.numberOfStudentDataCollections >> student.numberOfSubjects;

    fileStream.close();
}

void readFromFile(StudentDataCollection &student) {
    ifstream fileStream(getSecondFileInputName());

    if (!fileStream.is_open()) {
        throw invalid_argument("Unable to read file.");
    }

    string line;

    getline(fileStream, line); // skip first line

    student.eachExamScoresArr = Initialize2DIntArray(student);

    student.studentNamesArr = new string[student.numberOfStudentDataCollections];

    int iterator = 0;
    while (getline(fileStream, line)) {

        istringstream streamParser(line);

        string firstName, lastName;
        streamParser >> firstName >> lastName;
        student.studentNamesArr[iterator] = firstName.append(" ").append(lastName);

        for (int j = 0; j < student.numberOfSubjects; j++) {
            streamParser >> student.eachExamScoresArr[iterator][j];

            if (streamParser.fail()) {
                streamParser.clear();
                string initial;
                streamParser >> initial >> student.eachExamScoresArr[iterator][j];
                student.studentNamesArr[iterator].append(initial);
            }
        }

        iterator++;
    }

    fileStream.close();
}
