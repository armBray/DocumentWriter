#ifndef _DOCUMENT_H
#define _DOCUMENT_H

#include <fstream>
#include <string>
#include <vector>
using namespace std;

class InterfaceDocument // abstract class
{
public:
  virtual void Open(string filename) = 0;      // pure virtual function
  virtual void Close() = 0;                    // pure virtual function
  virtual void Write(vector<string> text) = 0; // pure virtual function

protected:
  ofstream f_out;
};

class txtDocument : public InterfaceDocument {
public:
  virtual void Open(string filename) { f_out.open(filename + ".txt"); }
  virtual void Close() { f_out.close(); }
  virtual void Write(vector<string> text) {
    for (auto &txt : text) {
      f_out << txt << " "; // add space btw words
    }
  }
};

class csvDocument : public InterfaceDocument {
public:
  virtual void Open(string filename) { f_out.open(filename + ".csv"); }
  virtual void Close() { f_out.close(); }
  virtual void Write(vector<string> text) {
    for (auto &txt : text) {
      f_out << txt << ","; // add comma btw words
    }
    f_out << endl;
  }
};

class htmlDocument : public InterfaceDocument {
public:
  virtual void Open(string filename) {
    f_out.open(filename + ".html");
    f_out << "<head><title>My Page</head></title>" << endl;
    f_out << "<body>" << endl;
  }
  virtual void Close() {
    f_out << "</body>" << endl;
    f_out.close();
  }
  virtual void Write(vector<string> text) {
    f_out << "<p>";
    for (auto &txt : text) {
      f_out << txt << " "; // add comma btw words
    }
    f_out << "</p>";
  }
};

#endif