#include <bits/stdc++.h>
#define ll long long
#define pll pair<ll,ll>
#define fi first
#define se second
using namespace std;
const ll N=510,M=1010,D=30;
ll c,n,m,d,q,w[M],k,a[N],t[N],x,y,dis[M][M];
void add(ll u,ll v,ll w)
{
	dis[u][v]=min(dis[u][v],w);
	dis[v][u]=min(dis[v][u],w);
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	memset(dis,0x3f3f3f3f,sizeof(dis));
	for (ll i = 1; i <= m; i++) cin >> w[i],dis[i][i]=0;
	for (ll i = 1; i <= n; i++)
	{
		cin >> k;
		for (ll j = 1; j <= k; j++) cin >> a[j] >> t[j];
		for (ll j = 1; j <= k; j++) for (ll kk = j+1; kk <= k; kk++) add(a[j],a[kk],t[j]+t[kk]);
	}
	for (ll i = 1; i <= m; i++)
	for (ll j = 1; j <= m; j++)
	for (ll kk = 1; kk <= m; kk++)
	{
		if (dis[i][j] > dis[i][kk]+dis[kk][j]) dis[i][j]=dis[i][kk]+dis[kk][j];
	}
	for (ll i = 1; i <= q; i++)
	{
		cin >> x >> y;
		cout << dis[x][y]+w[x]+w[y] << endl;
	}
	return 0;
}
// LuoguID: people123
// freopen // freopen // freopen
// 15:30才开始查电子设备没绷住 
// 这什么猎奇题目 
// 不会做 
/*
n 500
m,k 5e5
d 20
q 1e5
w[i] 1e9
t[i][i] 1e9
*/
