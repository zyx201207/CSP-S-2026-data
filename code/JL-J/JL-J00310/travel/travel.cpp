#include <bits/stdc++.h>
using namespace std;
map<char,int> mp,mp2;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string s1,s2,s3,s4;
    cin>>s1>>s2>>s3>>s4;
    if(s1==s3){
        cout<<'1';
    }else{
        cout<<"0000";
        return 0;
    }
    if(s2[0]+s2[1]==s4[0]+s4[1]){
        cout<<'1';
    }else{
        cout<<"000";
        return 0;
    }
    mp['D']=1;
    mp['F']=1;
    mp['A']=2;
    mp['C']=2;
    mp['B']=2;
    int t3=mp[s2[2]],t4=mp[s4[2]];
    if(t3==t4){
        cout<<"1";
    }else{
        cout<<"00";
        return 0;
    }
    mp2['D']=4;
    mp2['F']=5;
    mp2['A']=1;
    mp2['B']=2;
    mp2['C']=3;
    t3=mp2[s2[2]],t4=mp2[s4[2]];
    if(abs(t3-t4)==1){
        cout<<'1';
    }else{
        cout<<'0';
    }
    return 0;
}
