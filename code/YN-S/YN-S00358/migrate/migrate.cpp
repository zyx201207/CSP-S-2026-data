#include<bits/stdc++.h>
using namespace std;
using ll=long long;
constexpr ll inf64=1e18;
constexpr int inf32=1e9;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int c,t;
    cin>>c>>t;
    while(t--){
        int n;
        ll d;
        cin>>n>>d;
        vector<ll>x(n+3);
        vector<int>ideg(n+3);
        vector<vector<int>>g(n+3);
        for(int i=1;i<=n;i++)
            cin>>x[i];
        for(int i=1;i<=n-1;i++)
            for(int j=i+1;j<=n;j++)
                if(x[j]-x[i]<=d){
                    g[i].push_back(j);
                    ideg[j]++;
                }else
                    break;
        int ans=0;
        for(int i=1;i<=n;i++){
            vector<int>w(n+3),dis(n+3,inf32),deg(n+3);
            for(int j=1;j<=n;j++)
                deg[j]=ideg[j];
            queue<int>q;
            w[i]=1;
            dis[i]=0;
            for(int j=1;j<=n;j++)
                if(!deg[j])
                    q.push(j);
            while(!q.empty()){
                int u=q.front();
                q.pop();
                for(int v:g[u]){
                    if(dis[u]+1==dis[v])
                        w[v]+=w[u];
                    if(dis[u]+1<dis[v]){
                        w[v]=w[u];
                        dis[v]=dis[u]+1;
                    }
                    if(--deg[v]==0)
                        q.push(v);
                }
            }
            for(int j=1;j<=n;j++)
                if(w[j]==2)
                    ans++;
        }
        cout<<ans<<'\n';
    }
    return 0;
}
