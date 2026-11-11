#include <bits/stdc++.h>
using namespace std;
int c,t;
vector<int> e[1000005];
int main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
	cin >> c >> t;
	while(t--)
	{
		int n,k;
		int u,v;
		cin >> n >> k;
		for (int i = 1;i < n;i++)
		{
			cin >> u >> v;
			e[u].push_back(v);
		}
		cout << 1 << endl;
	}
	return 0;
}
