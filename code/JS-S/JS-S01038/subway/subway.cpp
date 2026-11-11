#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define fi first
#define se second
#define mkp make_pair
#define pb push_back
#define y0 y000
#define y1 y111
#define j0 j000
#define j1 j111
typedef long long ll;
typedef unsigned long long ull;
vector<pii >xls[500005];
ll dis[505][505];
int w[500005];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios_base::sync_with_stdio(0);cin.tie(0);
    int c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)cin>>w[i];
    for(int i=0;i<n;i++){
        int k;
        cin>>k;
        while(k--){
            int x,y;
            cin>>x>>y;
            xls[x].pb(mkp(i,y));
        }
    }
    memset(dis,63,sizeof(dis));
    for(int i=0;i<n;i++)dis[i][i]=0;
    for(int i=1;i<=m;i++){
        for(auto j:xls[i])for(auto k:xls[i]){
            int p1=j.fi,p2=k.fi,d1=j.se,d2=k.se;
            if(dis[p1][p2]>d1+d2)dis[p1][p2]=dis[p2][p1]=d1+d2;
        }
    }
    for(int k=0;k<n;k++)for(int i=0;i<n;i++)for(int j=0;j<n;j++)dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
    while(q--){
        int x,y;
        cin>>x>>y;
        ll ans=1000000000000000000;
        for(auto i:xls[x])for(auto j:xls[y])ans=min(ans,dis[i.fi][j.fi]+i.se+j.se);
        cout<<ans+w[x]+w[y]<<'\n';
    }
    return 0;
}
//peimuda bless me
//MatrixGroup bless me
//hyman00 bless me
//UKBwyx bless me
//luckyclover bless me
//He_XY bless me
//daisybunny bless me
//chenmohan bless me
//xuanxuanni bless me
//Tk_hash bless me
//chennie bless me
//placeholder bless me
//Cubber bless me
//rp++