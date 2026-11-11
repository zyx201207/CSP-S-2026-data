#include <bits/stdc++.h>
using namespace std;
const int N=1e6+10;

int read() {
    int s=0;
    char c=getchar();
    while(c<'0' || c>'9') c=getchar();
    while(c>='0' && c<='9') s=s*10+c-'0',c=getchar();
    return s;
}

int T;
int n,m;
vector<int> g[N];
pair<int,int> e[N];
int dis[N];

int calc(int msk) {
    if(__builtin_popcount(msk)>m) return n;
    for(int i=1;i<=n;i++) dis[i]=(msk>>i-1&1)? 0:1e9;
    int c=__builtin_popcount(msk);
    for(int i=1;i<n;i++) c-=(msk>>e[i].first-1&1)&(msk>>e[i].second-1&1);
    if(c>2) return n;
    queue<int> pq;
    for(int i=1;i<=n;i++) if(!dis[i]) pq.push(i);
    while(!pq.empty()) {
        int u=pq.front();
        pq.pop();
        for(int v:g[u]) {
            if(dis[v]>dis[u]+1) {
                dis[v]=dis[u]+1;
                pq.push(v);
            }
        }
    }
    int res=0;
    for(int i=1;i<=n;i++) res=max(res,dis[i]);
    return res;
}

int main() {
    freopen("data.in","r",stdin);
    freopen("bf.out","w",stdout);
    read();
    T=read();
    while(T--) {
        n=read(),m=read();
        for(int i=1;i<=n;i++) g[i].clear();
        for(int i=1;i<n;i++) {
            int u,v;
            scanf("%d%d",&u,&v);
            g[u].push_back(v),g[v].push_back(u);
            e[i]={u,v};
        }
        int ans=n;
        for(int i=1;i<1<<n;i++) ans=min(ans,calc(i));
        printf("%d\n",ans);
    }
    return 0;
}
