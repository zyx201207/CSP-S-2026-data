#include<bits/stdc++.h>
using namespace std;
int cid,n,m,d,Q;
#define N 500005
typedef long long ll;
int w[N];
vector<pair<int,int> >vr[N];
ll dis[505][505];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>cid>>n>>m>>d>>Q;
    for(int i=1;i<=m;i++)cin>>w[i];
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        for(int j=1;j<=k;j++){
            int x,t;
            cin>>x>>t;
            vr[x].push_back({i,t});
        }
    }
    memset(dis,0x3f,sizeof(dis));
    for(int i=1;i<=m;i++){
        int k=vr[i].size();
        for(auto [u,ut]:vr[i])for(auto [v,vt]:vr[i]){
            dis[u][v]=min(dis[u][v],(ll)ut+vt);
        }
    }
    for(int i=1;i<=n;i++)dis[i][i]=0;
    for(int k=1;k<=n;k++)for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
    while(Q--){
        int x,y;
        cin>>x>>y;
        ll mn=0x3f3f3f3f3f3f3f3f;
        for(auto [u,ut]:vr[x])for(auto [v,vt]:vr[y]){
            mn=min(mn,dis[u][v]+w[x]+w[y]+ut+vt);
        }
        cout<<mn<<'\n';
    }
    return 0;
}