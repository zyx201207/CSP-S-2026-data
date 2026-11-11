#include<bits/stdc++.h>
using namespace std;
const int N = 6e5 + 10,K = 550;
typedef long long LL;
LL w[N];
vector<pair<LL,LL>> a[N];
LL dis[N];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int id,n,m,d,q;
	cin>>n>>m>>d>>q;
	for(int i = 1; i <= m; i ++) cin>>w[i];
	for(int i = 1,k,x,y; i <= n; i ++)
	{
		cin>>k;
		while(k --) cin>>x>>y,a[i].push_back({x,y}),add(i,x + n,y),add(x + n,i,y);
	}
	while(q --)
	{
		int x,y;
		cin>>x>>y;
		LL res = w[x] + w[y];
		dij
	}
	return 0;
}
//station-t->line
//line-t->station
//line-line
//w_x+w_y+stationx->stationy
