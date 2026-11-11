#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string str1,str2,str3,str4;
    cin>>str1>>str2>>str3>>str4;
    if(str1!=str3){
        cout<<"0000"<<'\n';
        return 0;
    }
    string ans="1";
    if(str2.substr(0,2)!=str4.substr(0,2)){
        cout<<"1000"<<'\n';
        return 0;
    }
    if((str2[2]=='A'||str2[2]=='B'||str2[2]=='C')&&(str4[2]!='A'&&str4[2]!='B'&&str4[2]!='C')){
        cout<<"1100"<<'\n';
        return 0;
    }
    if((str2[2]=='D'||str2[2]=='F')&&(str4[2]!='D'&&str4[2]!='F')){
        cout<<"1100"<<'\n';
        return 0;
    }
    if((str2[2]=='D'||str2[2]=='F')){
        cout<<"1111"<<'\n';
        return 0;
    }
    if(str2[2]=='B'||str4[2]=='B'){
        cout<<"1111"<<'\n';
        return 0;
    }
    cout<<"1110"<<'\n';
    return 0;
}
