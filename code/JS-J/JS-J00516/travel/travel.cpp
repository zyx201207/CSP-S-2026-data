#include<bits/stdc++.h>
#define ll long long

using namespace std;
string c,s,c1,s1;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c>>s>>c1>>s1;
    if(c!=c1){
        cout<<0000;
        return 0;
    }
    if(s[0]!=s1[0]||s[1]!=s1[1]){
        cout<<1000;
        return 0;
    }
    if('A'<=s[2]&&s[2]<='C'&&'D'<=s1[2]&&s1[2]<='F'){
        cout<<1100;
        return 0;
    }
    if('D'<=s[2]&&s[2]<='F'&&'A'<=s1[2]&&s1[2]<='B'){
        cout<<1100;
        return 0;
    }
    if(s[2]-s1[2]>1){
        cout<<1110;
        return 0;
    }
    cout<<1111;
    return 0;
}
