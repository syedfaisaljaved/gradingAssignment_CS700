/*****************************
 * @name Module Name: Calculating Average subject score and grades for every subject of every student.
 * @author Author: Faisal Javed
 * @date Date of Creation: 28th September, 2022
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
 * @name Module Name: Calculating Average subject score and grades for every subject of every student.
 * @author Author: Faisal Javed
 * @date Date of Creation: 28th September, 2022
 * @details Purpose: To store heterogeneous data members under one grouped data structure.
 *          Struct is group of heterogeneous data elements grouped together under one name.
 *          The elements are known as members.
 *          @struct StudentDataCollection
 *          @var int **eachExamScoresArr
 *          @var float *averageScoreForEachExamArr
 *          @var string *studentNamesArr
 *          @var int numberOfStudents
 *          @var int numberOfSubjects
 * */
struct StudentDataCollection {
    int **eachExamScoresArr;
    std::string *studentNamesArr;
    float *averageScoreForEachExamArr;
    char **gradeForEachExamArr;
    int numberOfStudents, numberOfSubjects;
};

/**
 * @name Module Name: Calculating Average subject score and grades for every subject of every student.
 * @author Author: Faisal Javed
 * @date Date of Creation: 28th September, 2022
 * @details Purpose: Function Prototype to read names and exam scores from an input file.
 *          @param [in] StudentDataCollection
 *          @return [out] void
 * */
void readNameAndScoresFromFile(StudentDataCollection &);

/**
 * @name Module Name: Calculating Average subject score and grades for every subject of every student.
 * @author Author: Faisal Javed
 * @date Date of Creation: 28th September, 2022
 * @details Purpose: Function Prototype to first line from an input file.
 *          @param [in] StudentDataCollection
 *          @return [out] void
 * */
void readFirstLineFromFile(StudentDataCollection &);

/**
 * @name Module Name: Calculating Average subject score and grades for every subject of every student.
 * @author Author: Faisal Javed
 * @date Date of Creation: 28th September, 2022
 * @details Purpose: Function Prototype to calculate average score for every subject.
 *          @param [in] StudentDataCollection
 *          @return [out] void
 * */
void calculateAverageScoreForEachSubject(StudentDataCollection &);

/**
 * @name Module Name: Calculating Average subject score and grades for every subject of every student.
 * @author Author: Faisal Javed
 * @date Date of Creation: 28th September, 2022
 * @details Purpose: Function Prototype to calculate grade for each subject score of every student.
 *          @param [in] StudentDataCollection
 *          @return [out] void
 * */
void calculateGradeForEachExamScore(StudentDataCollection &);

/**
 * @name Module Name: Calculating Average subject score and grades for every subject of every student.
 * @author Author: Faisal Javed
 * @date Date of Creation: 28th September, 2022
 * @details Purpose: Function Prototype to write the processed data to an output file in a well formatted fashion.
 *          @param [in] StudentDataCollection
 *          @return [out] void
 * */
void writeStudentTableToFile(StudentDataCollection &);

/**
 * @name Module Name: Calculating Average subject score and grades for every subject of every student.
 * @author Author: Faisal Javed
 * @date Date of Creation: 28th September, 2022
 * @details Purpose: Inline Function Prototype to write a horizontal divider line to an output file.
 *         @param [in] ofstream
 *         @return [out] void
 * */
inline void insertHorizontalDividerLine(std::ofstream &);

/**
 * @name Module Name: Calculating Average subject score and grades for every subject of every student.
 * @author Author: Faisal Javed
 * @date Date of Creation: 28th September, 2022
 * @details Purpose: Function Prototype to write table header to an output file.
 *         @param [in] int @param [in] ofstream
 *         @return [out] void
 * */
void writeTableHeaderToSecondFile(int &, std::ofstream &);

/**
 * @name Module Name: Calculating Average subject score and grades for every subject of every student.
 * @author Author: Faisal Javed
 * @date Date of Creation: 28th September, 2022
 * @details Purpose: Inline Function Prototype to get the name of input file.
 *         @param [in] void
 *         @return [out] string
 * */
inline std::string getSecondFileInputName();

/**
 * @name Module Name: Calculating Average subject score and grades for every subject of every student.
 * @author Author: Faisal Javed
 * @date Date of Creation: 28th September, 2022
 * @details Purpose: Inline Function Prototype to get the name of output file.
 *         @param [in] void
 *         @return [out] string
 * */
inline std::string getSecondFileOutputName();