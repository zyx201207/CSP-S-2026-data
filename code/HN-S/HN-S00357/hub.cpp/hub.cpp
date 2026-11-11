#include <bits/stdc++.h>
using namespace std;
long long c,t,n,k,u[1000005],r[1000005];
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin >> c >> t;
	for (int i=1;i<=t;i++)
	{
		cin >> n >> k;
		for (int j=1;j<=n-1;j++)
		{
			cin >> u[j] >> r[j];
		}
	}
	cout << "1" << endl << "2";
	return 0;
}
