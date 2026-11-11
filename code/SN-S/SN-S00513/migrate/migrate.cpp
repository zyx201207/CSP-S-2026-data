//李雨轩 SN-S00513 陕西延安中学 
#include <iostream>
using namespace std;
long long a[2000005];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin >> c >> t;
	if (c>=11 && c<=12)
	{
		while (t--)
		{
			long long n,d;
			cin >> n >> d;
			for (int i=1;i<=n;i++)
			{
				cin >> a[i];
			}
			long long m=a[2]-a[1];
			if (d<2*m) 
			{
				cout << 0 << endl;
			}
			else if d>(n-1)*m;
			{
				cout << 0 << endl;
			}
			else 
			{
				cout << n-2;
			}
		}
	}
	if (c>=13 && c>=14)
	{
		while (t--)
		{
			long long n,d;
			cin >> n >> d;
			for (int i=1;i<=n;i++)
			{
				cin >> a[i];
			}
			int num=0;
			for (int i=1;i<=n;i++)
			{
				if (a[i]-a[1]<=d && a[n]-a[i]<=d) num++;
			}			
			if (num==2) cout << n*(n-1)/2;
			else cout << 0;
		}
	}
	if (c>=1 && c<=2)
	{
		while (t--)
		{
			long long n,d;
			cin >> n >> d;
			for (int i=1;i<=n;i++)
			{
				cin >> a[i];
			}
		}
		
		
	}
	return 0;
}
