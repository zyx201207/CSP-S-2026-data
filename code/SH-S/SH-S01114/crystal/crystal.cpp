#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500005];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	bool fg1 = true,fg2 = true;
	for(int i = 1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i = 1;i<=n;i++)
	{
		if(i>2&&a[i]-a[i-1]!=a[i-1]-a[i-2])
		{
			fg2 = false;
		}
	}
	if(fg2)
	{
		long long dif = a[1]-a[0];
		long long i = 0;
		while(m>=i)
		{
			m-=i;
			i+=dif;
		}
		cout<<int(i/dif);
		return 0;
	}

	long long ans = 0;
	for(int i = n;i>=2;i--)
	{
		long long cnt = 0;
		long long j = 1;
		long long x = m;
		while(j<i&&x>=a[i]-a[j])
		{
			x-=a[i]-a[j];
			cnt++;
			j++;
		}
		ans = max(ans,cnt);
	}
	cout<<ans+1;
	return 0;
 } 
