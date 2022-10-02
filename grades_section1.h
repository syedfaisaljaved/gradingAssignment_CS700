/*****************************
 * @name Module Name: Calculating Average score and Grades of Students.
 * @author Author: Faisal Javed
 * @date Date of Creation: 25th September, 2022
 * @details Purpose: CS-700 Assignment 1
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
 * @name Module Name: Calculating Average score and Grades of Students.
 * @author Author: Faisal Javed
 * @date Date of Creation: 25th September, 2022
 * @details Purpose: To store heterogeneous data members under one grouped data structure.
 *          Struct is group of heterogeneous data elements grouped together under one name.
 *          The elements are known as members.
 *          @var string name
 *          @var string grade
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
 * @name Module Name: Calculating Average score and Grades of Students.
 * @author Author: Faisal Javed
 * @date Date of Creation: 25th September, 2022
 * @details Purpose: Function Prototype to extract data from strings and store it an output file.
 *          @param [in] std::vector
 *          @return [out] void
 * */
void extractDataAndWriteToFile(const std::vector<std::string> &);

/**
 * @name Module Name: Calculating Average score and Grades of Students.
 * @author Author: Faisal Javed
 * @date Date of Creation: 25th September, 2022
 * @details Purpose: Function Prototype for read the contents of a file.
 *          @param [in] std::vector
 *          @return [out] void
 * */
void readContentFromFile(std::vector<std::string> &);

/**
 * @name Module Name: Calculating Average score and Grades of Students.
 * @author Author: Faisal Javed
 * @date Date of Creation: 25th September, 2022
 * @details Purpose: Function Prototype to calculate average marks and grades.
 *          @param [in] Student @param [in] istringstream
 *          @return [out] void
 * */
void calculateAverageAndGradesOfStudents(Student &, std::istringstream &);

/**
 * @name Module Name: Calculating Average score and Grades of Students.
 * @author Author: Faisal Javed
 * @date Date of Creation: 25th September, 2022
 * @details Purpose: Inline Function Prototype to calculate the average scores of students.
 *          @param float @param [in] float
 *          @return [out] @float
 * */
inline float calculateMarksAverage(float, float);

/**
 * @name Module Name: Calculating Average score and Grades of Students.
 * @author Author: Faisal Javed
 * @date Date of Creation: 25th September, 2022
 * @details Purpose: Function Prototype to calculate grades of students.
 *          @param [in] float
 *          @returns [out] string
 * */
std::string calculateGrade(float &);

/**
 * @name Module Name: Calculating Average score and Grades of Students.
 * @author Author: Faisal Javed
 * @date Date of Creation: 25th September, 2022
 * @details Purpose: Function Prototype to calculate the average scores of students.
 *          @param [in] Student
 *          @return [out] void
 * */
void printDataOnConsole(Student &);

/**
 * @name Module Name: Calculating Average score and Grades of Students.
 * @author Author: Faisal Javed
 * @date Date of Creation: 25th September, 2022
 * @details Purpose: Function Prototype to print a horizontal dashed line.
 *         @param [in] void
 *         @return [out] void
 * */
inline void printHorizontalDivider();

/**
 * @name Module Name: Calculating Average score and Grades of Students.
 * @author Author: Faisal Javed
 * @date Date of Creation: 25th September, 2022
 * @details Purpose: Function Prototype to print table header.
 *         @param [in] void
 *         @return [out] void
 * */
void printTableHeaderToConsole();

/**
 * @name Module Name: Calculating Average score and Grades of Students.
 * @author Author: Faisal Javed
 * @date Date of Creation: 25th September, 2022
 * @details Purpose: Function Prototype to write processed data to an output file in a formatted fashion.
 *         @param [in] Student @param [in] ofstream
 *         @return [out] void
 * */
void writeDataToFile(Student &, std::ofstream &);

/**
 * @name Module Name: Calculating Average score and Grades of Students.
 * @author Author: Faisal Javed
 * @date Date of Creation: 25th September, 2022
 * @details Purpose: Function Prototype to write table header to an output file.
 *         @param [in] ofstream
 *         @return [out] void
 * */
void writeTableHeaderToFile(std::ofstream &);

/**
 * @name Module Name: Calculating Average score and Grades of Students.
 * @author Author: Faisal Javed
 * @date Date of Creation: 25th September, 2022
 * @details Purpose: Inline Function Prototype to write a horizontal divider line to an output file.
 *         @param [in] ofstream
 *         @return [out] void
 * */
inline void insertHorizontalDivider(std::ofstream &);

/**
 * @name Module Name: Calculating Average score and Grades of Students.
 * @author Author: Faisal Javed
 * @date Date of Creation: 25th September, 2022
 * @details Purpose: Inline Function Prototype to get the name of input file.
 *         @param [in] void
 *         @return [out] string
 * */
inline std::string getFileInputName();

/**
 * @name Module Name: Calculating Average score and Grades of Students.
 * @author Author: Faisal Javed
 * @date Date of Creation: 25th September, 2022
 * @details Purpose: Inline Function Prototype to get the name of output file.
 *         @param [in] void
 *         @return [out] string
 * */
inline std::string getFileOutputName();
