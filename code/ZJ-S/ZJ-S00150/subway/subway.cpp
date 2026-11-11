#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<ll,ll> 
#define fi first
#define se second
#define pb push_back
const ll N=1e6+10,M=550,inf=1e18;
ll c,n,m,d,q,k,w[N],xx,yy,p[M][M];
vector<pii> e[N];
void add(ll x,ll y,ll z){
    e[x].pb({y,z});
    e[y].pb({x,z});
}
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    // ll st=clock();
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++) cin>>w[i];
    for(int i=1;i<=n;i++){
        cin>>k;
        for(int j=1;j<=k;j++) cin>>xx>>yy,add(xx,m+i,yy);
    }
    memset(p,0x3f,sizeof p);
    for(int i=1;i<=m;i++){
        for(auto pp:e[i]){
            ll y=pp.fi-m;
            for(auto qq:e[i]){
                ll z=qq.fi-m;
                p[y][z]=min(p[y][z],pp.se+qq.se);
            }
        }
    }
    for(int i=1;i<=n;i++) p[i][i]=0;
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                p[i][j]=min(p[i][j],p[i][k]+p[k][j]);
    for(int i=1;i<=q;i++){
        cin>>xx>>yy;
        if(xx>yy) swap(xx,yy);
        ll res=1e18;
        for(auto pp:e[xx]){
            ll y=pp.fi-m;
            for(auto qq:e[yy]){
                ll z=qq.fi-m;
                res=min(res,p[y][z]+w[xx]+w[yy]+pp.se+qq.se);
            }
        }
        cout<<res<<"\n";
    }
    // ll ed=clock();cerr<<(double)(ed-st)/CLOCKS_PER_SEC;
    return 0;
}