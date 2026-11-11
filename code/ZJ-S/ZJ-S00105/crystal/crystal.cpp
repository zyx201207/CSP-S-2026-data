#include<bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
    int n,m;
    scanf("%lld%lld",&n,&m);
    vector<int>a(n+2,0);
    vector<int>pre(n+2,0);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    sort(a.begin()+1,a.begin()+n+1);
    for(int i=1;i<=n;i++){
        pre[i]=pre[i-1]+a[i];
    }
    int r=0,ans=0;
    for(int l=1;l<=n;l++){
        r=max(l-1,r);
        while(r+1<=n&&a[r+1]*(r+1-l+1)-(pre[r+1]-pre[l-1])<=m)r++;
        ans=max(ans,r-l+1);
    }
    printf("%lld",ans);
    return;
}
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    solve();
    return 0;
}
