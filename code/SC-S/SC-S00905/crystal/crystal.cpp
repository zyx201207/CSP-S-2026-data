#include <bits/stdc++.h>
using namespace std;

long long n,m,a[500005],x,mx = -1e18,y;

int main()
{	
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++)	
		cin >> a[i];
	
	if(n == 1)
	{
		cout << 1;
		return 0;	
	}	
		
	sort(a + 1,a + n + 1);	
		
	bool f = true,f2 = true,f3 = true;
	x = a[1]; 
	y = a[2] - a[1];
	for(int i = 2;i <= n;i++)
	{
		if(a[i] != x)
			f = false;
		x = a[i];
		
		if(a[i] != i)
			f2 = false;
		
		if(a[i] - a[i - 1] != y)
			f3 = false;
	}
	if(f)
	{
		cout << n;
		return 0;
	}
	
	if(f2)
	{
		long long sum = 0,mm = m,i = 1,cc = 0;
		while(mm - sum >= 0)
		{
			sum += i;
			i++;
			cc++;
			if(cc == n)
				break;
		}
		cout << cc;
		return 0;
	}
	
	if(f3)
	{
		long long sum = 0,mm = m,i = 1,cc = 0;
		while(mm - sum >= 0)
		{
			sum += (i * y);
			i++;
			cc++;
			if(cc == n)
				break;
		}
		cout << cc;
		return 0;
	}
	
	for(int i = 1;i <= n;i++)
	{
		long long cnt = 1,c = m;
		for(int j = i - 1;j >= 1;j--)
		{
			if(a[i] - a[j] > c)
				break;
			cnt++;
			c -= (a[i] - a[j]);
		}
		mx = max(mx,cnt);
	}
	
	cout << mx;
	return 0;
} 