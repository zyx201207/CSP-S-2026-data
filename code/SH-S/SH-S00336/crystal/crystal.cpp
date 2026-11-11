#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
int const N=500005;
ll a[N];
int main() {
#ifndef DEBUG
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
#endif // DEBUG
    int n;
    ll m;
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    ll s=0;
    int ans=0;
    for(int l=1,r=1;r<=n;r++) {
        s+=a[r];
        while(l<r&&(r-l+1)*a[r]-s>m) l++,s-=a[l];
        ans=max(ans,r-l+1);
    }
    cout<<ans<<endl;
    return 0;
}
