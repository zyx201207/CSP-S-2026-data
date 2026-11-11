#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using PII=pair<int,int>;
const int N=2e6+5;
int c,t,n,ans;
ll x[N],d;
PII dp[N];
bitset<N>vis;
PII ms(int u,int t){
    if(vis[u])return dp[u];
    if(u==t)return {0,1};
    vis[u]=1;
    int ans=N,tot=0;
    for(int i=u+1;i<=t&&__int128(x[i])-x[u]<=d;i++){
        auto[res,rtot]=ms(i,t);
        if(res<ans)ans=res,tot=rtot;
        else if(res==ans)tot+=rtot;
    }
    return dp[u]={ans+1,tot};
}
int main(){//bx chtholly
    freopen("migrate.in","r",stdin),freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0);
    cin >> c >> t;
    while(t--){
        cin >> n >> d,ans=0;
        for(int i=1;i<=n;i++)cin >> x[i];
        for(int i=n;i>=1;i--){
            vis.reset();
            for(int j=1;j<i;j++)ans+=ms(j,i).second==2;
        }
        cout << ans << '\n';
    }
    return 0;
}