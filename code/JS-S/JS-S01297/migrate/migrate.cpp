#include <bits/stdc++.h>
using namespace std;
const int N = 2e6 + 5;
long long c,t;
long long a[N],ans;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t;
	while(t --)
	{
		ans = 0;
		long long n,b;
		cin >> n >> b;
		for(int i = 1;i <= n;i ++)
		{
			cin >> a[i];
		}
		if(c == 11 || c == 12)
		{
			if(b < a[2] - a[1])
			{
				cout << 0 << endl;
				continue;
			}
		}
		for(int i = 1;i <= n - 3;i ++)
		{
			if((a[i + 1] - a[i] < b) && (a[i + 2] - a[i + 1] < b) && (a[i + 3] - a[i + 2] < b) && (a[i + 2] - a[i] <= b) && (a[i + 3] - a[i + 1] <= b))
			{
				ans ++;
			}
		}
		cout << ans;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
0 1
4 2
1 2 3 4
*/
