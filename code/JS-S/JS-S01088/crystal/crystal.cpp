#include<bits/stdc++.h>
using namespace std;
using ll=long long;

int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,ans=0; ll m;
    cin>>n>>m;
    vector<ll> a(n+1);
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a.begin()+1,a.end());
    ll cur=0;
    for(int i=1,j=1;i<=n;i++){
        cur+=1ll*(i-j)*(a[i]-a[i-1]);
        while(cur>m) cur-=(a[i]-a[j]),j++;
        ans=max(i-j+1,ans);
    }
    cout<<ans<<'\n';
}