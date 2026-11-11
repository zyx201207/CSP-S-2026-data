#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+5;
int c,t,n,k;
vector<int>g[N];
inline void solve()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++)g[i].clear();
	for(int i=1;i<n;i++)
	{
		int u,v;
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	int K=1;
	while((1<<K)<k)K++;
	cout<<K;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		solve();
	}
	return 0;
}