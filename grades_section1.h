//
// Modified by Faisal Javed on 01/10/22.
//
#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

#ifndef GRADINGASSIGNMENT_CS700_GRADES_SECTION1_H
#define GRADINGASSIGNMENT_CS700_GRADES_SECTION1_H

struct Student {
    std::string name, grade;
    std::vector<int> allSubjectMarks;
    int numberOfSubjects{};
    float averageOfSubjectMarks{};
};

void extractDataAndWriteToFile(const std::vector<std::string> &fileContent);

void readContentFromFile(std::vector<std::string> &fileContent);

void readStudentSubjectMarks(Student &student, std::istringstream &streamParser);

inline float calculateMarksAverage(float totalMarks, float numberOfSubjects);

std::string calculateGrade(float averageOfSubjectMarks);

void printDataOnConsole(Student &student);

inline void printHorizontalDivider();

void printTableHeaderToConsole();

void writeDataToFile(Student &student, std::ofstream &outputStream);

void writeTableHeaderToFile(std::ofstream &outputStream);

inline void insertHorizontalDivider(std::ofstream &outputStream);

inline std::string getFileInputName();
inline std::string getFileOutputName();

#endif //GRADINGASSIGNMENT_CS700_GRADES_SECTION1_H
