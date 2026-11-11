#include<bits/stdc++.h>
using namespace std;
int a,b;
string s1,s2;
int m,n,m1,n1;
int x2,y2,numm;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a>>s1>>b>>s2;
    if(a!=b){
        cout<<"0000";
        return 0;
    }
    m=s1[0]-'0';
    n=s1[1]-'0';
    m1=s2[0]-'0';
    n1=s2[1]-'0';
    if(n!=n1||m!=m1){
        cout<<"1000";
        return 0;
    }
    x2=s1[2]-'A';
    y2=s2[2]-'A';
    numm=x2-y2;
    if(((s1[2]=='A'||s1[2]=='B'||s1[2]=='C')&&(s2[2]=='A'||s2[2]=='B'||s2[2]=='C'))||((s1[2]=='D'||s1[2]=='F')&&(s2[2]=='D'||s2[2]=='F'))){
        if(abs(numm)==1){
            cout<<"1111";
        }else{
            cout<<"1110";
            return 0;
        }
    }else{
        cout<<"1100";
        return 0;
    }
    return 0;
}
