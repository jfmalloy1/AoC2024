#include <iostream>
#include <regex>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

int main() {
    // Read in file
    ifstream file("Data/day3.txt");

    // Set up regex
    regex pattern("mul\\([0-9]*,[0-9]*\\)");

    string str;
    string mult;
    int offset = 4;
    int total = 0;
    int mult_total;
    while (getline(file, str)) {
        // Adding a -1 at the end will get everything BUT the regex pattern
        sregex_token_iterator iter(str.begin(), str.end(), pattern);
        sregex_token_iterator end;

        // Put iterator into a list of strings
        vector<string> to_vector;
        for (; iter != end; ++iter) {
            to_vector.push_back(*iter);
        }

        for (string match : to_vector) {
            
            cout << match << " " << match.length() << endl;
            mult = match.substr(offset, match.length() - offset - 1);
            cout << mult << endl;
            stringstream ss(mult);
            vector<int> l;
            string s;
            while (getline(ss, s, ','))
            {
                l.push_back(stoi(s));
            }
            cout << "Multiplying: ";
            mult_total = 1;
            for (int n : l) {
                cout << n << " , ";
                mult_total = mult_total * n;
            }
            // mult_total = mult_total * 10;
            cout << " = " << mult_total << endl;
            total = total + mult_total;
        }
        
        
    }
    cout << "Total: " << total << endl;

    return 0;
}