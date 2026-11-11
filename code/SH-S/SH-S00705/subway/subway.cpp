#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
const int M=500+5;
int c,n,m,d,q;
long long w[N];
int k[M];
vector<int>Ga[M],Gt[M];
vector<pair<int,long long> >G[N];
long long dis[M][M];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++){
            Ga[i].push_back(0);
            Gt[i].push_back(0);
        }
        for(int j=1;j<=k[i];j++){
            cin>>Ga[i][j-1]>>Gt[i][j-1];
            G[Ga[i][j-1]].push_back(make_pair(i,Gt[i][j-1]));
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            dis[i][j]=LONG_LONG_MAX;
        }
        dis[i][i]=0;
    }
    for(int i=1;i<=m;i++){
        for(auto x1:G[i]){
            for(auto x2:G[i]){
                dis[x1.first][x2.first]=min(dis[x1.first][x2.first],x1.second+x2.second);
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            for(int z=1;z<=n;z++){
                if(dis[j][i]!=LONG_LONG_MAX && dis[i][z]!=LONG_LONG_MAX){
                    dis[j][z]=min(dis[j][i]+dis[i][z],dis[j][z]);
                }
            }
        }
    }
    for(int i=1;i<=q;i++){
        int x,y;
        cin>>x>>y;
        long long ans=LONG_LONG_MAX;
        for(auto x1:G[x]){
            for(auto x2:G[y]){
                ans=min(ans,dis[x1.first][x2.first]+x1.second+x2.second);
            }
        }
        cout<<ans+w[x]+w[y]<<"\n";
    }
    return 0;
}
/*int main(){
    return 0;
}*/