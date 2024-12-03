#include <fstream>
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

bool checkSafe(int current, int last ,int directionFlag) {
    // int directionFlag = -1;


    int diff = current - last;
    cout << last << " " << current << endl;
    cout << diff << endl;

    // increasing
    if(diff > 0) {
        if (!directionFlag) {
           return false;
        }
        if (diff > 3) {

            return false;
        }
    }
    // decreasing
    if(diff < 0) {
        if (directionFlag) {
            return false;
        }

        if (diff < -3) {
            return false;
        }
    }
    // no diff
    if(diff == 0) {
        return false;
    }
    return true;
}

int main(int argc, char *argv[]) {
    string filename = "day2_data.txt";

    ifstream file(filename);

    string line;
    int level;

    int safe_reports = 0;
    while (getline(file, line)) {
        cout << line << endl;

        vector<int> levels;

        int directionFlag = -1;
        int bad_levels = 0;
        safe_reports++;
        stringstream ss(line);
        while(ss >> level) {
            // Begin report
            if(levels.size() < 2) {
                // cout << "START" << endl;
                levels.push_back(level);
                continue;
            }

            // Set decreasing/increasing flag based on first 2 nums
            if(*(--levels.end()) > level && directionFlag == -1) {
                directionFlag = 0;
            } else if(*(--levels.end()) < level && directionFlag == -1) {
                directionFlag = 1;
            }

            if(!checkSafe(level, *(--levels.end()), directionFlag)) {
                bad_levels++;

                // Only one level can be bad
                if (bad_levels > 1) {
                    cout << "UNSAFE" << endl;
                    safe_reports--;
                    break;
                }

                // If EOL is bad level then it's OK
                if(ss.eof()) {
                    break;
                }

                // // If begining, handle out of bouds
                // if(levels.size() == 1) {
                //     cout << "INC" << endl;
                //     continue;
                // }

                // Check
                if(!checkSafe(level, *(levels.end() - 2), directionFlag)) {
                    cout << "UNSAFE" << endl;
                    safe_reports--;
                    break;
                }
            }
            levels.push_back(level);
        }
    }
    file.close();

    cout << "safe reports:" << safe_reports << endl;

    return 0;
}
