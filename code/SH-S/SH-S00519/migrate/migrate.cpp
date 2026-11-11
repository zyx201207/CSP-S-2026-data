#include<iostream>
using namespace std;

long long x[2000002];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin >> c >> t;
	while (t--)
	{
		int n,d,num = 0;
		cin >> n >> d;
		for (int i = 1;i <= n;i++) cin >> x[i];
		if (c <= 10)
		{
			for (int i = 1;i <= n;i++)
			{
				bool flag = 0;
				for (int j = i+3;j <= n;j++)
				{
					if (x[j-1]-x[j-3] <= d && x[j]-x[j-2] <= d)
					{
						if (flag) break;
						flag = 1;
					}
					num += flag;
				}
			}
		}
		else if (c <= 12)
		{
			if (d >= 2*(x[2]-x[1])) num = max(0ll,n - 2*(d / (x[2]-x[1])) + 1);
		}
		cout << num << "\n";
	}
	return 0;
}
