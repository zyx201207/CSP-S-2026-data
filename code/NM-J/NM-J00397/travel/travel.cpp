#include<bits/stdc++.h>
using namespace std;
int main{
    ios::sync_with_stdio(false)
    cin.tie(mullptr);
    freopen("travel.in ","r",stdin);
    freopen("travel.out ","w",stdout);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){
        cout<<1;
    }
    else{
        cout<<"0000";
    }
    //
    if(s1[1]==s2[1]&&c1==c2){
        cout<<"1";
    }
    else{
        cout<<"0";
    }
    //
    if(s1[1]==s2[1]&&s1[2]=='C'&&s2[2]=='D'){
        cout<<"1";
    }
    else if(s1[1]==s2[1]&&s1[2]=='D'&&s2[2]=='C'){
        cout<<"1";
    }
    else if(s1[1]==s2[1]&&s1[2]=='B'&&s2[2]=='F'){
        cout<<"1";
    }
    else if(s1[1]==s2[1]&&s1[2]=='F'&&s2[2]=='B'){
        cout<<"1";
    }
    else{
        cout<<"0";
    }
    //
    if(s1[1]==s2[1]&&s1[2]=='A'&&s2[2]=='B'){
        cout<<"1";
    }
    else if(s1[1]==s2[1]&&s1[2]=='B'&&s2[2]=='A'){
        cout<<"1";
    }
    else if(s1[1]==s2[1]&&s1[2]=='B'&&s2[2]=='C'){
        cout<<"1";
    }
    else if(s1[1]==s2[1]&&s1[2]=='C'&&s2[2]=='B'){
        cout<<"1";
    }
    else if(s1[1]==s2[1]&&s1[2]=='C'&&s2[2]=='D'){
        cout<<"1";
    }
    else if(s1[1]==s2[1]&&s1[2]=='D'&&s2[2]=='C'){
        cout<<"1";
    }
    else if(s1[1]==s2[1]&&s1[2]=='C'&&s2[2]=='E'){
        cout<<"1";
    }
    else if(s1[1]==s2[1]&&s1[2]=='E'&&s2[2]=='C'){
        cout<<"1";
    }
    
    else if(s1[1]==s2[1]&&s1[2]=='E'&&s2[2]=='F'){
        cout<<"1";
    }
    else if(s1[1]==s2[1]&&s1[2]=='F'&&s2[2]=='E'){
        cout<<"1";
    }
    else{
        cout<<"0";
    }
    return 0;
}
