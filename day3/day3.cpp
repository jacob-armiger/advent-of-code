#include <fstream>
#include <iostream>
#include <iterator>
#include <regex>
#include <string>
using namespace std;

int main(int argc, char *argv[]) {
  string filename = "data.txt";

  ifstream file(filename);
  string line;
  string text;

  while (getline(file, line)) {
    cout << line << endl;
    text += line;
  }
  file.close();

  regex pattern("mul\\(\\d+,\\d+\\)|do\\(\\)|don't\\(\\)");
  auto begin = sregex_iterator(text.begin(), text.end(), pattern);
  auto end = sregex_iterator();

  int sum = 0;
  bool mult = true;
  for (sregex_iterator i = begin; i != end; ++i) {
    smatch match = *i;
    string str = match.str();
    cout << str << endl;

    if (str == "do()") {
      mult = true;
      continue;
    }

    if (str == "don't()") {
      mult = false;
      continue;
    }

    if (mult == true) {
      string substr = str.substr(4, 7);

      string num1 = substr.substr(0, substr.find(","));
      string num2 =
          substr.substr(substr.find(",") + 1, substr.size() - num1.size() + 1);

      int prod = stoi(num1) * stoi(num2);
      sum += prod;
    }
  }
  cout << sum << "\n";
  return 0;
}
