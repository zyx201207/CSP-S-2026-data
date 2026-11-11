#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int re1=0,re2=0,re3=0,re4=0;
int side(char x){
    if(x=='A' || x=='B' || x=='C'){
        return 1;
    }
    return 0;
}
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1!=c2){
        cout<<"0000\n";
        return 0;
    }
    if(s1[0]!=s2[0] || s1[1]!=s2[1]){
        cout<<"1000\n";
        return 0;
    }
    if(side(s1[2])!=side(s2[2])){
        cout<<"1100\n";
        return 0;
    }
    if(s1[2]+1!=s2[2] &&s1[2]-1!=s2[2]){
        cout<<"1110\n";
        return 0;
    }
    cout<<"1111\n";
    fclose(stdin);
    fclose(stdout);
    return 0;
}
