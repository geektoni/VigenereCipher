using namespace std;
#include <iostream>
#include <fstream>
#include <cstring>
#include "vigenere.h"

const int DIM = 26;
const int LINE = 100;
char tabulaRecta[DIM][DIM];

static int getNumber(char c) {
  char tmp = tolower(c);
  int pos = tmp-'a';
  return pos;
}

static int getDecNumber(char array[][DIM], char c, int y) {
  int i =0;
  while(i < 26 && array[i][y] != c) {
    i++;
  }
  return i;
}  

char * cryptLine(const char line[], const char key[]) {
  int i=0, y=0,k=0, dim=strlen(key);
  char * tmp = new char[LINE];
  while(i < strlen(line)) {
    if (line[i] != ' ' && (line[i] >= 'a' || line[i] <= 'z')) {
      tmp[k] = tabulaRecta[getNumber(line[i])][getNumber(key[y])];
      if (y == dim-1) {
        y=0;
      } else {
        y++;
      }
      k++;
    }
  i++;
  }
  return tmp;
}

char * decryptLine(const char line[], const char key[]) {
  int i=0, y=0,k=0, dim=strlen(key);
  char * tmp = new char[LINE];
  while(i < strlen(line)) {
    if (line[i] != ' ' && (line[i] >= 'a' || line[i] <= 'z')) {
      int index = getDecNumber(tabulaRecta, line[i], getNumber(key[y]));
      tmp[k] = tabulaRecta[index][0];
      if (y == dim-1) {
        y=0;
      } else {
        y++;
      }
      k++;
    }
  i++;
  }
  return tmp;
}

void generateTabula(char tabula[] ) {
  fstream in;
  char tmp;
  int x=0, y=0;
  in.open(tabula, ios::in);
  while(!in.eof()) {
    in >> tmp;
    if (x==25) {
      y++;
      x=0;
    } else {
      tabulaRecta[x][y] = tmp;
      x++;
    }
  }
  in.close();
}

void cryptText(char inFile[], char outFile[], char key[]) {
  fstream in, out;
  char * tmp;
  char * crypted;
  int i=0;
  in.open(inFile, ios::in);
  out.open(outFile, ios::out);
  while(!in.eof()) {
    tmp = new char[LINE];
    in.getline(tmp, LINE);
    crypted = cryptLine(tmp, key);
    cout << crypted << endl;
    out << crypted << endl;
    delete crypted;
    delete tmp;
    crypted = NULL;
    tmp = NULL;
  }
  in.close();
  out.close();
}

void decryptText(char inFile[], char outFile[], char key[]) {
  fstream in, out;
  char * tmp;
  char * decrypted;
  int i=0;
  in.open(inFile, ios::in);
  out.open(outFile, ios::out);
  while(!in.eof()) {
    tmp = new char[LINE];
    in.getline(tmp, LINE);
    decrypted = decryptLine(tmp, key);
    cout << decrypted << endl;
    out << decrypted << endl;
    delete decrypted;
    delete tmp;
    decrypted = NULL;
    tmp = NULL;
  }
  in.close();
  out.close();
}


