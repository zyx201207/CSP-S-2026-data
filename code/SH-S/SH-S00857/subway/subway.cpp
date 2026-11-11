#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct edge{
	ll typ,u,v;//typ=几号线 u、v=从哪到哪 
};
ll c,n,m,d,q,w[500010],k[510],a[50010][510],t[50010][510],x,y;
int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for (ll i=1;i<=m;i++) cin>>w[i];
	for (ll i=1;i<=n;i++) {
		cin>>k[i];
		for (ll j=1;j<=k[i];j++) cin>>a[i][j]>>t[i][j];
	}
	while (q--) {
		cin>>x>>y;
		ll ans=0;
		ans=w[x]+w[y];
		cout<<ans<<'\n';
	}
	return 0;
}
/*
1.首先加上两个地铁站从地铁口到站台的时间
2.从u号线到v号线的站内换乘：
 
*/
