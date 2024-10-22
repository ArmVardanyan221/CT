#include <iostream>
#include <string>

using namespace std;

struct CharCountNode {
    char character;
    int count;
    CharCountNode* next;

    CharCountNode(char ch) : character(ch), count(1), next(nullptr) {}
};

class AnagramChecker {
public:
    bool areAnagrams(const string& str1, const string& str2) {
        if (str1.length() != str2.length()) {
            return false;
        }

        CharCountNode* head1 = buildCharCountList(str1);
        CharCountNode* head2 = buildCharCountList(str2);

        return compareCharCounts(head1, head2);
    }

    void displayCharCounts(const string& str) {
        CharCountNode* head = buildCharCountList(str);
        cout << "Character counts in \"" << str << "\":\n";
        printCharCountList(head);
        clearCharCountList(head);  
    }

private:
    CharCountNode* buildCharCountList(const string& str) {
        CharCountNode* head = nullptr;
        CharCountNode* tail = nullptr;

        for (char ch : str) {
            CharCountNode* current = head;
            while (current) {
                if (current->character == ch) {
                    current->count++;
                    break;
                }
                current = current->next;
            }

            if (!current) { 
                CharCountNode* newNode = new CharCountNode(ch);
                if (!head) {
                    head = newNode;
                    tail = head;
                } else {
                    tail->next = newNode;
                    tail = newNode;
                }
            }
        }

        return head;
    }

    bool compareCharCounts(CharCountNode* head1, CharCountNode* head2) {
        while (head1 && head2) {
            if (head1->character != head2->character || head1->count != head2->count) {
                return false;
            }
            head1 = head1->next;
            head2 = head2->next;
        }
        return head1 == nullptr && head2 == nullptr; 
    }

    void printCharCountList(CharCountNode* head) {
        while (head) {
            cout << head->character << ": " << head->count << "\n";
            head = head->next;
        }
    }

    void clearCharCountList(CharCountNode* head) {
        while (head) {
            CharCountNode* temp = head;
            head = head->next;
            delete temp;
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
