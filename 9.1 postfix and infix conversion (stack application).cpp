#include <bits/stdc++.h>
using namespace std;

bool IsOperator(char c){
    switch(c){
        case '+':
        case '-':
        case '*':
        case '/':
        case '^':
            return true;
    }
    return false;
}

int Priority(char c){
    switch(c){
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
    }
    return 0;
}

string InToPost(string in_exp){
    stack<string> s;
    string post_exp="";
    for(int i=0;i<in_exp.length();i++){
        if(in_exp[i]=='('){
            s.push("(");
        }else if(in_exp[i]==')'){
            while(s.top()!="("){
                post_exp+=s.top(); s.pop();
            }
            s.pop();
        }else if(IsOperator(in_exp[i])){
            if(s.empty()){
                s.push(string (1,in_exp[i]));
            }else{
                string ss=s.top();
                if(Priority(ss[0])>=Priority(in_exp[i])){
                    post_exp+=s.top();
                    s.pop();
                }
                s.push(string (1,in_exp[i]));
            }
        }else{
            post_exp+=in_exp[i];
        }
    }
    while(!s.empty()){
        post_exp+=s.top();
        s.pop();
    }
    return post_exp;
}

string PostToIn(string post_exp){
    stack<string> s;
    string in_exp=" ";
    for(int i=0;i<post_exp.length();i++){
        if(IsOperator(post_exp[i])){
            string op2=s.top(); s.pop();
            string op1=s.top(); s.pop();
            s.push("("+op1+(string (1,post_exp[i]))+op2+")");
        }
        else{
            s.push(string (1,post_exp[i]));
        }
    }
    return s.top();
}

int main()
{
    int t=1;
    while(t){
        int choice;
        string expression;
        cout<<"Menu:\n1. infix to postfix\n2. postfix evaluation\nEnter choice: ";
        cin>>choice;
        cout<<"Enter expression: ";
        cin>>expression;
        switch(choice){
            case 1:
                cout<<InToPost(expression)<<endl;
                break;
            case 2:
                cout<<PostToIn(expression)<<endl;
                break;
            default:
                t--;
        }
    }
    return 0;
}


