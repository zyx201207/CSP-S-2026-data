#include <bits/stdc++.h>
using namespace std;

#define int long long

set<int> s;
vector<int> edges[1000011];
int q[1000011],dist[1011][1011],fa[1000011],p[1000011],c,t,n,k,ans;
bool b[1000011];

inline void read(int &x){
    char c=getchar();
    int s=1;
    while(c<'0'||c>'9'){
        if(c=='-')
            s*=-1;
        c=getchar();
    }
    x=0;
    while(c>='0'&&c<='9')
        x=(x<<1)+(x<<3)+c-48,
        c=getchar();
    x*=s;
    return;
}

inline void bfs(int s){
    int front=1,rear=0;
    for(int i=1;i<=n;i++)
        dist[s][i]=-1;
    dist[s][s]=0;
    q[++rear]=s;
    while(front<=rear){
        int x=q[front++];
        for(auto i:edges[x])
            if(dist[s][i]==-1)
                dist[s][i]=dist[s][x]+1;
    }
    return;
}

int Find(int x){
    if(fa[x]==x)
        return x;
    fa[x]=Find(fa[x]);
    return fa[x];
}
inline void Union(int x,int y){
    int fx=Find(x),fy=Find(y);
    if(fx==fy)
        return;
    fa[fx]=fy;
    return;
}

inline void dfs(int x){
    if(x==k+1){
        for(int i=1;i<=n;i++)
            fa[i]=i;
        for(int i=1;i<=k;i++)
            for(auto j:edges[p[i]])
                if(b[j])
                    Union(p[i],j);
        s.clear();
        for(int i=1;i<=n;i++)
            if(b[i])
                s.insert(fa[i]);
        if(s.size()>2)
            return;
        int r=-(1<<30);
        for(int i=1;i<=n;i++){
            int d=1<<30;
            for(int j=1;j<=k;j++)
                d=min(d,dist[i][p[j]]);
            r=max(r,d);
        }
        ans=min(ans,r);
        return;
    }
    for(int i=p[x-1]+1;i<=n-k+x;i++){
        p[x]=i,b[i]=1;
        dfs(x+1);
        b[i]=0;
    }
    return;
}

signed main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    read(c),read(t);
    for(;t--;){
        read(n),read(k);
        for(int i=1;i<n;i++){
            int u,v;
            read(u),read(v);
            edges[u].push_back(v);
            edges[v].push_back(u);
        }
        for(int i=1;i<=n;i++){
            bfs(i);
        }
        ans=1<<30;
        dfs(1);
        printf("%lld\n",ans);
    }
    return 0;
}
