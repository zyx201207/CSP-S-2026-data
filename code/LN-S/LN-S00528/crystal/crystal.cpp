#include<bits/stdc++.h>
#define int long long
#define qrw ios::sync_with_stdio(0),cin.tie(0)
using namespace std;
int n,m,a[1000005],f[1000005];
signed main(){
    qrw;
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++) f[i]=f[i-1]+a[i];
    int lp=1,rp=1,ans=0;
    for(;rp<=n;rp++){
        while((rp-lp+1)*a[rp]-(f[rp]-f[lp-1])>m) lp++;
        ans=max(ans,rp-lp+1);
    }
    cout<<ans<<endl;
    return 0;
}
//rp++ qwq
//Treat or trick!