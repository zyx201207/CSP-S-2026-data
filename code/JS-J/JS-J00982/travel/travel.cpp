#include<bits/stdc++.h>
using namespace std;
string s[3];

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,c2;
    string s1,s2;
    for(int i=0;i<1;i++){
    cin>>c1[i];
    }
    for(int i=0;i<2;i++){
    cin>>s1[i];
    }
    for(int i=0;i<1;i++){
    cin>>c2[i];
    }
    for(int i=0;i<2;i++){
    cin>>s2[i];
    }
    if(c1[0]!=c2[0]||c1[1]!=c2[1]){
        s[0]="0";
        s[1]="0";
        s[2]="0";
        s[3]="0";
    }
    else if(s1[0]!=s2[0]||s1[1]!=s2[1]){
        s[0]="1";
        s[1]="0";
        s[2]="0";
        s[3]="0";
    }
    else if(((s1=="F")&&(s2!="D"))||((s1=="D")&&(s2!="F"))||((s1=="A")&&(s2!="B")&&(s2!="C"))||((s1=="B")&&(s2!="A")&&(s2!="C"))||((s1=="C")&&(s2!="B")&&(s2!="A"))){
        s[0]="1";
        s[1]="1";
        s[2]="0";
        s[3]="0";
    }
    else if(((s1=="A")&&(s2!="B"))||((s1=="B")&&(s2!="A")&&(s2!="C"))||((s1=="C")&&(s2!="B"))){
        s[0]="1";
        s[1]="1";
        s[2]="1";
        s[3]="0";
    }
    else{
        s[0]="1";
        s[1]="1";
        s[2]="1";
        s[3]="1";
    }
    for(int i=0;i<3;i++){
        cout<<s[i];
    }
    return 0;
}
