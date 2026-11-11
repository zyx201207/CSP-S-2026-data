#include <bits/stdc++.h>
using namespace std;
int n,d,a[2000005];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	freopen("migrate.in","w",stdin);
	freopen("migrate.out","r",stdout);
	int c,t;
	cin >> c >> t;
	while(t--)
	{
		memset(a,0,sizeof(a));
		cin >> n >> d;
		for(int i = 1;i <= n;i++)
		{
			cin >> a[i];
		}
		int num = a[2] - a[1];
		if(num >= d)
		{
			cout << 0 << endl;
		}
		else
		{
			cout << n - (d / num) * 2 + 1 << endl;
		} 
	}
	return 0;
} 
