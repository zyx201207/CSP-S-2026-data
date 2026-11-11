#include <bits/stdc++.h>
using namespace std;
string n1,n2,s1,s2;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>n1>>s1>>n2>>s2;
    if(n1!=n2){
        cout<<"0000";
    }else if(s1[0]!=s2[0]||s1[1]!=s2[1]){
        cout<<"1000";
    }else if(((s1[2]=='A'||s1[2]=='B'||s1[2]=='C')&&(s2[2]=='D'||s2[2]=='F'))||((s2[2]=='A'||s2[2]=='B'||s2[2]=='C')&&(s1[2]=='D'||s1[2]=='F'))){
        cout<<"1100";
    }else if((s1[2]=='A'&&s2[2]=='B')||(s1[2]=='B'&&s2[2]=='A')||(s1[2]=='C'&&s2[2]=='B')||(s1[2]=='B'&&s2[2]=='C')||(s1[2]=='D'&&s2[2]=='F')||(s1[2]=='F'&&s2[2]=='D')){
        cout<<"1111";
    }else{
        cout<<"1110";
    }
    return 0;
}
