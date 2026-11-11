#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
long long w[500010];
long long a[500010];
long long t[500010];
long long g[1010][1010];
long long dis[1010][1010];
bool vis[1010][1010];
vector<pair<long long,long long> > g2[500010];
void dij(int s){
    priority_queue<pair<long long,long long>,vector<pair<long long,long long> >,greater<pair<long long,long long> > >q;
    q.push({0,s});
    while(!q.empty()){
        long long w=q.top().first;
        long long u=q.top().second;
        q.pop();
        if(vis[s][u]==true)continue;
        vis[s][u]=true;
        for(int i=0;i<g2[u].size();i++){
            long long ww=g2[u][i].first;
            long long v=g2[u][i].second;
            if(vis[s][v]==true)continue;
            dis[s][v]=min(dis[s][v],dis[s][u]+ww);
            q.push(g2[u][i]);
        }
    }
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=m;j++){
            if(j==i)continue;
            dis[i][j]=g[i][j]=1e12;
        }
    }
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        for(int j=1;j<=k;j++){
            cin>>a[j]>>t[j];
        }
        for(int j=1;j<k;j++){
            for(int l=j+1;l<=k;l++){
                g[a[j]][a[l]]=t[j]+t[l];
                g[a[l]][a[j]]=t[j]+t[l];
                g2[a[j]].push_back({t[j]+t[l],a[l]});
                g2[a[l]].push_back({t[j]+t[l],a[j]});
                dis[a[j]][a[l]]=g[a[j]][a[l]];
                dis[a[l]][a[j]]=g[a[l]][a[j]];
            }
        }
    }
    if(c>=7){
        for(int i=1;i<=m;i++){
            for(int j=1;j<=m;j++){
                if(i==j)continue;
                dis[i][j]=1e12;
            }
            dij(i);
        }
    }
    else{
        for(int i=1;i<=m;i++){
            for(int j=1;j<=m;j++){
                for(int k=1;k<=m;k++){
                    dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
                }
            }
        }
    }
    for(int i=1;i<=q;i++){
        int u,v;
        cin>>u>>v;
        cout<<w[u]+w[v]+dis[u][v]<<endl;
    }
    return 0;
}
