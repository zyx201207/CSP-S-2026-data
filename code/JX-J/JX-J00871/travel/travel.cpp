#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    //
    int a=1;
    for(int i=0;i<2;i++){
        char sa=c1[i];
        char sb=c2[i];
        if(sa != sb){
            a=0;
        }
    }
    cout<<a;
    //
    int b=a;
    for(int i=0;i<2;i++){
        char sc=s1[i];
        char sd=s2[i];
        if(sc != sd){
            b=0;
        }
    }
    cout<<b;
    //
    int c=b;
    if(s1[2]=='A'||s1[2]=='B'||s1[2]=='C'){
        if(s2[2]=='D'||s2[2]=='E'){
            c=0;
        }
    }
    if(s2[2]=='A'||s2[2]=='B'||s2[2]=='C'){
        if(s1[2]=='D'||s1[2]=='E'){
            c=0;
        }
    }
    cout<<c;
    //
    int d=c;
    if(s1[2]!=s2[2]+1 && s1[2]!=s2[2]-1){
        d=0;
    }
    cout<<d;
    return 0;
}
