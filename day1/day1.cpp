#include <fstream>
#include <iostream>
#include <string>

using namespace std;
int main(int argc, char *argvp[]) {
  string filename = "day1_data.txt";
  // string filename = "day1_test.txt";

  ifstream file(filename);

  string line;
  vector<int> list_1;
  vector<int> list_2;

  while (getline(file, line)) {
    cout << line << endl;

    // list_1.push_back(stoi(line.substr(0, 1)));
    // list_2.push_back(stoi(line.substr(4, 1)));

    list_1.push_back(stoi(line.substr(0,5)));
    list_2.push_back(stoi(line.substr(8,5)));
  }
  file.close();

  cout << endl;
  sort(list_1.begin(), list_1.end());
  sort(list_2.begin(), list_2.end());

  int dist = 0;
  for (int i = 0; i < list_1.size(); i++) {
    cout << list_1[i] << "   " << list_2[i] << endl;

    int num = 0;
    num = list_1[i] - list_2[i];

    if (num < 0) {
      num = num * -1;
    }

    dist += num;
  }

  cout << "DIST: " << dist << endl;

  vector<int>::iterator it1 = list_1.begin();
  vector<int>::iterator it2 = list_2.begin();

  int similarity = 0;
  while (it1 != list_1.end()) {
    int count = 0;

    while(*it1 == *(it2 + count)) {
        count++;
    }

    similarity += *it1 * count;

    if(*it1 <= *it2) {
        it1++;
    } else {
        it2++;
        if(it2 > list_2.end()) {
            cout << "Similarity: " << similarity << endl;
            return 1;
        }
    }

    if(*it1 != *it2 && it2 < list_2.end()) {
        it2 += count;
    }

  }

  cout << "Similarity: " << similarity << endl;
  return 0;
}
