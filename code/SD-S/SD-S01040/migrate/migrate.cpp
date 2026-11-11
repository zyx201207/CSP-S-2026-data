#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e6+2;
int c,t;
int x[maxn];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t;
	while(t--)
	{
		int n,d,ans = 0;
		cin >> n >> d;
		for(int i = 1;i <= n;i++)
			cin >> x[i];
		for(int i = 1;i <= n;i++)
		{
			for(int j = i + 3;j <= n;j++)
			{
				if(j == i + 3 && x[j-1]-x[1] <= d && x[j] - x[j-1] <= d && x[j] - x[i+1] <= d && x[i+1] - x[i] <= d)
					ans++;
			}
		}
		cout << ans << endl;
	}
	return 0;
}
//Oct31==Dec25 
