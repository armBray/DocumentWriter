#include <iostream>
#include <string>

using namespace std;

#include "Document.h"

int main() {
  txtDocument mytext;
  mytext.Open("provatxt");
  mytext.Write({"ciao", "sono", "io"});
  mytext.Close();

  csvDocument myspread;
  myspread.Open("provacsv");
  myspread.Write({"COLORE", "OGGETTO"});
  myspread.Write({"bianco", "muro"});
  myspread.Write({"blue", "mare"});
  myspread.Close();

  htmlDocument myhtml;
  myhtml.Open("provahtml");
  myhtml.Write({"ciao", "sono", "io"});
  myhtml.Close();

  return 0;
}

// g++ -o <name-you-want-to-give> source.cpp
//./myprogram