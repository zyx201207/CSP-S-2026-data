#include <bits/stdc++.h>
using namespace std;

const int MAXN=2*1e6;
vector<int>G[MAXN];
bool vis[MAXN];
int dis[MAXN];
int cnt[MAXN];

void bfs(int s) {
    queue<int>q;
    q.push(s);
    dis[s]=0;
    while(!q.empty()) {
        int u=q.front();q.pop();
        if(vis[u])continue;
        vis[u]=1;
        for(auto&v:G[u]){
            if(dis[v]>=dis[u]+1) {
                dis[v]=dis[u]+1;
                cnt[v]++;
                q.push(v);
            }
        }
    }
}

void solve()
{
    int n;
    long long d;
    for(int i=1;i<=n;i++) {
        G[i].clear();
    }
    cin>>n>>d;
    int tot=0;
    vector<long long>x(n+1);
    for(int i=1;i<=n;i++) {
        cin>>x[i];
    }
    for(int i=1;i<=n;i++) {
        for(int j=1;j<i;j++) {
            if(abs(x[i]-x[j])<=d) {
                G[j].push_back(i);
            }
        }
    }

    long long ans=0;
    for(int j=1;j<=n;j++) {
        memset(vis,0,sizeof(vis));
        memset(dis,0x3f,sizeof(dis));
        memset(cnt,0,sizeof(vis));
        //cout<<'\n';
        bfs(j);
        //cout<<'\n';
        for(int i=1;i<=n;i++) {
            //cout<<cnt[i]<<' ';
            if(cnt[i]==2)ans++;
        }
        //cout<<ans<<'\n';
    }
    cout<<ans<<'\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int C,T;cin>>C>>T;
    while(T--) {
        solve();
    }


}

