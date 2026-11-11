#include <bits/stdc++.h>
using namespace std;
char c[1000000005],d[1000000005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	cin >> n;
	long long a;
	for(int i = 1;i <= n;i++)
	{
		cin >> a;
		for(int i = 1;i <= a;i++)
		{
			cin >> c[i];
			d[i] = c[i];
		}
    }
	long long l,r,ans = 0;
	bool qmh = false;
	for(int i = 1;i <= n;i++)
	{
		for(int i = 1;i <= a;i++)
		{
			d[i]=!d[i];
			if(d[i] != c[i])
			{
				qmh=false;
				ans++;
			}
			else
			{
				qmh=true;
			}
		}
	}
	if(qmh)
	{
		cout << 0;
	}
	cout << ans;
	return 0;
}
