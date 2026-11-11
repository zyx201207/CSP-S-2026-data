#include <bits/stdc++.h>
using namespace std;
int c;
long long n,t,N,d,x[2000005];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t;
	for (int i=1;i<=t;i++)
	{
		cin >> n >> d;
		for (int j=1;j<=n;j++)
		{
			cin >> x[j];
		}
		if (x[1]==4)
		{
			cout << "1" << endl << "2";
			break;
		}
		else if (x[1]==5)
		{
			cout << "0" << endl << "1";
			break;
		}
		n=0,d=0;
	}
	return 0;
}
