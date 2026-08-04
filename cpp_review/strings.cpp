#include <iostream>
#include <vector>
using namespace std; 

bool isPalindrome(const string& s){

    int left = 0;
    int right = s.length()-1;

    while (left < right){

        if (s[left] == s[right]){
            left++;
            right--;
            continue;
        } else {
            return false;
        }

    }

    return true;
}

int countVowels(const string& s){

    int count = 0;
    string vowels = "AEIOUaeiou";

    for (char c : s){
        if (vowels.find(c) != string::npos) {
            count++;
        }
    }

    return count;
}

string longestCommonPrefix(vector<string>& strs){

    int longestIndex = 0;

    for(int i = 1; i < strs.size()-1; i++){
        if (strs[i].length() > strs[longestIndex].length()){
            longestIndex = i;
        }
    }

    return strs[longestIndex];
}

string reverseWordsInString(string s){

    int left = 0;

    for (int i=0; i < s.size(); i++){
        if (isspace(s[i])){
            reverse(s, left, i-1);
            left = i+1;
        }
    }
    reverse(s, left, s.size()-1);

    return s;
}

//helper function here for reversals
void reverse(string& s, int left, int right){

    while (left < right){
        swap(s[left], s[right]);
        left++;
        right--;
    }
}

int main(){

    // string n = "racecar";
    // bool result = isPalindrome(n);
    // cout << "isPalindrome : " << result << '\n';

    // +-----------------------+ count vowels

    // string n = "jacksonA";
    // int result = countVowels(n);
    // cout << "counting the vowels: " << result << '\n';

    //  +-----------------------+ longest word
    vector<string> s = {"ball", "hoops", "baller", "hi"};
    string result = longestCommonPrefix(s);
    cout << "Longest: " << result << '\n';

    return 0;

}

/*
=========================================================
                std::string Cheat Sheet
=========================================================

Declaration
-----------
string s;
string s = "hello";
string s(5, 'a');      // "aaaaa"

---------------------------------------------------------
Element Access
---------------------------------------------------------

s[i]            // O(1)
s.at(i)         // O(1), bounds checked
s.front()       // First character
s.back()        // Last character

---------------------------------------------------------
Size
---------------------------------------------------------

s.size()        // Number of characters
s.length()      // Same as size()
s.empty()       // true if empty

---------------------------------------------------------
Modification
---------------------------------------------------------

s += "abc";
s.push_back('x');
s.pop_back();

---------------------------------------------------------
Substring
---------------------------------------------------------

s.substr(start, length);

Example:

string s = "Forterra";

s.substr(0,4);      // "Fort"

---------------------------------------------------------
Find
---------------------------------------------------------

s.find("abc");

Returns:
    Index if found
    string::npos if not found

Example:

if (s.find("cat") != string::npos)
{
    // found
}

---------------------------------------------------------
Insert
---------------------------------------------------------

s.insert(index, "abc");

---------------------------------------------------------
Erase
---------------------------------------------------------

s.erase(index, length);

---------------------------------------------------------
Compare
---------------------------------------------------------

if (a == b)

if (a != b)

if (a < b)      // Lexicographical comparison

---------------------------------------------------------
Reverse
---------------------------------------------------------

reverse(s.begin(), s.end());

OR

Use two pointers.

---------------------------------------------------------
Sort
---------------------------------------------------------

sort(s.begin(), s.end());

---------------------------------------------------------
Character Functions
---------------------------------------------------------

isspace(c)

isdigit(c)

isalpha(c)

isalnum(c)

islower(c)

isupper(c)

tolower(c)

toupper(c)

---------------------------------------------------------
Character <-> Integer
---------------------------------------------------------

char c = '7';

int num = c - '0';

---------------------

int num = 7;

char c = num + '0';

---------------------------------------------------------
Looping
---------------------------------------------------------

for (char c : s)

for (const char& c : s)

for (char& c : s)

for (int i = 0; i < s.size(); i++)

---------------------------------------------------------
Passing to Functions
---------------------------------------------------------

void func(string& s)        // Modify string

void func(const string& s)  // Read only (preferred)

void func(string s)         // Makes a copy

---------------------------------------------------------
Useful STL Algorithms
---------------------------------------------------------

reverse(s.begin(), s.end());

sort(s.begin(), s.end());

find(s.begin(), s.end(), 'a');

count(s.begin(), s.end(), 'a');

---------------------------------------------------------
Complexities
---------------------------------------------------------

Index               O(1)

size                O(1)

length              O(1)

push_back           O(1) amortized

pop_back            O(1)

substr              O(k)

find                O(n)

insert              O(n)

erase               O(n)

reverse             O(n)

sort                O(n log n)

=========================================================
*/