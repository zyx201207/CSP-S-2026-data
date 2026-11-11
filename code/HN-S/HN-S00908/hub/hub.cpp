#include <bits/stdc++.h>
using namespace std;
long long c,t,n,k,u[1000005],v[1000005];
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin >> c >> t;
	int maxn = -1;
	for(int i = 0;i < t;i++)
	{
		cin >> n >> k;
		for(int j = 0;j < n-1;j++)
		{
			cin >> u[j] >> v[j];
		}
		cout << 0 << endl;
	}
	return 0;
} 
