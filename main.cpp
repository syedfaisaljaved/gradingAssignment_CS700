/*****************************
 * Module Names:
 *          1) Calculating Average score and Grades of Students.
 *          2) Calculating Average subject score and grades for every subject of every student.
 * @author Author: Faisal Javed
 * @date Date of Creation: 23rd September, 2022
 * @details Purpose: CS-700 Assignment 1
 * Student ID: 200491169
 ****************************/

/**
 * '#' is called preprocessor directive.
 * '<>' is used for pre-defined header files.
 * It read the program before it is compiled and executes only those lines which starts with '#'
 * */
#include <vector> /// header file called vectors are sequence containers representing arrays that can change in size.
#include "grades_section1.h" /// user-defined header @file grades_section1.h to propagate declarations to code file.
#include "grades_section2.h"  /// user-defined header @file grades_section2.h to propagate declarations to code file.

/**
 * 'namespace' is used to organise the names of program entities.
 * The below statement declares that program will be accessing entities whose name are the part of namespace called std.
 * */
using namespace std;

/*****************************
 * Module Names:
 *          1) Calculating Average score and Grades of Students.
 *          2) Calculating Average subject score and grades for every subject of every student.
 * @author Author: Faisal Javed
 * @date Date of Creation: 23rd September, 2022
 * @details Purpose: main() Function serves as the starting point for program execution.
 *          It has no arguments and returns 0 if the program is executed successfully.
 *          @param void
 *          @return int
 ****************************/
int main() { /// opening brace - program execution starts here.

    /**
     * @name Module Name: Calculating Average score and Grades of Students.
     * */
    vector<string> fileContent; /// creating a vector of string to store the lines read from input file.
    readContentFromFile(fileContent); /// function to read content of a input file.
    extractDataAndWriteToFile(fileContent); /// function to calculate average, grades and writing to an output file.

    /**
     * @name Module Name: Calculating Average subject score and grades for every subject of every student.
     * */
    StudentDataCollection student{}; /// declaration of struct named StudentDataCollection
    readFirstLineFromFile(student); /// function to read first line from input file
    readNameAndScoresFromFile(student); /// function to read student names and scores from input file
    calculateAverageScoreForEachSubject(student); /// function to calculate average subject score.
    calculateGradeForEachExamScore(student); /// function to calculate grade for every score of every student.
    writeStudentTableToFile(student); /// writing the calculated score and grades to outpput file in formatted fashion.
    return 0; /// returns 0 if the program is executed successfully because main() has a return type of integer.
} /// closing brace - program terminates here.