#include<bits/stdc++.h>
#define int long long

using namespace std;
int c,n,m,p,q;
int w[500005];
vector<int>a[505];
vector<pair<int,int> >t[505];
vector<pair<int,int> >tu[500005];
vector<pair<int,int> >nt[505];
int e[505][505];
int d[505][505];
int vis[505];
int k[500005];
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;

void dij(int s){
    memset(vis,0,sizeof vis);
    pq.push(make_pair(0,s));
    while(!pq.empty()){
        int u=pq.top().second;
        pq.pop();
        if(vis[u])continue;
        vis[u]=1;
        for(auto v:nt[u]){
            if(vis[v.first])continue;
            if(d[s][v.first]>d[s][u]+e[u][v.first]){
                d[s][v.first]=d[s][u]+e[u][v.first];
                pq.push(make_pair(d[s][v.first],v.first));
            }
        }

    }
}

signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>c>>n>>m>>p>>q;
    for(int i=1;i<=m;i++)cin>>w[i];
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++){
            int x,y;
            cin>>x>>y;
            tu[x].push_back(make_pair(i,y));
            t[i].push_back(make_pair(x,y));
        }
    }
    for(int i=1;i<=m;i++){
        for(int j=0;j<tu[i].size();j++)for(int k=j+1;k<tu[i].size();k++){
            if(e[tu[i][j].first][tu[i][k].first]==0||tu[i][j].second+tu[i][k].second<e[j][k])e[tu[i][j].first][tu[i][k].first]=e[tu[i][k].first][tu[i][j].first]=tu[i][j].second+tu[i][k].second;
        }
    }
    for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)if(e[i][j]!=0)nt[i].push_back(make_pair(j,e[i][j]));
    for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)d[i][j]=1000000000000;
    for(int i=1;i<=n;i++){
        d[i][i]=0;
        dij(i);
    }
    for(int i=1;i<=q;i++){
        int l,r;
        cin>>l>>r;
        int ans=1000000000000;
        for(auto u:tu[l])for(auto v:tu[r])ans=min(ans,d[u.first][v.first]+w[l]+w[r]+u.second+v.second);
        cout<<ans<<'\n';
    }
    return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/
