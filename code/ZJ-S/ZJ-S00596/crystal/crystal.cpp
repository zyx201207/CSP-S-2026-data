//CSP-S 2026 RP++!
#include<bits/stdc++.h>
using std::cin;
using std::cout;
using std::ios;
using std::sort;
using std::max;
using std::min;

#define int long long

const int N=5e5+5;

int a[N],n,m,pre;

void solve(){
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+n+1);
    int lef=1,rig=1,ans=1,pre=0;
    while(lef<=rig&&rig<=n){
        rig++,pre+=(rig-lef)*(a[rig]-a[rig-1]);
        if(rig>n)break;
        while(pre>m)
            pre-=(a[rig]-a[lef]),lef++;
        ans=max(ans,rig-lef+1);
    }
    cout<<ans<<'\n';
}

signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    solve();
    return 0;
}
