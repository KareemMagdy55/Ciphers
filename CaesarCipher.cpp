// Caesar Cipher
// Date    : 14 Mar. 2022
// Author  : Kareem Magdy
// Version : 1.0


#include <iostream>

using namespace std ;

void caesarCipher(string userWord, int opt);

int main() {


    return 0;
}

const char alphabets[26] = {'A', 'B', 'C', 'D', 'E', 'F',
                            'G', 'H', 'I', 'J', 'K', 'L',
                            'M', 'N', 'O', 'P', 'Q', 'R',
                            'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

const int numberOfAlphabets = sizeof(alphabets)/sizeof(alphabets[0]);


int shiftInfo(int shiftValue) {

    if (abs(shiftValue) < numberOfAlphabets ){

        if (shiftValue < 0){

            return  numberOfAlphabets - abs(shiftValue) ;
        }
        else if (shiftValue > 0){

            return shiftValue ;
        } else{
            return 0 ;
        }
    }else{
        shiftInfo(shiftValue % numberOfAlphabets );
    }
}

void encrypt(int shiftValue = 0, string word = ""){

    string codedWord ;

    for(char& c : word ) {
        for (int i = 0; i < numberOfAlphabets; i++) {
            if (i + shiftValue < numberOfAlphabets ) {

                if (toupper(c) == alphabets[i]) {
                    codedWord += alphabets[i + shiftValue];

                }

            } else {
                if (toupper(c) == alphabets[i]) {
                    codedWord += alphabets[i - (numberOfAlphabets - shiftValue)];

                }

            }
        }
    }
    cout << "_____________ Encryption ____________" << endl ;
    cout  << "Plain  : " << word << endl ;
    cout  << "Cipher : " << codedWord << endl ;
    cout << "_____________________________________" << endl ;
}

void decrypt(int shiftValue = 0, string word = ""){

    string decodedWord ;

    for(char& c : word ) {
        for (int i = 0; i < numberOfAlphabets; i++) {
            if (i - shiftValue < numberOfAlphabets && i - shiftValue >= 0 ) {

                if (toupper(c) == alphabets[i]) {
                    decodedWord += alphabets[i - shiftValue];

                }

            } else {
                if (toupper(c) == alphabets[i]) {
                    decodedWord += alphabets[ numberOfAlphabets - ( shiftValue - i ) ];

                }
            }
        }
    }
    cout << "_____________ Decryption __________" << endl ;
    cout  << "Plain  : " << word << endl ;
    cout  << "Cipher : " << decodedWord << endl ;
    cout << "___________________________________" << endl ;
}

void caesarCipher(string userWord, int opt) {


    int shiftValue = 0;



        if (opt == 1) {

            cout << "Please enter the shift value :";
            cin >> shiftValue;
            encrypt(shiftInfo(shiftValue), userWord);
        } else if (opt == 2) {

            cout << "Please enter the shift value :";
            cin >> shiftValue;
            decrypt(shiftInfo(shiftValue), userWord);
        }
    }

