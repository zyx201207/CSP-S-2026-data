#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string s[5] = {"A","B","C","D","F"};
    ios::sync_with_stdio(false);
    cin.tie(0);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    int a,b;
    if(c1==c2)cout<<1;
    else cout<<0;
    if(c1==c2 && s1[0]==s2[0] && s1[1]==s2[1])cout<<1;
    else cout<<0;
    if(s1[0]==s2[0] && s1[1]==s2[1])cout<<1;
    else cout<<0;
    cout<<0;
    return 0;
}
