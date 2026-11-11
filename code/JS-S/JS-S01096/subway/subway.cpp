#include<bits/stdc++.h>
#define M 500001
#define N 501
#define inf 1e18
using namespace std;
int c,n,m,d,q;
int k;
vector<pair<int,long long> > stn[M];
long long edges[N][N];
long long w[M];
int main(){
   freopen("subway.in","r",stdin);
   freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    for(int i=0;i<N;i++)for(int j=0;j<N;j++)edges[i][j]=inf;
    for(int i=0;i<N;i++)edges[i][i]=0;
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    int a,t;
    int k;
    for(int i=1;i<=n;i++){
        cin>>k;
        for(int j=0;j<k;j++){
            cin>>a>>t;
            stn[a].push_back(make_pair(i,t));
        }
    }
    for(int i=1;i<=m;i++){
        for(int j=0;j<stn[i].size();j++){
            for(int x=j+1;x<stn[i].size();x++){
                edges[stn[i][x].first][stn[i][j].first]=edges[stn[i][j].first][stn[i][x].first]=min(stn[i][j].second+stn[i][x].second,edges[stn[i][j].first][stn[i][x].first]);
            }
        }
    }
    for(int u=m;u>=1;u--){
        for(int i=1;i<=m;i++){
            if(edges[i][u]==inf)continue;
            for(int j=i+1;j<=m;j++){
                if(edges[u][j]==inf)continue;
                edges[j][i]=edges[i][j]=min(edges[i][j],edges[i][u]+edges[u][j]);
            }
        }
    }/*
    for(int i=1;i<=n;i++)for(int j=1;j<=n;j++){this code is correct
        if(edges[i][j]!=inf)cout<<i<<" "<<j<<" "<<edges[i][j]<<endl;
    }*/
    int l,r;
    long long ans;
    while(q--){
        ans=inf;
        cin>>l>>r;
        for(int i=0;i<stn[l].size();i++){
            for(int j=0;j<stn[r].size();j++){
                ans=min(edges[stn[l][i].first][stn[r][j].first]+stn[l][i].second+stn[r][j].second,ans);
            }
        }
        cout<<ans+w[l]+w[r]<<'\n';
    }
    return 0;
}
