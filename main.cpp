#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;


void processFileContent(vector<string> fileContent);
void readContentFromFile(vector<string> &fileContent, string &fileName);
void readStudentSubjectMarks(istringstream &streamParser, int &numberOfSubjects);
inline float calculateMarksAverage(int totalMarks, int numberOfSubjects);
string calculateGrade(float averageOfSubjectMarks);
void writeStudentDataToFile(string firstName, string lastName, string initial, string grade, float scoreAverage, int subjectMarks[]);

int main() {

    vector<string> fileContent;
    readContentFromFile(fileContent, (string &) "grades.txt");
    processFileContent(fileContent);
    return 0;
}

void readContentFromFile(vector<string> &fileContent, string &fileName) {
    ifstream fileStream(fileName);

    if(!fileStream.is_open()){
        throw invalid_argument("Unable to read file.");
    }

    string line;
    while(getline(fileStream, line)){
        fileContent.push_back(line);
    }
}

void processFileContent(vector<string> fileContent){
    istringstream streamParser;

    string firstName, lastName;
    char initial;
    int numberOfSubjects;

    streamParser >> firstName >> lastName;

    streamParser >> numberOfSubjects;

    if(streamParser.fail()){
        streamParser.clear();
        streamParser >> initial >> numberOfSubjects;
    }

    int allSubjectMarks[numberOfSubjects];
    int sumOfSubjectMarks = 0;
    for(auto marks : allSubjectMarks){
        streamParser >> marks;
        sumOfSubjectMarks += marks;
    }

    float averageOfSubjectMarks = calculateMarksAverage(sumOfSubjectMarks, numberOfSubjects);

    string grade = calculateGrade(averageOfSubjectMarks);
}

void writeStudentDataToFile(string firstName, string lastName, string initial, string grade, float scoreAverage, int subjectMarks[]){

}

inline float calculateMarksAverage(int totalMarks, int numberOfSubjects){
    return totalMarks / numberOfSubjects;
}

string calculateGrade(float marks){
    if(marks > 95 && marks <= 100){
        return "A";
    } else if(marks > 91.67 && marks <= 95){
        return "A-";
    } else if(marks > 88.3 && marks <= 91.67){
        return "B+";
    } else if(marks > 85 && marks <= 88.3){
        return "B";
    } else if(marks > 81.67 && marks <= 85){
        return "B-";
    } else if(marks > 78.33 && marks <= 81.67){
        return "C+";
    } else if(marks > 75 && marks <= 78.33){
        return "C";
    } else if(marks > 71.67 && marks <= 75){
        return "C-";
    } else if(marks > 68.33 && marks <= 71.67){
        return "D+";
    } else if(marks > 65 && marks <= 68.33){
        return "D";
    } else if(marks > 61.67 && marks <= 65){
        return "D-";
    } else if(marks > 0 && marks <= 61.67){
        return "F";
    }
}
