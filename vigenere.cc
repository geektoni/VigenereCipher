using namespace std;
#include <iostream>
#include <fstream>

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
