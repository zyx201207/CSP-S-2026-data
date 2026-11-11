#include <bits/stdc++.h>
using namespace std;
	int n;
	int m;
	long long a[10010];
	long long ans;
void t(int k,long long w,int p)
{
	if(k == m)
	{
		ans = max(ans, w);
		return;
	}
	for(int i = p + 1;i <= n - m + 2;i++)
	{
		t(k + 1,w & a[i],i);
	}
}

int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);

	cin >> n >> m;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	for(int i = 1;i <= n - 1;i++)
	{
	    long long ma = -1;
		int s;
		for(int j = i;j <= n;j++)
		{
			if(a[j] > ma)
			{
				ma = a[j];
				s = j;
			}
		}
		a[s] = a[i];
		a[i] = ma;
	} 
	ans = -1;
	for(int i = 1;i <= n - m + 1;i++)
	{
	    t(1,a[i],i);
	}
	cout << ans;
	return 0;
 } 
