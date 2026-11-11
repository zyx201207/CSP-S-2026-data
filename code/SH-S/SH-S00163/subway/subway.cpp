#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=509;
const ll M=5e5+9;
ll c,n,m,d,q,w[N],g[N][N];
vector<ll> to[M],v[M];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    scanf("%lld %lld %lld %lld %lld",&c,&n,&m,&d,&q);
    for(ll i=1;i<=m;i++) scanf("%lld",w+i);
    for(ll i=1,k;i<=n;i++){
	scanf("%lld",&k);
	for(ll j=1,a,t;j<=k;j++)
	    scanf("%lld %lld",&a,&t),to[a].push_back(i),v[a].push_back(t);
    }
    memset(g,0x3f,sizeof(g));
    for(ll i=1;i<=n;i++) g[i][i]=0;
    for(ll i=1;i<=m;i++)
	for(ll j=0;j<to[i].size();j++)
	    for(ll k=j+1;k<to[i].size();k++)
		g[to[i][j]][to[i][k]]=min(g[to[i][j]][to[i][k]],v[i][j]+v[i][k]);
    for(ll i=1;i<=n;i++)
	for(ll j=i+1;j<=n;j++)
	    g[j][i]=g[i][j];
    for(ll k=1;k<=n;k++)
	for(ll i=1;i<=n;i++)
	    for(ll j=1;j<=n;j++)
		g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
    for(ll i=1,x,y;i<=q;i++){
	scanf("%lld %lld",&x,&y);
	ll ans=1e18;
	for(ll a=0;a<to[x].size();a++)
	    for(ll b=0;b<to[y].size();b++)
		ans=min(ans,v[x][a]+v[y][b]+g[to[x][a]][to[y][b]]);
	printf("%lld\n",ans+w[x]+w[y]);
    }
    return 0;
}
