#include <bits/stdc++.h>
using namespace std;
const long long N = 5e5+5;
long long a[N];
long long s[N];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	long long n=0,m=0;
	cin >> n >> m;
	s[0] = 0;
	bool flag = true;
	for (long long i = 1;i <= n;i++)
	{
		cin >> a[i];
		if (a[i] != i)
		{
			flag = false;
		}
	}
	if (flag)
	{	
		int ma = 0;
		for(int i = 1;i <= n;i++)
		{
			if ((i * (i-1)) / 2 <= m)
			{
				ma = i;
			}
			else
			{
				break;
			}
		} 
		cout << ma;
		return 0;
	}
	sort(a+1,a+n+1);
	for (int i = 1;i <= n;i++)
	{
		s[i] = s[i-1] + a[i];
	}
	long long maxx = 0;
	long long ans = 0;
	for (long long i = 1;i <= n;i++)
	{
		long long sum = 0;
		int j;
		for (j = i;j >= 1;j--)
		{
			if (m >= sum)
			{
				sum += abs(a[i] - a[j]); 
			}
			else{
				j++;
				break;	
			}
		}
		maxx = max(maxx,i-j);
	}
	cout << maxx;
	return 0;
}


