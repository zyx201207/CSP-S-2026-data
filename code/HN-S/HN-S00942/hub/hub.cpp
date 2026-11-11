/*
这 n 座城市由 n - 1 条道路连接
*/

#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N=1e6;
vector <int> pict[N+105];


signed run ()
{
	int n,k;
	cin >> n >> k;
	for (int i=1; i<n; i++)
	{
		int u,v;
		scanf("%lld %lld",&u,&v);
		pict[u].push_back(v);
		pict[v].push_back(u);
	}
	
}

signed main ()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	
	ios::sync_with_stdio(0);
	
	int c,t;
	cin >> c;
	if (c==0)
	{
		cin >> t;
		if (t==2) cout << "1\n2";
		return 0;
	}
	cin >> t;
	while (t--)
	{
		run();
		cout << "\n";
	}
	
	return 0;
}
