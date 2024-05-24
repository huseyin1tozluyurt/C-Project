#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
using namespace std;


void fileClearFunc(ifstream& file);
void runProgramme(ifstream& file);
void viewGrades(string line);
void enrollCourse(string line);
void calculateGpa(string line);

class Student {
    
};
class Teacher {

};

string mainMenu() {
    bool x1, x2, x3, x4, condition = false;
    string operation;
    do
    {
        system("cls");
        cout << "**************************************" << endl;
        cout << "Choose one of those operations:" << endl;
        cout << "1-)Login: " << endl;
        cout << "2-)Register: " << endl;
        cout << "3-)Forgot my password: " << endl;
        cout << "4-)Exit: " << endl;
        cout << "***************************************" << endl;
        cout << "Operation: ";
        cin >> operation;
        x1 = (operation == "1");
        x2 = (operation == "2");
        x3 = (operation == "3");
        x4 = (operation == "4");
        condition = (x1 ^ x2 ^ x3 ^ x4);

    } while ((condition == false));
    return operation;
}
/*
int fileSize(ifstream &myFile){
    string line;
    int counter=1;
    while(getline(myFile,line)){
        counter++;
    }
    return counter;
}*/
string getUsername(string& line) {
    size_t position = line.find("\t");
    string username;
    //int positionIndex;
    if (position != string::npos) {
         username= line.substr(0,position);
         return username;
    }
    else {
        string errorMessage = "Username not Found! ";
        return errorMessage;
    }

}
string getId(string& line) {
    size_t position = line.find("\t");
    cout << "Line: " << position << endl;
    string id="";
    int i = 1;
    while ((line[i + position] <= '9') && (line[i + position] >= '0')) {
        id += line[i + position];
        i++;

    }
    return id;
 /* ending = line.find("\t", ending + 1);
    if (position !=string::npos) {
        int begining = position + 1;
        int ending = position -2;
        id = line.substr(begining, ending);
        return id;
    }
  */
}
string getPassword(string& line) {
    size_t position = line.find("\t");
    position = line.find("\t", position + 1);
    //index 20
    int i = (position+1);
    string password="";
    while (line[i] != '\t') {
        password += line[i];
        i++;
    }
    return password;
}
bool message(ifstream& myFile, string& username,int& indexId,string id) {

    string line;
    int currentLineI = 0;
    fileClearFunc(myFile);
    while (getline(myFile, line)) {
        string usernameInfile=getUsername(line);
        string idInFile = getId(line);
        cout << endl <<"Get ID:" << idInFile << endl;
        currentLineI += 1;
        if ( (usernameInfile== username) && (idInFile==id) ) {
            indexId = currentLineI;
            return true;
        }

        /*counter++;
        if(counter==fileSize){
            return false;
        }*/
    }

    cout << "Wrong ID or Username!" << endl;
    return false;

}
string gettingLine(ifstream& file, int lineIndex) {
    string line;
    int currentLine = 1;
    while ((getline(file, line)) && currentLine < lineIndex) {
        currentLine++;
    }
    if (currentLine == lineIndex) {
        return line;
    }
    else {
        // Line number out of range
        cerr << "Line number out of range: " << lineIndex << endl;
        return "";
    }

}
void operationLog(ifstream& file) {
    int indexTxt = 0;
    string username;
    string password;
    string id;
    cout << "-------------------" << endl;
    cout << "Enter '0' to return main menu" << endl;
    cout << "Enter username: ";
    cin >> username;
    if (username == "000") {
        file.close();
        mainMenu();
    }
    cout << "Enter ID: ";
    cin >> id;
    fileClearFunc(file);
    bool result = message(file, username, indexTxt,id);
    //cout << "Line index: " << indexTxt << endl;
    fileClearFunc(file);
    string myLine = gettingLine(file, indexTxt);
    //cout << myLine << endl;
    // file.clear(); // No need to clear here, as we are not writing to the file
    // file.seekg(0, ios::beg); // No need to seek again

    if (result == true) {

        while (true) {
            cout << "Enter password: ";
            cin >> password;
            string passwordInFile = getPassword(myLine);
            if (passwordInFile == password) {
                //user actions
                cout << "True Password." << endl;
                cout << "User" << endl;
                bool condition = false;
                bool x1, x2, x3, x4;
                string operation;
                while (!condition) {
                    cout << "Choose an operation" << endl << "1-)View Grades" << endl << "2-)Calculate GPA" << endl << "3-)Enroll a course from course pool" << endl << "4-)Exit" << endl;
                    cout << "Your operation: ";
                    cin >> operation;
                    x1 = (operation == "1");
                    x2 = (operation == "2");
                    x3 = (operation == "3");
                    x4 = (operation == "4");
                    condition = (x1 ^ x2 ^ x3 ^ x4);

                }
                bool myMessage = false;
                switch (operation[0]) {
                case '1':
                    viewGrades(myLine);
                    break;
                case '2':
                    calculateGpa(myLine);
                    break;
                case '3':
                    enrollCourse(myLine);
                    break;
                case '4':
                    // Exit the program
                    myMessage = true;
                    break;
                default:
                    cout << "Invalid operation. Please choose again." << endl;
                }
                if (myMessage == true)
                    break;
            }

            else {
                string decs;
                cout << "Invalid Password" << endl;
                cout << "-Press '0' to return main menu" << endl << "-Press any key except '0' to continue" << endl;
                cout << "Operation: ";
                cin >> decs;
                if (decs == "0") {
                    runProgramme(file);
                    break;
                }
                else
                    continue;

                }

            }
        }
    /*
    string dec;
    cout << "Press 1 to go: ";
    cin >> dec;
    if(dec=="1")
        runProgramme(file);
    */
}
void fileClearFunc(ifstream& file) {
    file.clear(); // Clear error flags
    file.seekg(0, ios::beg); // Move the file pointer to the beginning    
}
void runProgramme(ifstream& file) {
    if (file.is_open())
    {
        int indexTxt = 0;
        string operation = mainMenu();
        if (operation == "1") {
            operationLog(file);
        }
        else if (operation == "2") {

        }
        else if (operation == "3") {

        }
        else if (operation == "4") {

        }
    }
}
void viewGrades(string line) {

}
void calculateGpa(string line) {

}
void enrollCourse(string line) {

}

int main()
{
    ifstream file("info.txt");
    runProgramme(file);
    /*
        else if (operation == "4") {
            file.close();
            return 0;
        }
    }
    */
    file.close();
    return 0;
}
