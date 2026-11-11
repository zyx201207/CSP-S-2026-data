#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N = 2e5;
vector<ll>g[N];
ll c,t;
ll n,k;
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> c >> t;
	while(t--)
	{
		cin >> n >> k;
		for(int i  = 1; i< n;i++)
		{
			ll u,v;
			cin >> u >> v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		cout<<n/k<<"\n";
	}
}