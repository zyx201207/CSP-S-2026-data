#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int a,b;
    string s1,s2;
    cin>>a>>s1>>b>>s2;
    if(a!=b){
        cout<<"0000";
        return 0;
    }
    if(s1[0]!=s2[0]||s1[1]!=s2[1]){
        cout<<"1000";
        return 0;
    }
    if(s1[2]<='C'&&s2[2]>'C'||s2[2]<='C'&&s1[2]>'C'){
        cout<<"1100";
        return 0;
    }
    if(s1[2]=='A'&&s2[2]=='C'||s1[2]=='C'&&s2[2]=='A'){
        cout<<"1110";
        return 0;
    }
    cout<<"1111";
    return 0;
}
