#include<bits/stdc++.h>
#define int long long
#define ls (p<<1)
#define rs (p<<1|1)
#define mid (l+r>>1)
using namespace std;
map<char,int> mp;
signed main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    mp['F']=1;
    mp['D']=1;
    mp['C']=2;
    mp['B']=2;
    mp['A']=2;
    if(c1!=c2) cout<<"0000";
    else{
        if(s1[0]==s2[0]&&s1[1]==s2[1]){
            if(mp[s1[2]]!=mp[s2[2]]) cout<<"1100";
            else{
                char t1=s1[2],t2=s2[2];
                if(t1>t2) swap(t1,t2);
                if(t1=='A'&&t2=='B'||t1=='B'&&t2=='C'||t1=='D'&&t2=='F') cout<<"1111";
                else cout<<"1110";
            }
        }else cout<<"1000";
    }
    return 0;
}