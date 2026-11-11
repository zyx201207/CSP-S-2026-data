#include<bits/stdc++.h>
#define PII pair<int,int>
using namespace std;
const int N=510,M=500010;
int c,n,m,d,q;
int w[M];
int k[N];
int a[N][M],t[N][M];
long long dist[N][N];
vector<PII> ve[M];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++) dist[i][j]=1e18;
        dist[i][i]=0;
    }
    for(int i=1;i<=m;i++) cin>>w[i];
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++){
            cin>>a[i][j];
            cin>>t[i][a[i][j]];
            ve[a[i][j]].push_back({i,t[i][a[i][j]]});
        }
    }
    for(int i=1;i<=m;i++){
        int len=ve[i].size();
        for(int j=0;j<len;j++){
            int u=ve[i][j].first,co1=ve[i][j].second;
            for(int k=j+1;k<len;k++){
                int v=ve[i][k].first,co2=ve[i][k].second;
                dist[u][v]=dist[v][u]=min(dist[u][v],(long long)co1+co2);
            }
        }
    }
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++) dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
    while(q--){
        int x,y;
        cin>>x>>y;
        long long ans=1e18;
        int len1=ve[x].size(),len2=ve[y].size();
        for(int i=0;i<len1;i++)
            for(int j=0;j<len2;j++){
                int u=ve[x][i].first,v=ve[y][j].first;
                ans=min(ans,t[u][x]+dist[u][v]+t[v][y]);
            }
        cout<<ans+w[x]+w[y]<<endl;
    }
    return 0;
}
