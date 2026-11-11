#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll N=2e5+50;
ll f[N],n,m;
ll cnt[50];
vector<ll>v[50];
ll get(ll idx){
    ll res=1;
    for(ll i=1;i<=idx;i++){
        res*=2;
    }return res;
}
int main(){
    freopen("and.in","r",stdin);//T3: 9:40~10:20
    freopen("and.out","w",stdout);//hope: 100 about 50n
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //remeber to check !!!
    //answer : had done
    cin>>n>>m;
    for(ll i=1;i<=n;i++){
        cin>>f[i];
    }sort(f+1,f+n+1,greater<ll>());
    ll start=1,ed=n,idx=40;
    while(idx>=0){
        ll x=get(idx),cnt=0;
        for(ll i=start;i<=ed;i++){
            if((f[i]/x)%2){
                cnt++;
            }
        }if(cnt<m){
            idx--;continue;
        }idx--;
    }if(idx<0){
        ed=start+m-1;
    }
    ll ans=f[start];
    for(ll i=start+1;i<=ed;i++){
        ans&=f[i];
    }cout<<ans;
    return 0;
}
