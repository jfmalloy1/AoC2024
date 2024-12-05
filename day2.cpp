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
        int prev = -1;
        int count = 0;
        bool increase = true;
        
        while (getline(ss, s, ' ')) {
            int n = stoi(s);

            // Set up first number
            if (prev == -1) {
                prev = n;
                ++count;
            }
            else {
                cout << "Comparing: " << prev << " to " << n << endl;
                if (n < prev && count == 1) {
                    increase = false;
                }
                if (increase) {
                    if (n < prev) {
                        success = false;
                        cout << "Failed due to increase, n < prev" << endl;
                        break;
                    }
                    else if (n - prev > 3) {
                        success = false;
                        cout << "Failed due to increase, n-prev>3" << endl;
                        break;
                    }
                    else if (prev == n) {
                        success = false;
                        cout << "Failed due to equality, n==prev" << endl;
                        break;
                    }
                }
                else {
                    if (n > prev)
                    {
                        success = false;
                        cout << "Failed due to decrease, n > prev" << endl;
                        break;
                    }
                    else if (prev - n > 3)
                    {
                        success = false;
                        cout << "Failed due to decrase, prev-n>3" << endl;
                        break;
                    }
                    else if (prev == n)
                    {
                        success = false;
                        cout << "Failed due to equality, n==prev" << endl;
                        break;
                    }
                }
                ++count;
            }
            prev = n;


            
        }
        cout << "Increase? " << increase << endl;
        cout << "Success? " << success << endl;
        if (success) {
            ++success_counter;
        }
    }
    cout << "Total Successes: " << success_counter << endl;


    return 0;
}