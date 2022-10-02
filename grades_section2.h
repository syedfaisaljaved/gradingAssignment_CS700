/*****************************
 * Module Names: Calculating Average subject score and grades for every subject of every student.
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
 * Module Names: Calculating Average subject score and grades for every subject of every student.
 * Author: Faisal Javed
 * Date of Creation: 25rd September, 2022
 * Purpose: To store heterogeneous data members under one grouped data structure.
 *          Struct is group of heterogeneous data elements grouped together under one name.
 *          The elements are known as members.
 * */
struct StudentDataCollection {
    int **eachExamScoresArr;
    std::string *studentNamesArr;
    float *averageScoreForEachExamArr;
    char **gradeForEachExamArr;
    int numberOfStudents, numberOfSubjects;
};

/**
 * Module Names: Calculating Average subject score and grades for every subject of every student.
 * Author: Faisal Javed
 * Date of Creation: 25rd September, 2022
 * Purpose: Function Prototype to read names and exam scores from an input file.
 *          Parameter: @StudentDataCollection by reference
 *          Return type: void
 * */
void readNameAndScoresFromFile(StudentDataCollection &student);

/**
 * Module Names: Calculating Average subject score and grades for every subject of every student.
 * Author: Faisal Javed
 * Date of Creation: 25rd September, 2022
 * Purpose: Function Prototype to first line from an input file.
 *          Parameter: @StudentDataCollection by reference
 *          Return type: void
 * */
void readFirstLineFromFile(StudentDataCollection &);

/**
 * Module Names: Calculating Average subject score and grades for every subject of every student.
 * Author: Faisal Javed
 * Date of Creation: 25rd September, 2022
 * Purpose: Function Prototype to calculate average score for every subject.
 *          Parameter: @StudentDataCollection by reference
 *          Return type: void
 * */
void calculateAverageScoreForEachSubject(StudentDataCollection &);

/**
 * Module Names: Calculating Average subject score and grades for every subject of every student.
 * Author: Faisal Javed
 * Date of Creation: 25rd September, 2022
 * Purpose: Function Prototype to calculate grade for each subject score of every student.
 *          Parameter: @StudentDataCollection by reference
 *          Return type: void
 * */
void calculateGradeForEachExamScore(StudentDataCollection &);

/**
 * Module Names: Calculating Average subject score and grades for every subject of every student.
 * Author: Faisal Javed
 * Date of Creation: 25rd September, 2022
 * Purpose: Function Prototype to write the processed data to an output file in a well formatted fashion.
 *          Parameter: @StudentDataCollection by reference
 *          Return type: void
 * */
void writeStudentTableToFile(StudentDataCollection &);

/**
 * Module Names: Calculating Average subject score and grades for every subject of every student.
 * Author: Faisal Javed
 * Date of Creation: 25rd September, 2022
 * Purpose: Inline Function Prototype to write a horizontal divider line to an output file.
 *         Parameters: @ofstream by reference (stream operations to store data to a file).
 *         Return type: void
 * */
inline void insertHorizontalDividerLine(std::ofstream &);

/**
 * Module Names: Calculating Average subject score and grades for every subject of every student.
 * Author: Faisal Javed
 * Date of Creation: 25rd September, 2022
 * Purpose: Function Prototype to write table header to an output file.
 *         Parameter: @int by reference, @ofstream by reference (stream operations to store data to a file).
 *         Return type: void
 * */
void writeTableHeaderToSecondFile(int &, std::ofstream &);

/**
 * Module Names: Calculating Average subject score and grades for every subject of every student.
 * Author: Faisal Javed
 * Date of Creation: 25rd September, 2022
 * Purpose: Inline Function Prototype to get the name of input file.
 *         No Parameters.
 *         Return type: @string
 * */
inline std::string getSecondFileInputName();

/**
 * Module Names: Calculating Average subject score and grades for every subject of every student.
 * Author: Faisal Javed
 * Date of Creation: 25rd September, 2022
 * Purpose: Inline Function Prototype to get the name of output file.
 *         No Parameters.
 *         Return type: @string
 * */
inline std::string getSecondFileOutputName();