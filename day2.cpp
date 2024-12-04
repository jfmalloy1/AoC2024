#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <sstream>

using namespace std;

int main() {
    // Read in file
    ifstream file("Data/day2.txt");
    string str;

    // Counter for all successes
    int success_counter = 0;
    
    
    while (getline(file, str)) {
        // Individual check for success
        bool success = true;
        cout << str << endl;
        stringstream ss(str);
        string s;
        // Previous number (set to 0 by default)
        int prev = 0;
        bool increase = true;
        
        while (getline(ss, s, ' ')) {
            int n = stoi(s);

            // Set up first number
            if (prev == 0) {
                prev = n;
            }
            else {
                if (n < prev) {
                    increase = false;
                }

            }
            
        }
        cout << "Increase? " << increase << endl;
        }


    return 0;
}