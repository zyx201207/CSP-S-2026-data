#include <bits/stdc++.h>
using namespace std;
#define int long long
int c,t,n,d;
const int N=1e6+5;
int x[N],dp[N],cnt[N],q[N],hd,tl;
void solve(){
    cin>>n>>d;
    for (int i=1;i<=n;++i)
        cin>>x[i];
    int ans=0;
    for (int i=1;i<=n;++i){
        dp[i]=0;
        for (int j=i+1;j<=n;++j)
            dp[j]=0x3f3f3f3f3f3f3f3f;
        cnt[i]=1;
        hd=1,tl=0;
        q[++tl]=i;
        for (int j=i+1;j<=n;++j)
            cnt[j]=0;
        for (int j=i+1;j<=n;++j){
            while(hd<=tl&&(x[j]-x[q[hd]])>d) ++hd;
            if(hd<=tl)dp[i]=dp[q[hd]]+1;
            int p=hd;
            while(p<=tl&&dp[q[p]]==dp[q[hd]]) cnt[j]+=cnt[q[p]],++p;
            while(hd<=tl&&dp[j]<dp[q[tl]]) --tl;
            q[++tl]=j;
        }
        for (int j=i+1;j<=n;++j)
            ans+=(cnt[j]==2);
    }
    cout<<ans<<"\n";
    return;
}
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>c>>t;
    while(t--)
        solve();
    return 0;
}