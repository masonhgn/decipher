
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

typedef char list;

char alphabet[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R','S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'}; // alphabet for reference of caesar ciphering

string FILE_NAME; //file name variable for user to input file name to be opened
int cipherOption; //number of spaces shifted
int shiftNum; //newly fixed number for cipher spaces shifted after converted from ascii value
string cipherCode = ""; //for the given code for substitution deciphering
string deciphered = ""; // finished, deciphered output.
string nonDeciphered = "";

void subCipher () { // deciphering text the substitution way.

    char ch; //current character that is being examined

    cout << "Please provide a file name. \n";
    cin >> FILE_NAME;
    ifstream inFile;
    inFile.open(FILE_NAME);

    while (inFile.get(ch)) {
        for (const char l : alphabet) { // bad data checking
            if (ch == l) {
                cout << "You should have picked the Caesar option instead. Exiting...";
                exit(EXIT_SUCCESS);
            }
        }

        cipherCode += ch;
        if (ch == '\n') {
            break;
        }
    }

    while (inFile.get(ch)) { // checks for characters
        nonDeciphered += ch;

        if (ch == '.') {
            deciphered += '.';
        }

        if (ch == '\n') {
            deciphered += '\n';
        }

        deciphered += alphabet[cipherCode.find(ch)];
    }

    cout << cipherCode;

}



void caesarCipher() { //deciphers using the caesar method
    char ch; //current character that is being examined
    list sub[] = {'!','@','#','$','%','^','&','*','(',')','_','+','{','}','|',':','"','<','>','?',';','-','=','[',']','/' }; //array for bad data checking
    char encryption[26];



    cout << "Please provide a file name. \n";
    cin >> FILE_NAME;
    ifstream inFile;
    inFile.open(FILE_NAME);


    while (inFile.get(ch)) {// checks for characters

        for (int i = 0; i < sizeof(sub)/sizeof(sub[0]); i++) {// bad data checking
            if (ch == sub[i]) {
                cout << "You should have picked the substitution option instead. Exiting...";
                exit(EXIT_SUCCESS);
            }
        }
    }

    while (inFile.get(ch)) {
        nonDeciphered += ch;

        if (isdigit(ch)) { //checking for a number provided to tell how many spaces will be shifted.
            shiftNum = ch;
            shiftNum -= 48; // 48 is the ASCII value for 0 in chars so I converted it to an int this way because casting was not working.
            break;
        }

        int j = 0;


        for (int i=shiftNum; i < 26; i++) {
            encryption[j] = alphabet[i];
            j++;
            }

        for (int i = 0; i < shiftNum; i++) {
            encryption[j] = alphabet[i];
            j++;
            }
        }
    cout << "encryption: " << encryption << endl;

    while (inFile.get(ch)) {

        if (ch == ' ') {//checking for spaces
            deciphered += ' ';
        }

        if (ch == '\n') {//checking for new lines
            deciphered += ' ';
        }



        }
    }








void startMenu() { // main start menu interface
    cout << "Please decide what type of cipher you want to decode your file with. \n";
    cout << "\nType [1] for Caesar Cipher \n";
    cout << "Type [2] for Substitution Cipher \n";
    cout << "Type [3] to quit." << endl;
    cin >> cipherOption;

    if (cipherOption == 1) {
        caesarCipher();
    }
    else if (cipherOption == 2) {
        subCipher();
    }
    else if (cipherOption == 3) {
        exit(EXIT_SUCCESS);
    }
    else {
        cout << "Invalid option.";
        startMenu();
    }

}

int main() {

    startMenu();
    cout << "Here is your original text: \n \n";
    cout << nonDeciphered << endl;
    cout << "Here is your deciphered message: \n \n";
    cout << deciphered;



    return 0;
}





