#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool isXmas(char x, char m, char a, char s) {
    if (x == 'X' && m == 'M' && a == 'A' && s == 'S') {
        cout << x << m << a << s <<endl;
        return true;
    } else {
        return false;
    }
}

int main(int argc, char *argv[]) {
    string filename = "data.txt";

    ifstream file(filename);
    char ch;
    string line;
    vector<vector<char> > grid;

    while (getline(file, line)) {
        vector<char> row;

        for (char c : line) {
            // cout << c << endl;

            row.push_back(c);
        }
        grid.push_back(row);
    }
    file.close();

    int count = 0;

    for (int i = 0; i < grid.size(); ++i) {
        for (int j = 0; j < grid[i].size(); ++j) {
            char ch = grid[i][j];

            if (ch == 'X') {
                // left to right
                if ((j + 3) < grid[i].size() &&
                    isXmas(grid[i][j],
                           grid[i][j + 1],
                           grid[i][j + 2],
                           grid[i][j + 3])) {
                    count++;
                }
                // right to left
                if ((j - 3) >= 0 &&
                    isXmas(grid[i][j],
                           grid[i][j - 1],
                           grid[i][j - 2],
                           grid[i][j - 3])) {
                    count++;
                }
                // down to up
                if ((i - 3) >= 0 &&
                    isXmas(grid[i][j],
                           grid[i - 1][j],
                           grid[i - 2][j],
                           grid[i - 3][j])) {
                    count++;
                }
                // up to down
                if ((i + 3) < grid.size() &&
                    isXmas(grid[i][j],
                           grid[i + 1][j],
                           grid[i + 2][j],
                           grid[i + 3][j])) {
                    count++;
                }

                // upleft to downright
                if ((i + 3) < grid.size() && (j - 3) >= 0 &&
                    isXmas(grid[i][j],
                           grid[i + 1][j - 1],
                           grid[i + 2][j - 2],
                           grid[i + 3][j - 3])) {
                    count++;
                }
                // upleft
                if ((i - 3) >= 0 && (j - 3) >= 0 &&
                    isXmas(grid[i][j],
                           grid[i - 1][j - 1],
                           grid[i - 2][j - 2],
                           grid[i - 3][j - 3])) {
                    count++;

                }

                // upright
                if ((i - 3) >= 0 && (j + 3) < grid[i].size() &&
                    isXmas(grid[i][j],
                           grid[i - 1][j + 1],
                           grid[i - 2][j + 2],
                           grid[i - 3][j + 3])) {
                    cout << i << endl;

                    count++;
                }
                // downright
                if ((i + 3) < grid.size() && (j + 3) < grid[i].size() &&
                    isXmas(grid[i][j],
                           grid[i + 1][j + 1],
                           grid[i + 2][j + 2],
                           grid[i + 3][j + 3])) {
                    count++;
                }
            }
        }
    }

    cout << endl << count << endl;

    return 0;
}
