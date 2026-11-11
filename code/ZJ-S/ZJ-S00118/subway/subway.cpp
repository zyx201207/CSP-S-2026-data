#include<bits/stdc++.h>
using namespace std;

int n,m,q;
int w[500010],k[505],cnt[500010],f[505][505],a[500010][25],b[500010][25];
long long dis[505][505];

int main(){ // rnd(84,100)
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    scanf("%*d%d%d%*d%d",&n,&m,&q);
    for (int i=1;i<=m;++i) scanf("%d",w+i);
    for (int i=1;i<=n;++i) for (int j=1;j<=n;++j) f[i][j]=2147483647;
    memset(dis,0x3f,sizeof dis);
    for (int i=1;i<=n;++i){
        scanf("%d",k+i);
        for (int j=1;j<=k[i];++j){
            int x,y;  scanf("%d%d",&x,&y);
            for (int v=1;v<=cnt[x];++v){
                if (f[i][a[x][v]]>y+b[x][v]) f[i][a[x][v]]=f[a[x][v]][i]=y+b[x][v];
            }
            a[x][++cnt[x]]=i,b[x][cnt[x]]=y;
        }
    }
    for (int x=1;x<=n;++x){
        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>> q;
        q.push({0,x}),dis[x][x]=0;
        while (!q.empty()){
            pair<long long,int> u=q.top();  q.pop();
            if (dis[x][u.second]<u.first) continue;
            for (int v=1;v<=n;++v){
                if (f[u.second][v]!=2147483647 && u.first+f[u.second][v]<dis[x][v])
                    dis[x][v]=u.first+f[u.second][v],q.push({dis[x][v],v});
            }
        }
    }
    while (q--){
        int x,y;  scanf("%d%d",&x,&y);
        long long res=9223372036854775807;
        for (int i=1;i<=cnt[x];++i) for (int j=1;j<=cnt[y];++j){
            long long p=dis[a[x][i]][a[y][j]]+b[x][i]+b[y][j];
            if (res>p) res=p;
        }
        printf("%lld\n",res+w[x]+w[y]);
    }
    return 0;
}
