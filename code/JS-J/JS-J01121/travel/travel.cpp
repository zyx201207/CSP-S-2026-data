#include<bits/stdc++.h>
using namespace std;

main(){
    freopen("travel.in","r",stdin);freopen("travel.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    string s1,s2,s3,s4;
    cin>>s1>>s2>>s3>>s4;
    int a=(s1[0]-'0')*10+(s1[1]-'0'),
        b=(s3[0]-'0')*10+(s3[1]-'0');
    if(a!=b){
        cout<<"0000";
        return 0;
    }
    cout<<"1";
    a=(s2[0]-'0')*10+(s2[1]-'0'),
    b=(s4[0]-'0')*10+(s4[1]-'0');
    if(a!=b){
        cout<<"000";
        return 0;
    }
    cout<<"1";
    a=(s2[2]-'A'),b=(s4[2]-'A');
    if(a<3&&b>=3||a>=3&&b<3){
        cout<<"00";
        return 0;
    }
    cout<<"1";
    if(abs(a-b)==1&&a+b!=5)cout<<"1";
    else cout<<"0";
    return 0;
}
//I LOVE CCF
