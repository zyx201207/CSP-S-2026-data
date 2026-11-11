#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,qq;
int w[50010];
int dist[50010];
vector<vector<pair<int,int>>>p(50010);
void djstl(int start,int endn){
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
    for(int i=1;i<=50005;i++){
        dist[i]=INT_MAX;
    }
    dist[start]=0;
    q.push(make_pair(0,start));
    while (!q.empty())
    {
        int u=q.top().second;
        q.pop();
        for(int i=0;i<=int(p[u].size())-1;i++){
            int v=p[u][i].first;
            int ww=p[u][i].second;
            if(dist[v]>dist[u]+ww){
                dist[v]=dist[u]+ww;
                if(v==endn){
                    return;
                }
                q.push(make_pair(dist[v],v));
            }
        }
    }
    return;
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>qq;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        vector<pair<int,int>>p2(50010);
        for(int j=1;j<=k;j++){
            int a,t;
            cin>>a>>t;
            p2[j]=make_pair(a,t);
        }
        for(int j=1;j<=k-1;j++){
            for(int x=j+1;x<=k;x++){
                p[p2[j].first].push_back(make_pair(p2[x].first,p2[x].second+p2[j].second));
                p[p2[x].first].push_back(make_pair(p2[j].first,p2[x].second+p2[j].second));
            }
        }
    }
    for(int i=1;i<=qq;i++){
        int x,y;
        cin>>x>>y;
        djstl(x,y);
        cout<<dist[y]+w[x]+w[y]<<endl;
    }
    return 0;
}
