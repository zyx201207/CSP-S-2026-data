#include<bits/stdc++.h>
#define pll pair<ll,ll>
#define mkp make_pair
#define fi first
#define se second
using namespace std;
typedef long long ll;
const ll N=509,M=5e5+9,D=21;
const ll INF=1e18;
/*
the number of metro is small
but the number of node is big
we've got a lot of queries
maybe we can decide which metro we go to, and which metro we come from
this is O(d^2)
acceptable
now we need to calculate the distance between to metro
use every station to update the dist between to metro
O(md^2)
OK
and do a O(n^3)
NP!
need careful coding
*/
ll cid,n,m,d,Q;
ll w[M];
ll to[M][D],t[M][D];
ll dst[N][N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>cid>>n>>m>>d>>Q;
	for(ll i=1;i<=m;i++) cin>>w[i];
	for(ll i=1;i<=n;i++){
		ll k;
		cin>>k;
		for(ll j=1;j<=k;j++){
			ll x,y;
			cin>>x>>y;
			to[x][++to[x][0]]=i;
			t[x][to[x][0]]=y;
		}
	}
	memset(dst,0x3f,sizeof(dst));
	for(ll i=1;i<=n;i++) dst[i][i]=0;
	for(int i=1;i<=m;i++){
		ll sz=to[i][0];
		ll *now=to[i];
		for(int j=1;j<=sz;j++){
			ll u=now[j];
			for(int k=1;k<=sz;k++){
				ll v=now[k];
				dst[u][v]=min(dst[u][v],t[i][j]+t[i][k]);
			}
		}
	}
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++) dst[i][j]=min(dst[i][j],dst[i][k]+dst[k][j]);
	for(int _=1;_<=Q;_++){
		ll x,y;
		cin>>x>>y;
		ll res=INF;
		ll szx=to[x][0],szy=to[y][0];
		for(int i=1;i<=szx;i++)
			for(int j=1;j<=szy;j++) res=min(res,t[x][i]+dst[to[x][i]][to[y][j]]+t[y][j]);
		cout<<res+w[x]+w[y]<<'\n';
	}
	return 0;
}
