#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,a[500100],tot[500100],ans=1;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    std::ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(ll i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    for(ll i=1;i<=n;i++){
        tot[i]=a[i]+tot[i-1];
        while(a[i]*(ans+1)+tot[i-ans-1]-tot[i]<=m&&i-ans>0) ans++;
    }
    cout<<ans;
    return 0;
}
