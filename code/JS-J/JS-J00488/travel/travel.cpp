#include<bits/stdc++.h>
using namespace std;
string s1,s2,s3,s4;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>s1>>s2>>s3>>s4;
    if(s1!=s3){
        cout<<"0000"<<'\n';
        return 0;
    }
    if(s2[1]!=s4[1]||s2[0]!=s4[0]){
        cout<<"1000"<<'\n';
        return 0;
    }
    if(s2[2]=='A'||s2[2]=='B'||s2[2]=='C'){
        if(s4[2]!='A'&&s4[2]!='B'&&s4[2]!='C'){
            cout<<"1100"<<'\n';
            return 0;
        }
    }
    if(s2[2]!='A'&&s2[2]!='B'&&s2[2]!='C'){
        if(s4[2]=='A'||s4[2]=='B'||s4[2]=='C'){
            cout<<"1100"<<'\n';
            return 0;
        }
    }
    if(s2[2]=='A'&&s4[2]!='B'){
        cout<<"1110"<<'\n';
        return 0;
    }
    if(s2[2]=='B'&&s4[2]!='A'&&s4[2]!='C'){
        cout<<"1110"<<'\n';
        return 0;
    }
    if(s2[2]=='C'&&s4[2]!='B'){
        cout<<"1110"<<'\n';
        return 0;
    }
    if(s2[2]=='E'&&s4[2]!='F'){
        cout<<"1110"<<'\n';
        return 0;
    }
    if(s2[2]=='F'&&s4[2]!='E'){
        cout<<"1110"<<'\n';
        return 0;
    }
    cout<<"1111"<<'\n';
    return 0;
}
