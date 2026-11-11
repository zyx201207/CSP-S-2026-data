#include<bits/stdc++.h>
using namespace std;
#define int long long
#define llg long long
#define sig signed
#define usg unsigned
#define ull unsigned long long
const int inf=1ll<<60;
inline void ckmin(int &x,const int &y){
    if(x>y)x=y;
}
int c,n,m,d,q;
int w[500005];
vector<int>bl[500005],tt[500005];
int g[505][505];
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=n;++i)for(int j=1;j<=n;++j)g[i][j]=inf;
    for(int i=1;i<=n;++i)g[i][i]=0;
    for(int i=1;i<=m;++i)cin>>w[i];
    for(int i=1;i<=n;++i){
        int k,x,y;
        cin>>k;
        while(k--){
            cin>>x>>y;
            for(int j=0;j<bl[x].size();++j){
                int t1=bl[x][j],t2=tt[x][j];
                ckmin(g[t1][i],t2+y);
                ckmin(g[i][t1],t2+y);
            }
            bl[x].push_back(i);
            tt[x].push_back(y);
        }
    }
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            for(int k=1;k<=n;++k){
                ckmin(g[j][k],g[j][i]+g[i][k]);
            }
        }
    }
    while(q--){
        int x,y;
        cin>>x>>y;
        int ans=inf;
        if(x==y)ans=0;
        for(int i=0;i<bl[x].size();++i){
            int b1=bl[x][i],t1=tt[x][i];
            for(int j=0;j<bl[y].size();++j){
                int b2=bl[y][j],t2=tt[y][j];
                ckmin(ans,g[b1][b2]+t1+t2+w[x]+w[y]);
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
// /home/user/Desktop/JS-S01268/subway/subway
