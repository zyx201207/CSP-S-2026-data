#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","w",stdin);
    freopen("travel.out","r",stdout);
    string c1,s1,c2,s2;
    bool flag;
    cin>>c1>>s1>>c2>>s2;
    if(c1[1]==c2[1]) {
            cout<<1;
            flag=1;
    }
    else {
            cout<<0;
            flag=0;}
    if(s1[1]==s2[1]&&flag==1) cout<<1;
    else {
            cout<<0;
            flag=0;}
    if(((s1[2]>='A'&&s1[2]<='C')&&(s2[2]>='A'&&s2[2]<='C')||(s1[2]>='D'&&s1[2]<='F')&&(s2[2]>='D'&&s2[2]<='F'))&&flag==1) {
            cout<<1;}
    else {
            cout<<0;
            flag=0;
    }
    int n=s1[2]-s2[2];
    if((n==1||n==-1)&&flag==1) cout<<1;
    else cout<<0;
    return 0;
}
