#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class AnagramChecker {
public:

    bool areAnagrams(const string& str1, const string& str2) {

        if (str1.length() != str2.length()) {
            return false;
        }


        unordered_map<char, int> charCount;

        for (char ch : str1) {
            charCount[ch]++;
        }


        for (char ch : str2) {
            charCount[ch]--;

            if (charCount[ch] < 0) {
                return false;
            }
        }

        return true;
    }


    void displayCharCounts(const string& str) {
        unordered_map<char, int> charCount;


        for (char ch : str) {
            charCount[ch]++;
        }

        cout << "Character counts in \"" << str << "\":\n";
        for (const auto& pair : charCount) {
            cout << pair.first << ": " << pair.second << "\n";
        }
    }
};

int main() {
    AnagramChecker anagramChecker;
    string str1, str2;

    cout << "Enter the first string: ";
    getline(cin, str1);
    cout << "Enter the second string: ";
    getline(cin, str2);

    if (anagramChecker.areAnagrams(str1, str2)) {
        cout << "The strings are anagrams.\n";
    } else {
        cout << "The strings are not anagrams.\n";
    }


    anagramChecker.displayCharCounts(str1);
    anagramChecker.displayCharCounts(str2);

    return 0;
}
