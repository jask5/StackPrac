#include<iostream>
#include<stack>
#include<math.h>
using namespace std;


int prefixEvaluation(string s) {
    stack<int> st;
    
    for(int i = s.length()-1; i >= 0; i--) {
        //check operand

        if(s[i] >= '0' && s[i] <= '9') {
            st.push(s[i] - '0'); //coz pushing int 

        } 
        else{ //operator
        int op1 = st.top();
        st.pop();
        int op2 = st.top();
        st.pop();


        switch(s[i]) {
            case '+':
            st.push(op1 + op2);
            break;

            case '-':
            st.push(op1 - op2);
            break;

            case '*':
            st.push(op1 * op2);
            break;

            case '/':
            st.push(op1 / op2);
            break;

            case '^':
            st.push(op1/op2);
            break;
        }

    }
}

return st.top();
};



int main() {
    stack<int> st; 
    cout << prefixEvaluation("-+7*45+20")<<endl;



    return 0;
}

//-+7*45+20