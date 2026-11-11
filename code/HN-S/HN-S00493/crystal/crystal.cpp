/*
宇宙冷漠，这张牌我是，非常了解的。
*/
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int n;
ll m;
const int N=5e5;
ll a[N+5];
void solve(){
    cin>>n>>m;
    for(int i=1;i<=n;++i) cin>>a[i];
    sort(a+1,a+n+1);
    int p=1;
    ll sum=0;
    int ans=1;
    for(int i=2;i<=n;++i){
        sum+=(a[i]-a[i-1])*(i-p);
        while(sum>m){
            sum-=a[i]-a[p];
            ++p;
        }
        ans=max(i-p+1,ans);
    }
    cout<<ans<<"\n";
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);
    int Tcases=1;
    // cin>>Tcases;
    while(Tcases--) solve();
    return 0;
}
/*
在古代，穷人一拳打倒十个保安到底有多爽。
*/