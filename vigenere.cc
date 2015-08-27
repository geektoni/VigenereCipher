using namespace std;
#include <iostream>
#include <fstream>

static int DIM = 26;
static int LINE = 100;
char tabulaRecta[DIM][DIM];

static int getNumber(char c) {
  char tmp = tolower(c);
  int pos = 'a'- tmp;
  return tmp;
} 

char * cryptLine(const char line[], const char key[]) {
  int i=0, y=0;
  char * tmp = new char[LINE];
  while(line[i] != '\0') {
    tmp[i] = tabulaRecta[getNumber(line[i])][getNumber(key[y])];
    if (y == strlen(key)-1) {
      y=0;
    } else {
      y++;
    }
    i++;
  }
  return tmp;
}


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

void cryptTest(char inFile[], char outFile[], char key[]) {
  fstream in, out;
  char tmp[LINE];
  char * crypted;
  char c;
  int i=0;
  in.open(inFile, ios::in);
  out.open(outFile, ios::out);
  while(!in.eof()) {
    in >> c;
    if (c == '\n') {
      crypted = cryptLine(tmp, key);
      out << crypted << '\n';
      delete crypted;
      crypted = null;
    } else {
      tmp[i] = c;
      c++;
    }
  }
  in.close();
  out.close();
}
