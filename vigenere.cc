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

char * cryptLine(const char line[], const char key[]) {
  int i=0, y=0,k=0, dim=strlen(key);
  char * tmp = new char[LINE];
  while(i < strlen(line)) {
    if (line[i] != ' ') {
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

void printTabula() {
  for (int i=0; i<26; i++) {
    for (int j=0; j<26; j++) {
      cout << tabulaRecta[i][j]<< " ";
    }
    cout << endl;
  }
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
    out << crypted << endl;
    delete crypted;
    delete tmp;
    crypted = NULL;
    tmp = NULL;
  }
  in.close();
  out.close();
}

