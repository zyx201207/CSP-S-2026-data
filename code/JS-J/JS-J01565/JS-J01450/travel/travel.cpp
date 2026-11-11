#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    int f1=0,f2=0,f3=0;
    if(c1==c2){
        cout<<"1";
        f1=1;
    }else{
        cout<<"0";
    }
    if(s1[0]==s2[0] and s1[1]==s2[1] and f1==1){
        cout<<"1";
        f2=1;
    }else{
        cout<<"0";
    }
    if((s1[2]=='A' or s1[2]=='B' or s1[2]=='C') and (s2[2]=='A' or s2[2]=='B' or s2[2]=='C') and f2==1){
        cout<<"1";
        f3=1;
    }else if((s1[2]=='D' or s1[2]=='F') and (s2[2]=='D' or s2[2]=='F') and f2==1){
        cout<<"1";
        f3=1;
    }else{
        cout<<"0";
    }
    int a=s1[2]-'A';
    int b=s2[2]-'A';
    if((a-b==1 or b-a==1) and (s1[2]!='D' and s2[2]!='C') and (s1[2]!='C' and s2[2]!='D') and f3==1){
        cout<<"1";
    }else{
        cout<<"0";
    }
    return 0;
}