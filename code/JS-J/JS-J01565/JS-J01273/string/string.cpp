#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n,ans=0;
    cin>>n;
    string s;
    for(ll i=1;i<=n;i++){
        ll k;cin>>k;
        char c;cin>>c;
        for(ll j=1;j<=k;j++) s+=c;
    }
    ll side=s.size();
    //cout<<side;//tttttttttttttttttttsssssssssssssssssddddddddddddddddddddmmmmmmmmmmmmm
    for(ll i=0;i<(side/2);i++){
        if(s[i]!=s[side-i-1]) ans++;
        //cout<<ans++<<"\n";//tttttttttttttttttttttttssssssssssssssssssssssssdddddddddddddddddddddddmmmmmmmmmmmmmmmmmmm
    }
    cout<<ans;
    return 0;
}
//remember me first csp-j2 ;but...why i can only AC(maybe) T1!!!t2 i have no idea!!! i can only have a third prize...;09:45
//t3 let me have a try 9:46 bye;
//bao_li_chu_qi_ji !!!!!9:57qian
//go to wc 10:05
//bao li wan cheng!!!10:11
//string3 sixunhuanle ???
//string3 sxh!!! 10:34
//wow!!!!!string3 tooooooooooooooo big!!!;10:40
//ping jian guo dong 10:40~45(mei chi wan)
//gai bu gai fang shou____?
//jia ge jian su 10:49
//byebye!
