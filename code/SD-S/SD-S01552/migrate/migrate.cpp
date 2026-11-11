#include <bits/stdc++.h>
using namespace std;
long long c,t,n,d,f=1,cnt;
long long x[2000005],b[2000005],s;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t;
	for(int i = 1;i<=t;i++)
	{
		cin >> n >> d;
		for(int j = 1;j<=n;j++)
		{
			cin >> x[j];
			b[j] = x[j] - x[j-1];
			if(j>=3&&b[j]!=b[j-1]) f = 0;
		}
		if(f)
		{
			t = b[2];
			if(!(2*t<=d&&d<3*t))
			{
				cout << 0 << endl;
			}
			else
			{
				cout << n-3 << endl;
			}
		}
		else cout << 0 << endl;
	}
	return 0;
}
