//https://leetcode.com/problems/letter-combinations-of-a-phone-number/

#include<iostream>
#include<vector>
#include "array.cpp"
using namespace std;


class Solution {

private:
    void solve(string digits, string output, int index, vector<string> &ans, string mapping[]){
        //base case
        if (index >= digits.length()){
            ans.push_back(output);
            return;
        }

        int number = digits[index] - '0';
        string value = mapping[number];

        for(int i = 0; i < value.length(); i++){
            output.push_back(value[i]);
            solve(digits, output, index + 1, ans, mapping);
            output.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if (digits.length() == 0){
            return ans;
        }
        string output;
        int index = 0;
        string mapping[10] = {"","", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

        solve(digits, output, index, ans, mapping);

        return ans;
        
    }
};



int main(){
    string digits;
    cout << "Enter digits:";
    cin >> digits;

    Solution o1;
    vector<string> ans = o1.letterCombinations(digits);
    
    print_vector_s(ans);
    cout << "\n Length:" << ans.size();

}