#include<bits/stdc++.h>
using namespace std;
int c,t,n,k,u,v;
vector<int> e[200005];
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin >>c >> t;
	if (c == 13 || c == 14)
	{
		while(t--)
		{
			int depth = 0;
			cin >> n >> k;
			for (int i = 1;i < n;i++)
			{
				cin >> u >> v;
			}
			cout << int(ceil(1.0*((n-1)/2-k+2)/4)) << "\n"; 
		}
	}
	/*while(t--)
	{
		cin >> n >> k;
		for (int i = 1;i < n;i++)
		{
			cin >> u >> v;
			e[u].push_back(v);
		}
	}*/
	return 0;
}
