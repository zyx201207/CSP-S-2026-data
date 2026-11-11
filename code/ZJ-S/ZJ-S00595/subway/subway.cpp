#include <bits/stdc++.h>
using namespace std;
#define int long long
const int M=5e5+5;
int c,n,m,d,q,a[M],k[505],ksum,sum,x[M],y[M],u,v,f[M],e[M];
vector<pair<int,int> > b[M];
priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > pq;
int dij(int t,int w){
	while (pq.size()) pq.pop();
	for (int i=1;i<=m;i++) f[i]=2e9,e[i]=0;
	f[t]=0;e[t]=1;pq.push({0,t});
	int fa,son,shijian;
	while (pq.size())
	{
		fa=pq.top().second;pq.pop();e[fa]=0;
		for (int i=0;i<b[fa].size();i++)
		{
			son=b[fa][i].first;shijian=b[fa][i].second;
			if (f[fa]+shijian<f[son])
			{
				f[son]=f[fa]+shijian;
				if (e[son]==0) e[son]=1,pq.push({f[son],son});
			}
		}
	}
	return f[w];
}
signed main(){
	ios::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for (int i=1;i<=m;i++) cin>>a[i];
	for (int i=1;i<=n;i++)
	{
		cin>>k[i];sum+=k[i];
		for (int j=1;j<=k[i];j++) cin>>x[j]>>y[j];
		for (int j=1;j<=k[i];j++)
			for (int jj=j+1;jj<=k[i];jj++)
				b[x[j]].push_back({x[jj],y[j]+y[jj]}),
				b[x[jj]].push_back({x[j],y[j]+y[jj]});
	}
	while (q--)
	{
		cin>>u>>v;
		cout<<dij(u,v)+a[u]+a[v]<<"\n";
	}
	return 0;
}
