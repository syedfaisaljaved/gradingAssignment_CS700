//
// Created by Faisal Javed on 30/09/22.
//

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "main_section2.h"

using namespace std;

struct StudentDataCollection {
    int **eachExamScoresArr;
    string *studentNamesArr;
    float *averageScoreForEachExamArr;
    char **gradeForEachExamArr;
    int numberOfStudents, numberOfSubjects;
};

void readContentFromFile(string &fileName);

void readFromFile(string &fileName, StudentDataCollection &);

void readFirstLineFromFile(string &fileName, StudentDataCollection &);

void calculateAverageScoreForEachSubject(StudentDataCollection &);

void calculateGradeForEachExamScore(StudentDataCollection &);

void displayStudentTable(StudentDataCollection &);

int **Initialize2DIntArray(StudentDataCollection &);
char **Initialize2DCharArray(StudentDataCollection &);

int main() {
    StudentDataCollection student{};

    readFirstLineFromFile((string &) "grades_Section2.txt", student);
    readFromFile((string &) "grades_Section2.txt", student);

    calculateAverageScoreForEachSubject(student);
    calculateGradeForEachExamScore(student);
    displayStudentTable(student);
//    readContentFromFile((string &) "grades_Section2.txt");
    return 0;
}

int **Initialize2DIntArray(StudentDataCollection &student) {
    static int ** array = new int * [student.numberOfStudents];
    for(int i = 0; i < student.numberOfStudents; i++){
        array[i] = new int[student.numberOfSubjects];
    }
    return array;
}

char **Initialize2DCharArray(StudentDataCollection &student) {
    static char ** array = new char * [student.numberOfStudents];
    for(int i = 0; i < student.numberOfStudents; i++){
        array[i] = new char[student.numberOfSubjects];
    }
    return array;
}

void displayStudentTable(StudentDataCollection &student) {
    for (int i = 0; i < student.numberOfStudents; i++) {
        cout << left << setw(30) << student.studentNamesArr[i];
        for (int j = 0; j < student.numberOfSubjects; j++) {
            cout << left << setw(5) << student.eachExamScoresArr[i][j] << setw(3) << "->" << setw(5)
                 << student.gradeForEachExamArr[i][j] << setw(10) << " average :" << setw(10) << setprecision(4)
                 << student.averageScoreForEachExamArr[j];
        }
        cout << endl;
    }

}

