#include<bits/stdc++.h>
using namespace std;
struct e{
    long long v,w;
    bool operator <(e a)const{return w<a.w;}
};
int c,n,m,dd,q,w[500005],k,a,t,d[500505],x,y,gg[505][505];
vector<e>g[500505];
void dij(long long x){
    for(int i=0;i<=m+n;i++)d[i]=1000000000;d[x]=0;
    priority_queue<e>q;
    q.push({x,0});
    while(!q.empty()){
        long long u=q.top().v;q.pop();
        for(int i=0;i<g[u].size();i++){
            long long v=g[u][i].v,w=g[u][i].w;
            if(v>m&&v<=x)continue;
            if(d[u]+w<d[v]){
                d[v]=d[u]+w;
                q.push({v,w});
            }
        }
    }
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>dd>>q;
    for(int i=1;i<=m;i++)
        scanf("%d",&w[i]);
    for(int i=1;i<=n;i++){
        scanf("%d",&k);
        for(int j=1;j<=k;j++){
            scanf("%d%d",&a,&t);
            g[a].push_back({m+i,t});
            g[m+i].push_back({a,t});
        }
    }
    for(int i=1;i<=n;i++){
        dij(i+m);
        for(int j=i;j<=n;j++)gg[i][j]=gg[j][i]=d[j+m];
    }
    while(q--){
        long long ans=1000000000000000000;
        scanf("%d%d",&x,&y);
        for(int i=0;i<g[x].size();i++){
            long long wi=g[x][i].w,vi=g[x][i].v;
            for(int j=0;j<g[y].size();j++){
                long long wj=g[y][j].w,vj=g[y][j].v;
                ans=min(ans,(long long)(w[x]+w[y]+wi+wj+gg[vi-m][vj-m]));
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
