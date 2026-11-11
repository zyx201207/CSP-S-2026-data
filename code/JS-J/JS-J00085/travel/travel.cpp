#include<bits/stdc++.h>
using namespace std;
#define int long long
string s1, s2, s3, s4;
signed main(){
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    cin>>s1>>s2>>s3>>s4;
    if(s1 != s3) cout<<"0000";
    else if(s2[1]!=s4[1]||s2[0]!=s4[0]) cout<<"1000";
    else if(((s2[2]=='A'||s2[2]=='B'||s2[2]=='C')&&(s4[2]=='D'||s4[2]=='E'))||((s4[2]=='A'||s4[2]=='B'||s4[2]=='C')&&(s2[2]=='D'||s2[2]=='E')))cout<<"1100";
    else if(s2[2]=='A'&&s4[2]=='C'||s4[2]=='A'&&s2[2]=='C') cout<<"1110";
    else cout<<1111;
    return 0;
}

