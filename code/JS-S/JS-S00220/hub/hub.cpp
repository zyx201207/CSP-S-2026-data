#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+10,M=1e3+10;
int c,T,n,k,u,v,lt,rst,tag[N],vis[N],fa[N],dis[M][M];
vector<int>G[N];
int Find(int x){
    if(fa[x]==x) return x;
    return fa[x]=Find(fa[x]);
}
void unionset(int x,int y){
    int fx=Find(x);
    int fy=Find(y);
    if(fx==fy) return;
    fa[fx]=fy;
}
void bfs(int s){
    for(int i=1;i<=n;i++) dis[s][i]=1e9;
    for(int i=1;i<=n;i++) vis[i]=0;
    dis[s][s]=0;
    queue<int>Q;
    Q.push(s);
    while(Q.size()){
        int tu=Q.front();
        Q.pop();
        if(vis[tu]) continue;
        vis[tu]=1;
        for(int i=0;i<G[tu].size();i++){
            int tv=G[tu][i];
            if(dis[s][tv]>dis[s][tu]+1){
                dis[s][tv]=dis[s][tu]+1;
                Q.push(tv);
            }
        }
    }
    return;
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>T;
    while(T--){
        cin>>n>>k;
        for(int i=1;i<=n;i++) G[i].clear();
        for(int i=1;i<n;i++){
            cin>>u>>v;
            G[u].push_back(v);
            G[v].push_back(u);
        }
        for(int i=1;i<=n;i++) bfs(i);
        for(int i=1;i<=n;i++) sort(G[i].begin(),G[i].end());
        int ans=1e9;
        for(int S=0;S<(1<<n);S++){
            for(int i=1;i<=n;i++) tag[i]=0;
            for(int i=1;i<=n;i++) fa[i]=i;
            vector<int>cc;
            for(int i=0;i<n;i++){
                if(S&(1<<i)){
                    cc.push_back(i+1);
                    tag[i+1]=1;
                }
            }
            if(cc.size()!=k) continue;
            for(int i=0;i<cc.size();i++){
                for(int j=i+1;j<cc.size();j++){
                    int u=cc[i],v=cc[j];
                    int stt=0;
                    for(int h=0;h<G[u].size();h++){
                        if(G[u][h]==v) stt=1;
                    }
                    if(stt) unionset(u,v);
                }
            }
            int siz=0;
            for(int i=0;i<cc.size();i++){
                if(Find(cc[i])==cc[i]) siz++;
            }
            if(siz>2) continue;
            int tqr=0;
            for(int i=1;i<=n;i++){
                if(tag[i]) continue;
                int td=1e9;
                for(int j=0;j<cc.size();j++){
                    int v=cc[j];
                    td=min(td,dis[i][v]);
                }
                tqr=max(tqr,td);
            }
            ans=min(ans,tqr);
        }
        cout<<ans<<'\n';
    }
    return 0;
}
