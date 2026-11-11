#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int w[5000001];
vector < pair<int,int> > E[5000001];
int dis[5000001];
int vis[5000001];
void djs(int s,int e){
    memset(dis,0x3f3f3f3f,sizeof(dis));
    memset(vis,false,sizeof(vis));
    dis[s]=0;
    priority_queue < pair<int,int>,vector< pair<int,int> >,greater< pair<int,int> > > qu;
    qu.push({0,s});
    while(!qu.empty()){
        int u=qu.top().second;
        qu.pop();
        vis[u]=true;
        if(u==e){
            break;
        }
        for(int i=0;i<E[u].size();i++){
            int v=E[u][i].second;
            if(!vis[v]){
                int dist=dis[u]+E[u][i].first;
                if(dist<dis[v]){
                    dis[v]=dist;
                }
                qu.push({dist,v});
            }
        }
    }
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
    for(int i=1;i<=m;i++){
        scanf("%d",&w[i]);
    }
    for(int i=1;i<=n;i++){
        int k;
        scanf("%d",&k);
        int a[m+1],t[m+1];
        for(int j=1;j<=k;j++){
            scanf("%d%d",&a[j],&t[j]);
        }
        for(int j=1;j<=k;j++){
            for(int l=1;l<=k;l++){
                if(j!=l){
                    E[a[j]].push_back({t[j]+t[l],a[l]});
                }
            }
        }
    }
    for(int i=1;i<=q;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        djs(x,y);
        int ans=w[x]+w[y]+dis[y];
        printf("%d\n",ans);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
