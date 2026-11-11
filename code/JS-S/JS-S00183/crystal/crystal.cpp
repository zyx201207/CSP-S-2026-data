#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int maxN=5e5+20;
ll a[maxN];
int main() {
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    ll n,m;
    cin>>n>>m;
    for (int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+n+1);
    ll l=0,r=0,s=0,ans=1;
    while (r<=n) {
        s+=(a[r+1]-a[r])*(r-l+1);
        r++;
        while (s>m) s-=a[r]-a[l++];
        ans=max(ans,r-l+1);
    }
    cout<<ans;
    return 0;
}
