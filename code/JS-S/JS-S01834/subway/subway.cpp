#include<bits/stdc++.h>
#define int __int128
#define endl '\n'
#define inf 123456789000000
#define N 505
#define M 500005
using namespace std;
int f[N][N];
struct edge{
    int to,t;
};
vector<edge> ztl[M];
int w[M],k[N];
long long c,n,m,d,q;
vector<edge> a[M];
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        long long x;cin>>x;
        w[i]=x;
    }
    for(int i=1;i<=n;i++){
        long long x;cin>>x;
        k[i]=x;
        for(int j=1;j<=k[i];j++){
            long long x,y;cin>>x>>y;
            a[x].push_back({i,y});
        }
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            f[i][j]=inf;
    for(int i=1;i<=m;i++){
        for(edge x:a[i]){
            for(edge y:a[i]){
                f[x.to][y.to]=min(f[x.to][y.to],x.t+y.t);
            }
        }
    }
    for(int i=1;i<=n;i++) f[i][i]=0;
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
    for(int i=1;i<=q;i++){
        long long s,e;cin>>s>>e;
        int ans=inf;
        for(edge i:a[s]){
            for(edge o:a[e]){
                int res=i.t+o.t+f[i.to][o.to];
                ans=min(ans,res);
            }
        }
        cout<<(long long)(ans+w[s]+w[e])<<endl;
    }
    return 0;
}