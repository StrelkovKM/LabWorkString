#pragma once

#include <iostream>
using namespace std;

class TString
{
protected:
  char* str;
  int len;
public:
  TString(); ///+
  TString(const TString& obj); ///+
  TString(TString&& obj) noexcept; ///??????????
  TString(const char* str_, int len_); ///+
  TString(const char* str_); ///+
  ~TString(); ///+

  char* GetStr(); ///+
  int GetLen() const; ///+

  void SetStr(const char* str_); ///+?
  void SetLen(int len_); ///+

  TString operator+(const TString& obj); ///+
  TString operator*(int count); ///+
  TString operator=(const TString& obj); ///+
 
  bool operator==(const TString& obj); ///+
  bool operator!=(const TString& obj); ///+
  bool operator<(const TString& obj); ///+
  bool operator>(const TString& obj); ///+

  char operator[](int sym); ///+


  friend ostream& operator<<(ostream& output, TString& obj); ///+
  friend istream& operator>>(istream& input, TString& obj); ///+
};

int cstrlen(const char* str);