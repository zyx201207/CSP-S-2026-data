#include<bits/stdc++.h>
using namespace std;
ifstream fin("hub.in");
ofstream fout("hub.out");
#define cin fin
#define cout fout
const int N=10;
int C,T,n,k,dis[N],mn,fa[N];
vector<int> G[N];
bool f[N],f2[N];
void dfs(int u,int fa,int d) {
    dis[u]=min(dis[u],d);
    for(int v:G[u]) if(v!=fa) dfs(v,u,d+1);
}
int find(int x) {
    if(fa[x]==x) return x;
    return fa[x]=find(fa[x]);
}
void merge(int u,int v) {
    int x=find(u),y=find(v);
    if(x!=y) fa[x]=y;
}
int main() {
    cin>>C>>T;
    while(T--) {
        cin>>n>>k; mn=n;
        for(int i=0;i<n;i++) {
            G[i].clear();
        }
        for(int i=1;i<n;i++) {
            int u,v; cin>>u>>v; u--,v--;
            G[u].push_back(v);
            G[v].push_back(u);
        }
        for(int o=0;o<1<<n;o++) {
            int c=0;
            for(int i=0;i<n;i++) f2[i]=0;
            for(int i=0;i<n;i++) {
                f[i]=o&(1<<i);
                if(o&(1<<i)) c++;
            }
            if(c!=k) continue;
            for(int i=0;i<n;i++) dis[i]=n,fa[i]=i;
            for(int u=0;u<n;u++)
                for(int v=0;v<n;v++)
                    if(f[u]&&f[v]) cerr<<u<<' '<<v<<'\n',merge(u,v);
            for(int i=0;i<n;i++) if(f[i]) f2[find(i)]=1;
            int c2=0;
            for(int i=0;i<n;i++) c2+=f2[i];
            cerr<<c2<<'\n';
            if(c2>2) continue;
            for(int i=0;i<n;i++) if(f[i]) dfs(i,0,0);
            int mx=0;
            for(int i=0;i<n;i++) {
                mx=max(mx,dis[i]);
            }
            mn=min(mn,mx);
        }
        cout<<mn<<'\n';
    }
}