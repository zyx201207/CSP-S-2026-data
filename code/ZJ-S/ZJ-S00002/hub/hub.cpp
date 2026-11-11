#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int c;
int t;
vector<int> g[N];
void solve()
{
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		int u,v;
		cin>>u>>v;
		g[u].push_back(v);
	}
	cout<<n/k<<'\n';
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		solve();
	}
	return 0;
}
