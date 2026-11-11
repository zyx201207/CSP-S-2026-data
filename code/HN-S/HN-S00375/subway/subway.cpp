#include<bits/stdc++.h>
#define fi first
#define se second
#define ll long long
using namespace std;
const int N=505,M=5e5+5,Q=1e5+5;//N=线路数,M=地铁站数量
inline void rd(int &x){
    char c=getchar_unlocked();x=0;
    while(c<'0'||c>'9')c=getchar_unlocked();
    while(c>='0'&&c<='9')
        x=x*10+c-'0',c=getchar_unlocked();
}
void write(ll x){
    if(x>9)write(x/10);
    putchar(x%10+'0');
}
int n,m,d,q;
int w[M];
vector<pair<int,int>>ve[M];
ll g[N][N];
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int Cid;rd(Cid),rd(n),rd(m),rd(d),rd(q);
    for(int i=1;i<=m;i++)rd(w[i]);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if(i!=j)g[i][j]=1e18;
    for(int i=1;i<=n;i++){
        int k;rd(k);
        for(int j=1,x,y;j<=k;j++)
            rd(x),rd(y),ve[x].push_back({i,y});
    }
    for(int i=1;i<=m;i++)
        for(int j=0;j<(int)ve[i].size();j++)
            for(int l=j+1;l<(int)ve[i].size();l++){
                int x=ve[i][j].fi,y=ve[i][l].fi;
                ll  w=ve[i][j].se  +ve[i][l].se;
                g[x][y]=min(g[x][y],w);
                g[y][x]=min(g[y][x],w);
            }
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                g[i][j]=min(g[i][k]+g[k][j],g[i][j]);
    for(int i=1;i<=q;i++){
        int x,y;rd(x),rd(y);
        ll ans=1e18;
        for(auto j:ve[x])
            for(auto l:ve[y])
                ans=min(ans,g[j.fi][l.fi]+j.se+l.se);
        write(ans+w[x]+w[y]),puts("");
    }
}
/*
by GCSG01

take about 1h for writing.

and check code without run.

done 16:12
*/