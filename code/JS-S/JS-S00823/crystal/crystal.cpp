#include <bits/stdc++.h>
using namespace std;
const int N=5e5+3;
#define int long long
int n,m,a[N],sum[N],ans=1;
int get(int l,int r){ return (r-l+1)*a[r]-sum[r]+sum[l-1]; }
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
    for(int r=2,l=1;r<=n;r++){
        while(l<=r&&get(l,r)>m) l++;
        ans=max(ans,r-l+1);
    }
    cout<<ans;
}
/*

Believe in yourself.

*/
