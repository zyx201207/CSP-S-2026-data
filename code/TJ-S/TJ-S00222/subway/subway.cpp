#include<bits/stdc++.h>
using namespace std;
long long dis[505][505];long long c,n,m,d,q;
void floyd(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            for(int k=1;k<=n;k++){
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
            }
        }
    }
}
struct LNE{
    long long line,t;
};
long long w[500005];
vector<LNE> lne[500005];

void init(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            dis[i][j]=1e18;
        }
    }
    for(int i=1;i<=n;i++){
        dis[i][i]=0;
    }
    for(int i=1;i<=m;i++){
        for(LNE j:lne[i]){
            for(LNE k:lne[i]){
                if(j.line==k.line)continue;
                dis[j.line][k.line]=j.t+k.t;
                dis[k.line][j.line]=j.t+k.t;
            }
        }
    }
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)cin>>w[i];
    for(int i=1;i<=n;i++){
        long long k;cin>>k;
        for(int j=1;j<=k;j++){
            long long a,t;
            cin>>a>>t;
            lne[a].push_back({i,t});
        }
    }
    init();
    floyd();
    for(int i=1;i<=q;i++){
        long long x,y;
        cin>>x>>y;
        long long udgt=1e18;
        for(LNE j:lne[x]){
            for(LNE k:lne[y]){
                udgt=min(udgt,dis[j.line][k.line]+k.t+j.t);
            }
        }
        cout<<udgt+w[x]+w[y]<<'\n';
    }
    return 0;
}
