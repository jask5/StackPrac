#include<bits/stdc++.h>
#include<iostream>
#include<stack>
using namespace std;


bool isValid(string s) {
    int n = s.size();
    bool ans = true;

    stack<char> st;

    for(int i = 0; i <= n; i++){
        if(s[i] == '{' || s[i] == '[' || s[i] == '(') {
            st.push(s[i]);
        }
     else if(s[i] == ')') {
        if(!st.empty() && st.top() == '(') {
            st.pop();
        } else {
            ans = false;
            break;
        }
    }
    else if(s[i] == ']') {
        if(!st.empty() && st.top() == '[') {
            st.pop();
        } else {
            ans = false;
            break;
        }
    }
    else if(s[i] == '}') {
        if(!st.empty() && st.top() == '{') {
            st.pop();
        } else {
            ans = false;
            break;
        }
    }
}

//checking for remaining elements 
if(!st.empty()) {
    return false;
}

return ans;
}

int main() {
    string s = "{([]}";

    if(isValid(s)) {
        cout << "Is valid string" << endl;
    
    } else {
        cout << "Invalid" << endl;
    }
}