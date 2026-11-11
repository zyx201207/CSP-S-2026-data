#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,a[500010],l,r,t,cnt = 0;
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	l = n/2+1;
	r = l;
	t = l;
	long long len = min(a[r]-a[r-1],a[t+1]-a[t]);
	while(m > 0)
	{
	if(len + a[r-1] == a[r])
	{
		r--;
		a[r-1] = a[r-1]+len;
		m = m-len;
		len = min(a[r]-a[r-1],a[t+1]-a[t]);
	}
	else
	{
		t++;
		a[t+1] = a[t+1]-len;
		 m = m - len;
		 len = min(a[r]-a[r-1],a[t+1]-a[t]);
	}
	}
	for(int i = 1; i <= n; i++)
	{
		if(a[i] == a[l])
		{
			cnt++;
		}
	}
	cout << cnt;
	return 0;
 } 
