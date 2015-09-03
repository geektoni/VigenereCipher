using namespace std;
#include <iostream>
#include <fstream>
#include <cstring>
#include "vigenere.h"

const int DIM = 26;
const int LINE = 100;
char tabulaRecta[DIM][DIM] = {
'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z',
'B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','A',
'C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','A','B',
'D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','A','B','C',
'E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','A','B','C','D',
'F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','A','B','C','D','E',
'G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','A','B','C','D','E','F',
'H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','A','B','C','D','E','F','G',
'I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','A','B','C','D','E','F','G','H',
'J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','A','B','C','D','E','F','G','H','I',
'K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','A','B','C','D','E','F','G','H','I','J',
'L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','A','B','C','D','E','F','G','H','I','J','K',
'M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','A','B','C','D','E','F','G','H','I','J','K','L',
'N','O','P','Q','R','S','T','U','V','W','X','Y','Z','A','B','C','D','E','F','G','H','I','J','K','L','M',
'O','P','Q','R','S','T','U','V','W','X','Y','Z','A','B','C','D','E','F','G','H','I','J','K','L','M','N',
'P','Q','R','S','T','U','V','W','X','Y','Z','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O',
'Q','R','S','T','U','V','W','X','Y','Z','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P',
'R','S','T','U','V','W','X','Y','Z','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q',
'S','T','U','V','W','X','Y','Z','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R',
'T','U','V','W','X','Y','Z','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S',
'U','V','W','X','Y','Z','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T',
'V','W','X','Y','Z','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U',
'W','X','Y','Z','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V',
'X','Y','Z','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W',
'Y','Z','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X',
'Z','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y'
};

/* Get the given letter position inside alphabet */
static int getNumber(char c) {
  char tmp = tolower(c);
  int pos = tmp-'a';
  return pos;
}

/* Get the given letter position inside a line on the tabula */
static int getDecNumber(char array[][DIM], char c, int y) {
  int i=0;
  bool status = true;
  while(i < 26 && status) {
    if (array[i][y] == c) {
      status = false;
    } else {
      i++;
    }
  }
  return i;
}  

/* Crypt one line of text with the given key*/
char * cryptLine(const char line[], const char key[]) {
  unsigned int i=0, y=0,k=0, dim=strlen(key);
  char * tmp = new char[LINE];
  while(i < strlen(line)) {
    if (line[i] != ' ') {
      if (line[i] >= 'a' && line[i] <= 'z') {
        tmp[k] = tabulaRecta[getNumber(line[i])][getNumber(key[y])];
        if (y == dim-1) {
          y=0; 
        } else {
          y++;
        }
      } else {
        tmp[k] = line[i];
      }
      k++;
    }
  i++;
  }
  return tmp;
}

/* Decrypt one line of text, given the key */
char * decryptLine(const char line[], const char key[]) {
  unsigned int i=0, y=0,k=0, dim=strlen(key);
  char * tmp = new char[LINE];
  while(i < strlen(line)) {
    if (line[i] != ' ') {
      if (line[i] >= 'A' && line[i] <= 'Z') {
        int index = getDecNumber(tabulaRecta, line[i], getNumber(key[y]));
        tmp[k] = tabulaRecta[index][0];
        if (y == dim-1) {
          y=0;
        } else {
          y++;
        }
      } else {
        tmp[k] = line[i];
      }
      k++;
    }
  i++;
  }
  return tmp;
}

/* Crypt an entire text and put it inside an output file */
void cryptText(char inFile[], char outFile[], char key[]) {
  fstream in, out;
  char * tmp;
  char * crypted;
  in.open(inFile, ios::in);
  out.open(outFile, ios::out);
  while(!in.eof()) {
    tmp = new char[LINE];
    in.getline(tmp, LINE);
    crypted = cryptLine(tmp, key);
    out << crypted << endl;
    delete crypted;
    delete tmp;
    crypted = NULL;
    tmp = NULL;
  }
  in.close();
  out.close();
}

/* Decrypt a text and put it inside and out file */
void decryptText(char inFile[], char outFile[], char key[]) {
  fstream in, out;
  char * tmp;
  char * decrypted;
  in.open(inFile, ios::in);
  out.open(outFile, ios::out);
  while(!in.eof()) {
    tmp = new char[LINE];
    in.getline(tmp, LINE);
    decrypted = decryptLine(tmp, key);
    out << decrypted << endl;
    delete decrypted;
    delete tmp;
    decrypted = NULL;
    tmp = NULL;
  }
  in.close();
  out.close();
}


