#include <bits/stdc++.h>
using ll=unsigned long long;
using namespace std;
const int N=502;
const int M=5e5+2;
int c,n,m,d,q;
ll k[N],w[M];
ll a[N][N],t[N][N],dis[N][N];
vector <int> g[M];
map <pair <int,int>,int> id;
inline void Solve() {
    int x,y;
    cin>>x>>y;
    ll res=-1;
    for(int &u:g[x])
        for(int &v:g[y]) {
            if(dis[u][v]==ULLONG_MAX)   continue;
            ll time=dis[u][v]+t[u][id[{u,x}]]+t[v][id[{v,y}]];
            res=min(res,time);
        }
    cout<<w[x]+w[y]+res<<"\n";
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)   cin>>w[i];
    for(int i=1;i<=n;i++) {
        cin>>k[i];
        for(int j=1;j<=k[i];j++) {
            cin>>a[i][j]>>t[i][j];
            g[a[i][j]].push_back(i);
            id[{i,a[i][j]}]=j;
        }
    }
    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++) if(i!=j)    dis[i][j]=dis[j][i]=ULLONG_MAX;
    for(int i=1;i<=m;i++)
        for(int j=0;j<g[i].size();j++)
            for(int k=j+1;k<g[i].size();k++) {
                int x=g[i][j];
                int y=g[i][k];
                dis[x][y]=dis[y][x]=min(dis[x][y],t[x][id[{x,i}]]+t[y][id[{y,i}]]);
            }
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                if(i!=k&&j!=k&&i!=j&&dis[i][k]!=ULLONG_MAX&&dis[k][j]!=ULLONG_MAX)    dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);//xian lu i dao xian lu j de zui xiao huan cheng shi jian
    while(q--)  Solve();
    return 0;
}  
//It's my first time to join CSP-S2,but the second time to Join CSP-J2
//I did bad in the morning
//In this problem, my answers are as same as subway1,2,3,4,5,6
//But I don't know why my answer is complete wrong in subway7
//If someone can see this
//Please put me on Luogu and @Byte_dancer
//CSP-S2 2026 RP++!
//Maybe 100+76+40=216
//Pray for me 
//Oct 31 17:14 AT CHANGZHOU 