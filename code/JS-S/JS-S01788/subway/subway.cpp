#include <bits/stdc++.h>
using namespace std;
struct node{
    long long l;
    int to;
    node(int toto,long long ll){
        to=toto,l=ll;
    }
};
int cc,n,m,dd,q,a[500010],t[500010];
long long d[1000010];
vector<node>e[1000010];
set<pair<int,long long> >c;
inline void dij(int u,int v){
    c.clear();
    d[u]=0;
    c.insert({u,d[u]});
    while(!c.empty()){
        auto fg=*c.begin();
        int x=fg.first;
        c.erase(c.begin());
        if(x==v||d[x]==1LL<<60)
            break;
        for(auto y:e[x])
            if(d[x]+y.l<d[y.to]){
                c.erase({y.to,d[y.to]});
                d[y.to]=d[x]+y.l;
                c.insert({y.to,d[y.to]});
            }
    }
    printf("%lld\n",d[v]);
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    scanf("%d%d%d%d%d",&cc,&n,&m,&dd,&q);
    for(int i=1;i<=m;i++){
        int w;
        scanf("%d",&w);
        e[i].push_back(node(m+i,w));
        e[m+i].push_back(node(i,w));
    }
    for(int i=1;i<=n;i++){
        int k;
        scanf("%d",&k);
        for(int j=1;j<=k;j++)
            scanf("%d%d",&a[j],&t[j]);
        for(int j=1;j<=k;j++)
            for(int l=j+1;l<=k;l++){
                e[m+a[j]].push_back(node(m+a[l],t[j]+t[l]));
                e[m+a[l]].push_back(node(m+a[j],t[j]+t[l]));
            }
    }
    for(;q--;){
        int u,v;
        scanf("%d%d",&u,&v);
        for(int i=1;i<=2*m;i++)
            d[i]=1LL<<60;
        dij(u,v);
    }
    return 0;
}
