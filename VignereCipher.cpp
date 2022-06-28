// Vignere Cipher
// Date    : 28 Mar. 2022
// Author  : Kareem Magdy
// Version : 1.0


#include <iostream>
using namespace std;

void vignereCipher(string userWord, int opt);

int main() {

    vignereCipher("dsadad", 1);
    return 0;
}

    void encrypt(string userInput, string repeatedKeyword) {
        char encryptChar = 'A';
        int temp;

        if (userInput.length() <= 80 && repeatedKeyword.length() >= 8) {

            for (int i = 0; i < userInput.length(); i++) {

                if (isalpha(userInput[i]) && isalpha(repeatedKeyword[i])) {
                    userInput[i] = (char) toupper(userInput[i]);
                    repeatedKeyword[i] = (char) toupper(repeatedKeyword[i]);

                    temp = ((userInput[i] + repeatedKeyword[i]) % 26) + encryptChar;
                    temp = toupper(char(temp));
                    cout << (char) temp;

                } else {
                    cout << userInput[i];
                }
            }


        }


    }
    void decrypt(string userInput, string repeatedKeyword) {
        char decryptChar = 'A';
        int temp;


        if (userInput.length() <= 80 && repeatedKeyword.length() >= 8) {

            for (int i = 0; i < userInput.length(); i++) {
                if (isalpha(userInput[i]) && isalpha(repeatedKeyword[i])) {
                    userInput[i] = (char) toupper(userInput[i]);
                    repeatedKeyword[i] = (char) toupper(repeatedKeyword[i]);

                    temp = (userInput[i] - decryptChar) - (repeatedKeyword[i] - decryptChar);
                    if (temp < 0) {

                        cout << (char) toupper(temp + decryptChar + 26);
                    } else {

                        cout << (char) toupper(temp + decryptChar);
                    }

                } else {
                    cout << userInput[i];
                }
            }


        }


    }
    void vignereCipher(string userWord, int opt) {

        string userKeyWord;







            if (opt == 1) {

                cout << "\nPlease enter the Key word :";
                cin >> userKeyWord;
                cout << "\n______________________Encryption________________________" << endl;
                cout << "message           : " << userWord << endl;
                cout << "repeated keyword  : " << userKeyWord << endl;
                cout << "encrypted message : ";
                encrypt(userWord, userKeyWord);

                cout << "\n________________________________________________________" << endl;
            } else if (opt == 2) {

                cout << "\nPlease enter the Key word :";
                cin >> userKeyWord;
                cout << "\n______________________Decryption________________________" << endl;
                cout << "message                : " << userWord << endl;
                cout << "repeated keyword       : " << userKeyWord << endl;
                cout << "decrypted word message : ";
                decrypt(userWord, userKeyWord);


                cout << "\n________________________________________________________" << endl;
            }


}
