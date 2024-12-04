#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
    // Read in file
    ifstream file("Data/day1p1.txt");
    string s1, s2;
    string str;
    vector<int> col1;
    vector<int> col2;
    vector<int> diffs;
    
    // Separate columns into lists of integers
    while (getline(file, str)){
        stringstream s(str);
        s >> s1 >> s2;
        col1.push_back(stoi(s1));
        col2.push_back(stoi(s2));
    }

    // Sort columns
    sort(col1.begin(), col1.end());
    sort(col2.begin(), col2.end());

    // Calculate differences on sorted lists & sum them up
    int diff_sum = 0;
    for (int i = 0; i < col1.size(); ++i) {
        diff_sum+=abs(col1[i] - col2[i]);
    }

    cout << "Sum of Diffs: " << diff_sum << endl;
    return 0;
}