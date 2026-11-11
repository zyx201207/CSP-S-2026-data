#include<bits/stdc++.h>
using namespace std;
int t1,c1,t2,c2;
char s1,s2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>t1>>c1>>s1>>t2>>c2>>s2;
    if(t1==t2)cout<<"1";
    else{cout<<"0000";return 0;}
    if(c1==c2)cout<<"1";
    else{cout<<"000";return 0;}
    if(s1=='A'||s1=='B'||s1=='C'){
        if(s2=='A'||s2=='B'||s2=='C')cout<<"1";
        else{cout<<"00";return 0;}
    }
    else{
        if(s2=='D'||s2=='E')cout<<"1";
        else{cout<<"00";return 0;}
    }
    if(s2==s1+1||s2==s1-1)cout<<"1";
    else cout<<"0";
    return 0;
}
