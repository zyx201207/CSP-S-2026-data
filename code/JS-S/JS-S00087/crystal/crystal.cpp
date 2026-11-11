#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll len=5e5+10;
ll n,m,ans;
ll a[len],b[len];
ll calc(ll tar,ll lst){
    if(lst*tar-b[lst]<=m)return lst;
    ll res=0;
    ll l=1,r=lst;
    while(l<=r){
        ll mid=(l+r)>>1;
        ll tmp=(lst-mid+1)*tar-(b[lst]-b[mid-1]);
        if(tmp<=m)res=mid,r=mid-1;
        else l=mid+1;
    }
    return lst-res+1;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        b[i]=b[i-1]+a[i];
    }
    for(int i=1;i<=n;i++){
        ll tmp=calc(a[i],i-1);
        ans=max(ans,tmp+1);
    }
    cout<<ans;
    return 0;
}
/*
bushiweishenmechuzhemeduotulunashiwodewentima???zenmeyiyanT2T3T4doushitulunya?
laodawomenzhendebukaodianbiedema??ruguowowupanlejiudangwomeishuoba.

holding no responsibility for accuracy below

"Oh to see without my eyes"
"The first time that you kissed me"
"Boundless by the time i cried"
"To build your walls around me"

"For the love for laughter i flew up to your arms -----Visions of Gideon"
*/
