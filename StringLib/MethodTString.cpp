constexpr auto BUFF = 256;
#include "ClassTString.h"

TString::TString()
{
  str = new char[1] {'\0'};
  len = 1;
}

TString::TString(const char* str_)
{
  if ((str_ == nullptr))
    throw "str_ == nullptr";
  {
    len = cstrlen(str_);
    str = new char[len + 1];

    for (int i = 0; i < len; ++i)
      str[i] = str_[i];

    str[len] = '\0';
  }
}

TString::TString(const TString& obj)
{
  len = obj.len;

  if (obj.str != nullptr)
  {
    str = new char[len];
    for (int i = 0; i < len; ++i)
      str[i] = obj.str[i];
  }
  else
    throw ("p.str == nullptr");

  str = new char[ len + 1];
  for (int i = 0; i < len; ++i)

    str[i] = obj.str[i];

  str[len] = '\0';
}


TString::TString(TString&& obj) noexcept
{
  len = obj.len;
  str = obj.str;

  obj.str = nullptr;
  obj.len = 0;
}


TString::TString(const char* str_, int len_)
{
  if (len_ <= 0)
    throw ("len_ <= 0");
  if (cstrlen(str_) != len_)
    throw ("strlen(str_) != len_");

  len = len_;
  str = new char[len + 1];

  for (int i = 0; i < len; ++i)
    str[i] = str_[i];

  str[len] = '\0';
}


TString::~TString()
{
  if (str != nullptr) delete[]str;
}


char* TString::GetStr()
{
  if (str != nullptr) return str;
  else return nullptr;
}


int TString::GetLen() const
{
  return len;
}


void TString::SetStr(const char* str_)
{
  delete[] str;
  len = cstrlen(str_);
  str = new char[len + 1];
  for (int i = 0; i < len; ++i)
    str[i] = str_[i];

  str[len] = '\0';
}


void TString::SetLen(int len_)
{
  if (len_ <= 0)
    throw "len_ <= 0";
  if (len == len_)
    return;

  //if (len < len_)
  //  throw "len_ <= 0";

  len = len_;
  char* str_ = this->GetStr();
  str = new char[len + 1];

  for (int i = 0; i < len; ++i)
    str[i] = str_[i];

  str[len] = '\0';
}


TString TString::operator+(const TString& obj)
{
  char* nstr = new char[len + obj.len + 1];

  for (int i = 0; i < len; ++i)
    nstr[i] = str[i];
  for (int i = 0; i < obj.len; ++i)
    nstr[i + len] = obj.str[i];

  nstr[len + obj.len] = '\0';

  return TString(nstr);
}


TString TString::operator*(int rep)
{
  if (rep < 0)
    throw "rep <= 0";

  char* buf = new char[len * rep + 1];

  for (int i = 0; i < rep; ++i)
  {
    for (int j = 0; j < len; ++j)
      buf[len * i + j] = str[j];
  }

  buf[len * rep] = '\0';

  return TString(buf);
}


TString TString::operator=(const TString& line)
{
  len = line.len;
  str = new char[len + 1];

  for (int i = 0; i < len; ++i)
    str[i] = line.str[i];

  str[len] = '\0';

  return *this;
}


bool TString::operator==(const TString& line)
{
  if (len != line.len)
    return false;

  bool f = true;

  for (int i = 0; i < len; ++i)
  {
    if (str[i] != line.str[i])
      f = false;
  }

  return f;
}


bool TString::operator!=(const TString& line)
{
  if (len != line.len)
    return true;

  bool f = false;

  for (int i = 0; i < len; ++i)
  {
    if (str[i] != line.str[i])
      f = true;
  }

  return f;
}


bool TString::operator<(const TString& line)
{
  return len < line.len;
}


bool TString::operator>(const TString& line)
{
  return len > line.len;
}


char TString::operator[](int p)
{
  if (p >= len && p < 0)
    throw "size";
  return str[p];
}


ostream& operator<<(ostream& output, TString& line)
{
  output << "Length of string: " << line.len << "\n" << "String: " << line.str << "\n";
  return output;
}


istream& operator>>(istream& input, TString& line)
{
  char buf[BUFF];
  cout << "Enter a string: ";
  input >> buf;
  line.SetStr(buf);

  return input;
}

int cstrlen(const char* str)
{
  int counter = 0;
  if (str == nullptr)
    throw "str == nullptr";
  while (str[counter] != '\0')
    counter++;
  return counter;
}