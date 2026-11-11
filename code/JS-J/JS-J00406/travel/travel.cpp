#include<bits/stdc++.h>
using namespace std;
bool check1(string s,string c){
    return s==c;
}
bool check2(string s,string c){
    return s[0]+s[1]==c[0]+c[1];
}
bool check3(string s,string c)
{
    if(s[2]=='A'){
        return c[2]=='B'||c[2]=='C';
    }
    else if(s[2]=='B'){
        return c[2]=='A'||c[2]=='C';
    }
    else if(s[2]=='C'){
        return c[2]=='A'||c[2]=='B';
    }
    else if(s[2]=='D'){
        return c[2]=='F';
    }
    else{
        return c[2]=='D';
    }
}
bool check4(string s,string c){
    if(s[2]=='A'){
        return c[2]=='B';
    }
    else if(s[2]=='B'){
        return c[2]=='A'||c[2]=='C';
    }
    else if(s[2]=='C'){
        return c[2]=='B';
    }
    else if(s[2]=='D'){
        return c[2]=='F';
    }
    else{
        return c[2]=='D';
    }
}
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string s1,s2,c1,c2;
    cin>>s1>>s2>>c1>>c2;
    // if(s1==c1&&s2==c2)
    // {
    //     cout<<0000;
    // }
    if(check1(s1,c1)){
        cout<<1;
    }
    else{
        cout<<0;
    }
    if(check1(s1,c1)&&check2(s2,c2)){
        cout<<1;
    }
    else{
        cout<<0;
    }
    if(check1(s1,c1)&&check2(s2,c2)&&check3(s2,c2)){
        cout<<1;
    }
    else{
        cout<<0;
    }
    if(check1(s1,c1)&&check2(s2,c2)&&check3(s2,c2)&&check4(s2,c2)){
        cout<<1;
    }
    else{
        cout<<0;
    }
}