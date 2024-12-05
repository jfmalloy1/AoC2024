#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

vector<int> checkStr(const std::vector<int> &l)
{
    stringstream ss;
    int prev = -1;
    bool increase = true;
    // Returns two numbers - success code (1 if success, 0 otherwise), and error position (0, 1, 2, etc...)
    int count = 0;
    bool success = true;
    for (int n: l) {
        // Set up first number
        if (prev == -1)
        {
            prev = n;
            ++count;
        }
        else
        {
            cout << "Comparing: " << prev << " to " << n << endl;
            if (n < prev && count == 1)
            {
                increase = false;
            }
            if (increase)
            {
                if (n < prev)
                {
                    success = false;
                    cout << "Failed due to increase, n < prev" << endl;
                    break;
                }
                else if (n - prev > 3)
                {
                    success = false;
                    cout << "Failed due to increase, n-prev>3" << endl;
                    break;
                }
                else if (prev == n)
                {
                    success = false;
                    cout << "Failed due to equality, n==prev" << endl;
                    break;
                }
            }
            else
            {
                if (n > prev)
                {
                    success = false;
                    cout << "Failed due to decrease, n > prev" << endl;
                    break;
                }
                else if (prev - n > 3)
                {
                    success = false;
                    cout << "Failed due to decrease, prev-n>3" << endl;
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
    vector<int> values;
    // Return 1, -1 for success
    if (success) {
        values.push_back(1);
        values.push_back(-1);
    } else {
        // Return 0 and the offending position for failures
        values.push_back(0);
        values.push_back(count);
    }
    return values;
}

int main() {
    // Read in file
    ifstream file("Data/day2.txt");
    string str;

    // Counter for all successes
    int success_counter = 0;


    while (getline(file, str))
    {
        cout << str << endl;

        // Individual check for success
        bool success = true;
        // Stringstream to hold separated line
        stringstream ss(str);
        // List to hold ints
        vector<int> l;
        // Individual strings holding ints
        string s;
        int tolerance = 0;
        int tolerance_limit = 2;

        while(getline(ss, s, ' ')) {
            l.push_back(stoi(s));
        }

        vector<int> status = checkStr(l);
        cout << status[0] << " " << status[1] << endl;
        // If status == 1, it was successful and therefore breaks out of loop
        if (status[0])
        {
            ++success_counter;
        }
        // Otherwise, try i, i-1, i-2 and see if any of those fail - if not, add to success
        else {
            vector<int> l_copy;
            copy(l.begin(), l.end(), back_inserter(l_copy));

            // Take away i (initial failure point)
            l_copy.erase(l_copy.begin() + status[1]);
            vector<int> status_v1 = checkStr(l_copy);

            // Take away i-1, if possible
            copy(l.begin(), l.end(), back_inserter(l_copy));
            l_copy.erase(l_copy.begin() + status[1]-1);
            vector<int> status_v2 = checkStr(l_copy);

            // Take away -2, if possible
            vector<int> status_v3;
            if (status[1] - 2 >= 0)
            {
                copy(l.begin(), l.end(), back_inserter(l_copy));
                l_copy.erase(l_copy.begin() + status[1] - 2);
                status_v3 = checkStr(l_copy);
            }

            if (status_v1[0] && status_v2[0] && status_v3[0]) {
                ++success_counter;
            }
            
        }
        

    }
    cout << "Total Successes: " << success_counter << endl;


    return 0;
}