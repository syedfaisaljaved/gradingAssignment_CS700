#include <vector>
#include "grades_section1.h"
#include "grades_section2.h"

using namespace std;

int main() {

    vector<string> fileContent;
    readContentFromFile(fileContent);
    extractDataAndWriteToFile(fileContent);


    StudentDataCollection student{};
    readFirstLineFromFile(student);
    readFromFile( student);
    calculateAverageScoreForEachSubject(student);
    calculateGradeForEachExamScore(student);
    displayStudentTable(student);
    return 0;

}