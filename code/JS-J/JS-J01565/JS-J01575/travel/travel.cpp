#include<bits/stdc++.h>
using namespace std;

string c1,s1,c2,s2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1!=c2){
        cout<<"0000";
        return 0;
    }
    cout<<"1";
    if(s1[1]==s2[1]&&s1[0]==s2[0]){
        cout<<"1";
    }
    else{
        cout<<"000";
        return 0;
    }
    char a=s1[2],b=s2[2];
    int f1=0,f2=0;
    if(a=='A'||a=='B'||a=='C'){
        f1=1;
    }
    if(b=='A'||b=='B'||b=='C'){
        f2=1;
    }
    if(f1!=f2){
        cout<<"00";
        return 0;
    }
    cout<<"1";
    if(abs(a-b)==1){
        cout<<"1";
    }
    else{
        cout<<"0";
    }
    return 0;
}