void calculateGradeForEachExamScore(StudentDataCollection &student) {
    student.gradeForEachExamArr = Initialize2DCharArray(student);

    for (int i = 0; i < student.numberOfSubjects; i++) {
        for (int j = 0; j < student.numberOfStudents; j++) {

            float difference = (float) student.eachExamScoresArr[j][i] - (float) student.averageScoreForEachExamArr[i];

//            cout << "diff " << difference << endl;
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
        for (int j = 0; j < student.numberOfStudents; j++) {
//            cout << "student " << j+1 << " subject " << i+1 << " is " << student.eachExamScoresArr[j][i] << endl;
//            cout << "average before adding " << student.averageScoreForEachExamArr[i] << endl;

            float average = (float) student.eachExamScoresArr[j][i] / (float) student.numberOfStudents;
//            cout << "average calc is " << average << endl;
            student.averageScoreForEachExamArr[i] = student.averageScoreForEachExamArr[i] + average;
//            cout << "student " << i+1 << " subject average is " << student.averageScoreForEachExamArr[i] << endl;
        }
    }
}

//void readContentFromFile(string &fileName) {
//    ifstream fileStream(fileName);
//
//    if (!fileStream.is_open()) {
//        throw invalid_argument("Unable to read file.");
//    }
//
//    int numberOfStudents, numberOfSubjects;
//    string line;
//
////    getNumberOfStudentsAndSubjects(fileStream, numberOfStudents, numberOfSubjects);
//
//    int eachExamScores[numberOfStudents][numberOfSubjects];
//    string studentNamesArr[numberOfStudents];
//
//    int iterator = 0;
//    while (getline(fileStream, line)) {
//        istringstream streamParser(line);
//
////        cout << "line " << line << endl;
//        string firstName, lastName;
//        streamParser >> firstName >> lastName;
//        studentNamesArr[iterator] = firstName.append(" ").append(lastName);
//
//        for(int j = 0; j < numberOfSubjects; j++){
//            streamParser >> eachExamScores[iterator][j];
//
//            if (streamParser.fail()) {
//                streamParser.clear();
//                string initial;
//                streamParser >> initial >> eachExamScores[iterator][j];
//                studentNamesArr[iterator].append(initial);
//            }
//
////            cout << studentNamesArr[iterator] << " score " << j+1 << " is: " << eachExamScores[iterator][j] << endl;
//        }
//
//        iterator++;
//    }
//
//    fileStream.close();
//
//    float averageScoreForEachExam[numberOfSubjects];
//    char gradeForEachExam[numberOfStudents][numberOfSubjects];
//
//    for(int i = 0; i < numberOfSubjects; i++){
//        averageScoreForEachExam[i] = 0;
//        for(int j = 0; j < numberOfStudents; j++){
//            cout << "student " << j+1 << " subject " << i+1 << " is " << eachExamScores[j][i] << endl;
//            cout << "average before adding " << averageScoreForEachExam[i] << endl;
//
//            float average = (float) eachExamScores[j][i]/(float)numberOfStudents;
//            cout << "average calc is " << average << endl;
//            averageScoreForEachExam[i] = averageScoreForEachExam[i] + average;
//            cout << "student " << i+1 << " subject average is " << averageScoreForEachExam[i] << endl;
//        }
//    }
//
//    for(int i = 0; i < numberOfSubjects; i++){
//        for(int j = 0; j < numberOfStudents; j++){
//
//            float difference = (float) eachExamScores[j][i] - (float) averageScoreForEachExam[i];
//
//            cout << "diff " << difference << endl;
//            if(difference > 15.0){
//                gradeForEachExam[j][i] = 'A';
//            } else if(difference < -15.0){
//                gradeForEachExam[j][i] = 'F';
//            } else if(difference > 5.0){
//                gradeForEachExam[j][i] = 'B';
//            } else if(difference < -5.0){
//                gradeForEachExam[j][i] = 'D';
//            } else {
//                gradeForEachExam[j][i] = 'C';
//            }
//        }
//    }
//
//    for(int i = 0; i < numberOfStudents; i++){
//        cout << left << setw(30) << studentNamesArr[i];
//        for(int j = 0; j < numberOfSubjects; j++){
//            cout << left << setw(5) << eachExamScores[i][j] << setw(3) << "->" << setw(5) << gradeForEachExam[i][j] << setw(10) << " average :" << setw(10) << setprecision(4) << averageScoreForEachExam[j];
//        }
//        cout << endl;
//    }
//
//}

void readFirstLineFromFile(string &fileName, StudentDataCollection &student) {
    ifstream fileStream(fileName);

    if (!fileStream.is_open()) {
        throw invalid_argument("Unable to read file.");
    }

    fileStream >> student.numberOfStudents >> student.numberOfSubjects;

    fileStream.close();
}

void readFromFile(string &fileName, StudentDataCollection &student) {
    ifstream fileStream(fileName);

    if (!fileStream.is_open()) {
        throw invalid_argument("Unable to read file.");
    }

    string line;

    getline(fileStream, line); // skip first line

    student.eachExamScoresArr = Initialize2DIntArray(student);

    student.studentNamesArr = new string[student.numberOfStudents];

    int iterator = 0;
    while (getline(fileStream, line)) {

        istringstream streamParser(line);

//        cout << "line " << line << endl;

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

//            cout << studentNamesArr[iterator] << " score " << j+1 << " is: " << eachExamScores[iterator][j] << endl;
        }

        iterator++;
    }

    fileStream.close();
}
