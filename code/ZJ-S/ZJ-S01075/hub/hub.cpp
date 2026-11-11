#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c, T;
	cin >> c >> T;
	while(T--)
	{
		int n, m;
		cin >> n >> m;
		for(int i = 1, u, v; i < n; i++)
			cin >> u >> v;
		int cnt = 0;
		while(n)
			cnt++, n /= 2;
		cout << cnt << "\n";
	}
	return 0;
}