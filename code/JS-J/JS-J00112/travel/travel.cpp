#include<bits/stdc++.h>
using namespace std;
char s2[5], s4[5];
int main(){
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s1, s3;
    cin>>s1>>s2>>s3>>s4;
    bool flag=1;
    if(s1==s3){
        cout<<1;
    }
    else {
        cout<<0;
        flag=0;
    }
    if(flag==0){
        for(int i=1; i<=3; i++) cout<<0;
        return 0;
    }
    if(s2[0]==s4[0]&&s2[1]==s4[1]){
        cout<<1;
    }
    else {
        cout<<0;
        flag=0;
    }
    if(flag==0){
        for(int i=1; i<=2; i++) cout<<0;
        return 0;
    }
    if((s2[2]<='C'&&s4[2]<='C')||(s2[2]>'C'&&s4[2]>'C')){
        cout<<1;
    }
    else {
        cout<<0;
        flag=0;
    }
    if(flag==0){
        cout<<0;
        return 0;
    }
    if(abs(s2[2]-s4[2])==1) cout<<1;
    else cout<<0;

    return 0;
}
