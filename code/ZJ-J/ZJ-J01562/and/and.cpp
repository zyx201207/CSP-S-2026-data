#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+10;
const int M = 35;
int sz[N][M];
int n,m;
map<int,int>mp;
long long t[N];
long long ans[N];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for(int i = 1;i <= n;i++)
	{
		cin >> t[i];
		long long a;
		a = t[i];
		int res = 0;
		while(a)
		{
			if(a & 1)
			{
				sz[i][++res] = 1;
				mp[res]++;
			}
			else
			{
				sz[i][++res] = 0;
			}
			a >>= 1;
		}
	}
	int op = 0;
	for(int i = 30;i >= 1;i--)
	{
		if(mp[i] >= m)
		{
			op = i;
			break;
		}
	}
	int cnt = 0;
	if(op == 0)
	{
		cout << 0;
	}
	else
	{
		for(int i = 1;i <= n;i++)
		{
			if(sz[i][op] == 1)
			{
				ans[++cnt] = t[i];
			}
		}
	}
	sort(ans+1,ans+cnt+1);
	reverse(ans+1,ans+cnt+1);
	long long sum = ans[1];
	for(int i = 2;i <= m;i++)
	{
		sum  = sum&ans[i];
	}
	cout << sum;
	return 0;
}
