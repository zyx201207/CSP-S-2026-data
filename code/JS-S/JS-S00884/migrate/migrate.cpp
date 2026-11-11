#include <bits/stdc++.h>
#define int long long
using namespace std;
int f[2000003],a[2000003],dis[2000003],vis[2000003];
struct node{
    int u,d;
};
queue<node> q;
vector<int> g[2000003];
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,T,cnt=0;
    cin>>c>>T;
    while(T--){
        cnt++;
        long long n,d;
        cin>>n>>d;
        for(int i=1;i<=n;i++) cin>>a[i];
        sort(a+1,a+n+1);
        int ans=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++) dis[j]=1e18,f[j]=0,vis[j]=0,g[j].clear();
            f[i]=dis[i]=0;
            for(int j=i+1;j<=n;j++)
                for(int k=j-1;k>=i;k--)
                    if(a[k]+d>=a[j]) g[k].push_back(j);
            q.push({i,0});
            while(!q.empty()){
                node u=q.front();
                q.pop();
                if(dis[u.u]==1e18) dis[u.u]=u.d,f[u.u]=1;
                else if(dis[u.u]==u.d) f[u.u]++;
                vis[u.u]=1;
                for(auto v:g[u.u]){
                    if(vis[v]) continue;
                    q.push({v,u.d+1});
                }
            }
            for(int j=i+1;j<=n;j++)
                if(f[j]==2) ans++;
        }
        cout<<ans<<'\n';
    }
}
