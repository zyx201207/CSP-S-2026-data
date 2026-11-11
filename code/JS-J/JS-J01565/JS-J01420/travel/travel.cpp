#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string s1,v1,s2,v2,w1="",w2="";
    cin>>s1>>v1>>s2>>v2;
    for(int i=0;i<=1;i++){
        w1+=v1[i];
        w2+=v2[i];
    }

    if(s1!=s2){
        cout<<"0000";
    }
    else if(w1!=w2){
        cout<<"1000";
    }
    else if(!((v1[2]<='C'&&v2[2]<='C')||(v1[2]>'C'&&v2[2]>'C'))){
        cout<<"1100";
    }
    else if(!((v1[2]=='A'&&v2[2]=='B')||(v1[2]=='B'&&v2[2]=='A')||(v1[2]=='B'&&v2[2]=='C')||(v1[2]=='C'&&v2[2]=='B')||(v1[2]=='D'&&v2[2]=='F')||(v1[2]=='F'&&v2[2]=='D'))){
        cout<<"1110";
    }
    else{
        cout<<"1111";
    }
    return 0;
}
