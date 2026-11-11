#include <bits/stdc++.h>
using namespace std;
const int N=5e5+5;
long long a[N];
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin >> n >> m;
	bool flag1=1,flag2=1;
	int cha; 
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
		if(a[i]!=i)
		{
			flag1=0;
		}
		if(i>=2&&abs(a[i]-a[i-1])!=abs(a[i-1]-a[i-2]))
		{
			flag2=0;
		}
	}
	sort(a+1,a+n+1);
	if(flag2)
	{
		cha=a[2]-a[1];
		int ans=1;
		for(int i=1;i<=n;i++)
		{
			if(m>=i*cha)
			{
				ans++;
				m-=i*cha; 
			}
		}
		cout << ans;
		return 0;		
	}
	int ans=0;
	for(int i=n;i>=2;i--)
	{
		long long zhi=m;
		int cnt=1;
		for(int j=i-1;j>=1;j--)
		{
			if(zhi>=a[i]-a[j])
			{
				cnt++;
				zhi=zhi-(a[i]-a[j]);				
			}
		}
		ans=max(ans,cnt);
	}
	cout << ans;
	return 0;
}