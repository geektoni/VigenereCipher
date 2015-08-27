using namespace std;
#include <iostream>
#include <fstream>
#include <cstring>

static int DIM = 26;
static int LINE = 100;
char tabulaRecta[DIM][DIM];

void generateMatrix(char tabula[] ) {
  fstream in;
  char tmp;
  int x=0, y=0;
  in.open(tabula, ios::in);
  while(!in.eof()) {
    in >> tmp;
    if (tmp == '\n') {
      y++;
    } else {
      tabulaRecta[x][y] = tmp;
      x++;
    }
  }
  in.close();
}

void cryptTest(char in[], char out[], char key[]) {
  fstream in, out;
  char tmp[LINE];
  char * crypted;
  char c;
  int i=0;
  in.open(in, ios::in);
  out.open(out, ios:out);
  while(!in.eof()) {
    in >> c;
    if (c == '\n') {
      tmp[i] = '\0';
      crypted = cryptLine(tmp, key);
      out << crypted << '\n';
      delete crypted;
      crypted = null;
    } else {
      tmp[i] = c;
      i++;
    }
  }
  in.close();
  out.close();
}

static char * cryptLine(static char line[], static char key[]) {
  int i=0, y=0;
  char * tmp = new char[LINE];
  while(line[i] != '\0') {
    tmp[i] = tabulaRecta[getNumber(line[i])][getNumber(key[y])];
    if (y == key.length()-1) {
      y=0;
    } else {
      y++;
    }
    i++;
  }
  return tmp;
}

static int getNumber(char c) {
  char tmp = tolower(c);
  int pos = 'a'- tmp;
  return tmp;
} 
