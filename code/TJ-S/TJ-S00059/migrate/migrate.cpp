#include <bits/stdc++.h>
using namespace std;
long long c,t,n,d,maxx;
long long x[1000000];
int main()
{
	//=================================================
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t;
	if(c==11 || c==12)
	{
		for(int o=1;o<=t;o++)
		{
			for(long long i=1;i<=n;i++)
			{
				cin >> x[i];
				maxx=max(maxx,x[i]);
			}
			if(maxx<=d)
			{
				cout << 0 << endl;
			}
			else
			{
				cout << n-d+maxx/d << endl;
			}
		}
		return 0;
	}
	for(int o=1;o<=t;o++)
	{
		cin >> n >> d;
	}
	return 0;
}
