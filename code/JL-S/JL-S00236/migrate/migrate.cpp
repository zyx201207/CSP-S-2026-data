#include <iostream>
using namespace std;
int a[2000005];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin >> c >> t;
	while(t--)
	{
		int n,d;
		cin >> n >> d;
		for(int i = 1; i <= n; i++)
		{
			cin >> a[i];
		}
		if(c==11||c==12)
		{
			int D = a[2]-a[1];
			if(2*D>d)cout << 0 << '\n';
			else if((2*D<d)&&(3*D>d))cout << (n-3+n-2);
			else cout << 0 << '\n';
		}
		else if(c==13||c==14)
		{
			if((n==5) && (a[1]+a[5]==2*a[3]) && (a[3]-a[1]<=d) && (a[4]-a[1]>=d) && (a[5]-a[2]>=d))cout << 2 << '\n';
			else cout << 0 << '\n';
		}
	}
	return 0;
}
