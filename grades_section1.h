/*****************************
 * Module Names: Calculating Average score and Grades of Students.
 * Author: Faisal Javed
 * Date of Creation: 25rd September, 2022
 * Purpose: CS-700 Assignment 1
 * Student ID: 200491169
 ****************************/

/**
  * Code placed here is included only once per translation unit.
  * '#pragma once' is non-standard preprocessor directive intended for implementing compiler-specific preprocessor instructions.
  * It's purpose is to replace the include guards that you use in header files to avoid multiple inclusion.
  * */
#pragma once

#include <iostream> /// library that controls reading from and writing to the standard streams.
#include <fstream> /// library that implements high-level input/output operations on file based streams.
#include <sstream> /// library that allows performing insertion, extraction, and other operations for parsing inputs and converting strings to numbers, and vice-versa.
#include <vector> /// library called vectors are sequence containers representing arrays that can change in size.

/**
 * Module Names: Calculating Average score and Grades of Students.
 * Author: Faisal Javed
 * Date of Creation: 25rd September, 2022
 * Purpose: To store heterogeneous data members under one grouped data structure.
 *          Struct is group of heterogeneous data elements grouped together under one name.
 *          The elements are known as members.
 * */
struct Student {
    std::string name, grade; /// string variables.
    int numberOfSubjects{}; /// integer variable.
    float averageOfSubjectMarks{}; /// float variable.
};

/**
 * Module Names: Calculating Average score and Grades of Students.
 * Author: Faisal Javed
 * Date of Creation: 25rd September, 2022
 * Purpose: Function Prototype to extract data from strings and store it an output file.
 *          Parameter: @vector<string> by reference
 *          Return type: void
 * */
void extractDataAndWriteToFile(const std::vector<std::string> &);

/**
 * Module Names: Calculating Average score and Grades of Students.
 * Author: Faisal Javed
 * Date of Creation: 25rd September, 2022
 * Purpose: Function Prototype for read the contents of a file.
 *          Parameter: @vector<string> by reference
 *          Return type: void
 * */
void readContentFromFile(std::vector<std::string> &);

/**
 * Module Names: Calculating Average score and Grades of Students.
 * Author: Faisal Javed
 * Date of Creation: 25rd September, 2022
 * Purpose: Function Prototype to calculate average marks and grades.
 *          Parameters: @Student by reference, @istringstream by reference
 *          Return type: void
 * */
void calculateAverageAndGradesOfStudents(Student &, std::istringstream &);

/**
 * Module Names: Calculating Average score and Grades of Students.
 * Author: Faisal Javed
 * Date of Creation: 25rd September, 2022
 * Purpose: Inline Function Prototype to calculate the average scores of students.
 *          Parameters: @float by value, @float by value
 *          Return type: @float
 * */
inline float calculateMarksAverage(float, float);

/**
 * Module Names: Calculating Average score and Grades of Students.
 * Author: Faisal Javed
 * Date of Creation: 25rd September, 2022
 * Purpose: Function Prototype to calculate grades of students.
 *          Parameter: @float by reference
 *          Return type: @string
 * */
std::string calculateGrade(float &);

/**
 * Module Names: Calculating Average score and Grades of Students.
 * Author: Faisal Javed
 * Date of Creation: 25rd September, 2022
 * Purpose: Function Prototype to calculate the average scores of students.
 *          Parameter: @Student by reference
 *          Return type: void
 * */
void printDataOnConsole(Student &);

/**
 * Module Names: Calculating Average score and Grades of Students.
 * Author: Faisal Javed
 * Date of Creation: 25rd September, 2022
 * Purpose: Function Prototype to print a horizontal dashed line.
 *         No Parameters.
 *         Return type: void
 * */
inline void printHorizontalDivider();

/**
 * Module Names: Calculating Average score and Grades of Students.
 * Author: Faisal Javed
 * Date of Creation: 25rd September, 2022
 * Purpose: Function Prototype to print table header.
 *         No Parameters.
 *         Return type: void
 * */
void printTableHeaderToConsole();

/**
 * Module Names: Calculating Average score and Grades of Students.
 * Author: Faisal Javed
 * Date of Creation: 25rd September, 2022
 * Purpose: Function Prototype to write processed data to an output file in a formatted fashion.
 *         Parameters : @Student by reference, @ofstream by reference (stream operations to store data to a file).
 *         Return type: void
 * */
void writeDataToFile(Student &, std::ofstream &);

/**
 * Module Names: Calculating Average score and Grades of Students.
 * Author: Faisal Javed
 * Date of Creation: 25rd September, 2022
 * Purpose: Function Prototype to write table header to an output file.
 *         Parameter: @ofstream by reference (stream operations to store data to a file).
 *         Return type: void
 * */
void writeTableHeaderToFile(std::ofstream &);

/**
 * Module Names: Calculating Average score and Grades of Students.
 * Author: Faisal Javed
 * Date of Creation: 25rd September, 2022
 * Purpose: Inline Function Prototype to write a horizontal divider line to an output file.
 *         Parameter: @ofstream by reference (stream operations to store data to a file).
 *         Return type: void
 * */
inline void insertHorizontalDivider(std::ofstream &);

/**
 * Module Names: Calculating Average score and Grades of Students.
 * Author: Faisal Javed
 * Date of Creation: 25rd September, 2022
 * Purpose: Inline Function Prototype to get the name of input file.
 *         No Parameters.
 *         Return type: @string
 * */
inline std::string getFileInputName();

/**
 * Module Names: Calculating Average score and Grades of Students.
 * Author: Faisal Javed
 * Date of Creation: 25rd September, 2022
 * Purpose: Inline Function Prototype to get the name of output file.
 *         No Parameters.
 *         Return type: @string
 * */
inline std::string getFileOutputName();
