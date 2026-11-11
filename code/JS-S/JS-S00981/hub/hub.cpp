#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,t,n,k,d[1000006];
vector<int>e[1000006];
void dfs(int s,int dep){
    if(d[s]>dep) d[s]=dep;
    else return;
    for(auto x:e[s]) dfs(x,dep+1);
}
signed main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>t;
    while(t--){
        cin>>n>>k;
        for(int i=1;i<=n;i++) e[i].clear();

        for(int i=1;i<n;i++){
            int u,v;
            cin>>u>>v;
            e[u].push_back(v);
            e[v].push_back(u);
        }
        if(n<=10){
            int ans=1e18;
            for(int i=0;i<(1<<n);i++){
                int cnt=0;
                for(int j=0;j<n;j++)
                    if(i&(1<<j)) cnt++;
                if(cnt!=k) continue;
                for(int i=1;i<=n;i++) d[i]=1e18;
                for(int j=0;j<n;j++)
                    if(i&(1<<j)) dfs(j,0);
                int mx=0;
                for(int j=1;j<=n;j++) mx=max(mx,d[j]);
                ans=min(ans,mx);
            }
            cout<<ans<<"\n";
        }else if(k==1){
            int ans=1e18;
            for(int i=1;i<=n;i++){
                for(int i=1;i<=n;i++) d[i]=1e18;
                dfs(i,0);
                int mx=0;
                for(int j=1;j<=n;j++) mx=max(mx,d[j]);
                ans=min(ans,mx);
            }
            cout<<ans<<"\n";
        }else if(k==2){
            int ans=1e18;
            for(int i=1;i<=n;i++)
                for(int j=1;j<=n;j++){
                    for(int i=1;i<=n;i++) d[i]=1e18;
                    dfs(i,0);
                    dfs(j,0);
                    int mx=0;
                    for(int j=1;j<=n;j++) mx=max(mx,d[j]);
                    ans=min(ans,mx);
                }
            cout<<ans<<"\n";
        }else{
            int ans=1e18;
            for(int i=0;i<(1<<n);i++){
                int cnt=0;
                for(int j=0;j<n;j++)
                    if(i&(1<<j)) cnt++;
                if(cnt!=k) continue;

            }
            cout<<ans<<"\n";
        }
    }
    return 0;
}
