//
// Created by Faisal Javed on 30/09/22.
//

#ifndef GRADINGASSIGNMENT_CS700_GRADES_SECTION2_H
#define GRADINGASSIGNMENT_CS700_GRADES_SECTION2_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>


struct StudentDataCollection {
    int **eachExamScoresArr;
    std::string *studentNamesArr;
    float *averageScoreForEachExamArr;
    char **gradeForEachExamArr;
    int numberOfStudentDataCollections, numberOfSubjects;
};

void readFromFile(StudentDataCollection &);

void readFirstLineFromFile(StudentDataCollection &);

void calculateAverageScoreForEachSubject(StudentDataCollection &);

void calculateGradeForEachExamScore(StudentDataCollection &);

void displayStudentTable(StudentDataCollection &);

int **Initialize2DIntArray(StudentDataCollection &);

char **Initialize2DCharArray(StudentDataCollection &);

inline void insertHorizontalDividerLine(std::ofstream &);

void writeTableHeaderToSecondFile(int &, std::ofstream &);

inline std::string getSecondFileInputName();
inline std::string getSecondFileOutputName();

#endif //GRADINGASSIGNMENT_CS700_GRADES_SECTION2_H
