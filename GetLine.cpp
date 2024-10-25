#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

int main() {
  // Case 1
    string input = "\"Hello\", \"Are\", \"You\"";
    vector<string> words;
    stringstream ss(input);
    string temp;

    while (getline(ss, temp, ',')) {
        // Remove leading/trailing spaces and quotes
        temp.erase(0, temp.find_first_not_of(" \""));  // Left trim
        temp.erase(temp.find_last_not_of(" \"") + 1);   // Right trim
        words.push_back(temp);
    }

    for (const string& word : words) {
        cout << word << " ";
    }

  
  // Case 2
    string input = "1, 2, 3, 4, 8";
    vector<int> values;
    stringstream ss(input);
    string temp;

    while (getline(ss, temp, ',')) {
        values.push_back(stoi(temp));  // Convert to integer and add to vector
    }

    // Display the vector
    for (int val : values) {
        cout << val << " ";
    }
  

  // Case 3
   string input = "Hello, Are, You";
    vector<string> words;
    stringstream ss(input);
    string temp;

    while (getline(ss, temp, ',')) {
        temp.erase(0, temp.find_first_not_of(" "));   // Left trim
        temp.erase(temp.find_last_not_of(" ") + 1);   // Right trim
        words.push_back(temp);
    }

    // Display the vector
    for (const string& word : words) {
        cout << word << " ";
    }

    return 0;
}
