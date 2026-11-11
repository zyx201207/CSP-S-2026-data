#include<bits/stdc++.h>
using namespace std;

int main(){
    string s1,s2;
    int c1,c2;
    cin>>c1>>s1>>c2>>s2;
    int k1=s1[0]*10+s1[1];
    int k2=s2[0]*10+s2[1];
    char x1=s1[2];
    char x2=s2[2];
    if(c1==c2){
        cout<<"1";
        if(k1==k2){
            cout<<"1";
            if((x1=='A'&&x2=='B')||(x1=='B'&&x2=='A')||(x1=='C'&&x2=='B')||(x1=='B'&&x2=='C')||(x1=='D'&&x2=='F')||(x1=='F'&&x2=='D')){
                cout<<"1"<<"1";
            }
            else if((x1=='C'&&x2=='A')||(x1=='A'&&x2=='C')){
                cout<<"1"<<"0";
            }
            else{
                cout<<"0"<<"0";
            }
        }
        else{
            cout<<"0"<<"0"<<"0";
        }
    }
    else{
            cout<<"0"<<"0"<<"0"<<"0";
    }
    return 0;
}
