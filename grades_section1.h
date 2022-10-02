/*****************************
 * @name Module Name: Calculating Average score and Grades of Students.
 * @author Faisal Javed
 * @date 25th September, 2022
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
 * Module Name: Calculating Average score and Grades of Students.
 * Author: Faisal Javed
 * Date of Creation: 25th September, 2022
 * Purpose: To store heterogeneous data members under one grouped data structure.
 *          Struct is group of heterogeneous data elements grouped together under one name.
 *          The elements are known as members.
 *          @var std::string name
 *          @var std::string grade
 *          @var int numberOfSubjects
 *          @var float averageOfSubjectMarks
 *          @struct Student
 * */
struct Student {
    std::string name, grade; /// string variables.
    int numberOfSubjects{}; /// integer variable.
    float averageOfSubjectMarks{}; /// float variable.
};

/**
 * Module Name: Calculating Average score and Grades of Students.
 * Author: Faisal Javed
 * Date of Creation: 25th September, 2022
 * Purpose: Function Prototype to extract data from strings and store it an output file.
 *          @param [in] std::vector
 *          @return [out] void
 * */
void extractDataAndWriteToFile(const std::vector<std::string> &);

/**
 * Module Name: Calculating Average score and Grades of Students.
 * Author: Faisal Javed
 * Date of Creation: 25th September, 2022
 * Purpose: Function Prototype for read the contents of a file.
 *          @param [in] std::vector
 *          @return [out] void
 * */
void readContentFromFile(std::vector<std::string> &);

/**
 * Module Name: Calculating Average score and Grades of Students.
 * Author: Faisal Javed
 * Date of Creation: 25th September, 2022
 * Purpose: Function Prototype to calculate average marks and grades.
 *          @param [in] Student @param [in] istringstream
 *          @return [out] void
 * */
void calculateAverageAndGradesOfStudents(Student &, std::istringstream &);

/**
 * Module Name: Calculating Average score and Grades of Students.
 * Author: Faisal Javed
 * Date of Creation: 25th September, 2022
 * Purpose: Inline Function Prototype to calculate the average scores of students.
 *          @param float @param [in] float
 *          @return [out] @float
 * */
inline float calculateMarksAverage(float, float);

/**
 * Module Name: Calculating Average score and Grades of Students.
 * Author: Faisal Javed
 * Date of Creation: 25th September, 2022
 * Purpose: Function Prototype to calculate grades of students.
 *          @param [in] float
 *          @returns [out] std::string
 * */
std::string calculateGrade(float &);

/**
 * Module Name: Calculating Average score and Grades of Students.
 * Author: Faisal Javed
 * Date of Creation: 25th September, 2022
 * Purpose: Function Prototype to calculate the average scores of students.
 *          @param [in] Student
 *          @return [out] void
 * */
void printDataOnConsole(Student &);

/**
 * Module Name: Calculating Average score and Grades of Students.
 * Author: Faisal Javed
 * Date of Creation: 25th September, 2022
 * Purpose: Function Prototype to print a horizontal dashed line.
 *         @param [in] void
 *         @return [out] void
 * */
inline void printHorizontalDivider();

/**
 * Module Name: Calculating Average score and Grades of Students.
 * Author: Faisal Javed
 * Date of Creation: 25th September, 2022
 * Purpose: Function Prototype to print table header.
 *         @param [in] void
 *         @return [out] void
 * */
void printTableHeaderToConsole();

/**
 * Module Name: Calculating Average score and Grades of Students.
 * Author: Faisal Javed
 * Date of Creation: 25th September, 2022
 * Purpose: Function Prototype to write processed data to an output file in a formatted fashion.
 *         @param [in] Student @param [in] ofstream
 *         @return [out] void
 * */
void writeDataToFile(Student &, std::ofstream &);

/**
 * Module Name: Calculating Average score and Grades of Students.
 * Author: Faisal Javed
 * Date of Creation: 25th September, 2022
 * Purpose: Function Prototype to write table header to an output file.
 *         @param [in] ofstream
 *         @return [out] void
 * */
void writeTableHeaderToFile(std::ofstream &);

/**
 * Module Name: Calculating Average score and Grades of Students.
 * Author: Faisal Javed
 * Date of Creation: 25th September, 2022
 * Purpose: Inline Function Prototype to write a horizontal divider line to an output file.
 *         @param [in] ofstream
 *         @return [out] void
 * */
inline void insertHorizontalDivider(std::ofstream &);

/**
 * Module Name: Calculating Average score and Grades of Students.
 * Author: Faisal Javed
 * Date of Creation: 25th September, 2022
 * Purpose: Inline Function Prototype to get the name of input file.
 *         @param [in] void
 *         @return [out] std::string
 * */
inline std::string getFileInputName();

/**
 * Module Name: Calculating Average score and Grades of Students.
 * Author: Faisal Javed
 * Date of Creation: 25th September, 2022
 * Purpose: Inline Function Prototype to get the name of output file.
 *         @param [in] void
 *         @return [out] std::string
 * */
inline std::string getFileOutputName();
