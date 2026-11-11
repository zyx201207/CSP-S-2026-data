#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
#include <map>
#include <set>

using std::cin; using std::cout;
using std::queue; using std::priority_queue; using std::vector;
using std::map; using std::set;

const int maxn=550,maxm=550000;

struct pair2 {
    int v,w;
};

int c,n,m,d,q;
int w[maxm],k[maxm];
vector<int> a[maxm],t[maxm];
int x[maxm],y[maxm];
long long f[maxn][maxn];
vector<pair2> fa[maxm];

int main() {
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);

    memset(f,0x1f,sizeof(f));
    scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
    for(int i=1;i<=n;i++) {
        f[i][i]=0;
    }
    for(int i=1;i<=m;i++) {
        scanf("%d",&w[i]);
    }
    for(int i=1;i<=n;i++) {
        scanf("%d",&k[i]);
        a[i].resize(k[i]+3);
        t[i].resize(k[i]+3);
        for(int j=1;j<=k[i];j++) {
            scanf("%d%d",&(a[i])[j],&(t[i])[j]);
            fa[(a[i])[j]].push_back({i,(t[i])[j]});
        }
    }
    for(int i=1;i<=m;i++) {
        int size=fa[i].size();
        for(int j=0;j<size;j++) {
            for(int k=j+1;k<size;k++) {
                int u=(fa[i])[j].v;
                int v=(fa[i])[k].v;
                long long temp=(fa[i])[j].w+(fa[i])[k].w;
                f[u][v]=std::min(f[u][v],temp);
                f[v][u]=f[u][v];
            }
        }
    }
    for(int k=1;k<=n;k++) {
        for(int u=1;u<=n;u++) {
            for(int v=1;v<=n;v++) {
                f[u][v]=std::min(f[u][v],f[u][k]+f[k][v]);
            }
        }
    }
    for(int i=1;i<=q;i++) {
        long long ans=0x1f1f1f1f1f1f1f1f;
        scanf("%d%d",&x[i],&y[i]);
        int sx=fa[x[i]].size();
        int sy=fa[y[i]].size();
        for(int j=0;j<sx;j++) {
            int u=(fa[x[i]])[j].v;
            long long t1=(fa[x[i]])[j].w;
            for(int k=0;k<sy;k++) {
                int v=(fa[y[i]])[k].v;
                long long t2=(fa[y[i]])[k].w;
                ans=std::min(ans,f[u][v]+t1+t2);
            }
        }
        ans+=w[x[i]]+w[y[i]];
        printf("%lld\n",ans);
    }
    return 0;
}