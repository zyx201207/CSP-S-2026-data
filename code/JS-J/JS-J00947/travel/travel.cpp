#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin.sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    string s1,s2,t1,t2;
    cin>>s1>>s2>>t1>>t2;
    map<char,int> mp;
    mp['A']=0;mp['B']=0;mp['C']=0;
    mp['D']=1;mp['F']=1;
    if(s1==t1)cout<<"1";
    else{
        cout<<"0000";
        return 0;
    }
    if(s2[0]==t2[0]&&s2[1]==t2[1])cout<<"1";
    else{
        cout<<"000";
        return 0;
    }
    if(mp[s2[2]]==mp[t2[2]])cout<<"1";
    else{
        cout<<"00";
        return 0;
    }
    if((s2[2]=='A'&&t2[2]=='B')||(s2[2]=='B'&&t2[2]=='A')||(s2[2]=='B'&&t2[2]=='C')||(s2[2]=='C'&&t2[2]=='B')||(s2[2]=='D'&&t2[2]=='F')||(s2[2]=='F'&&t2[2]=='D'))cout<<"1";
    else cout<<"0";
}
//100~100
