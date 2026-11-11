#include<bits/stdc++.h>
using namespace std;
#define eb emplace_back
#define pii pair<int,int>
#define fi first
#define se second
#define ll long long
const int M=5e5+9,N=509;const ll inf=1e18;
int c,n,m,d,q,w[M];ll dis[N][N];
vector<pii>v1[N],bl[M];
int main(){
    //int t0=clock();
    freopen("subway.in","r",stdin),freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0),cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)cin>>w[i];
    for(int i=1;i<=n;i++){
        int k;cin>>k;
        for(int j=1,x,t;j<=k;j++)cin>>x>>t,v1[i].eb(x,t),bl[x].eb(i,t);
    }for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)dis[i][j]=inf;
    for(int i=1;i<=n;i++)for(auto[x,t1]:v1[i])for(auto[y,t2]:bl[x])dis[i][y]=dis[y][i]=i==y?0:t1+t2;
    for(int k=1;k<=n;k++)for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
    for(int x,y;q--;){
        cin>>x>>y;ll mn=inf;
        for(auto[i,t]:bl[x])for(auto[j,tt]:bl[y])mn=min(mn,t+tt+dis[i][j]);
        cout<<mn+w[x]+w[y]<<'\n';
    }//cerr<<clock()-t0;
    return 0;
}