#include <bits/stdc++.h>
using namespace std;
long long a[500005];
long long maxn = 0,n,m,ans,pos;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	bool b = 1;
	for(int i = 1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i = n;i>=1;i--)
	{
		if((a[i] - a[i-1]) != (a[2]-a[1]))
		{
			b = 0;
		}
	}
	if(b == 1)
	{
		for(int i = 1;i<=n;i++)
		{
			if(ans + a[i] <= m)
			{
				ans += a[i];
				pos++;
			}
			else 
			{
				cout<<pos+1<<endl;
				return 0;
			}
		}
	}
	else
	{
		sort(a+1,a+n+1);
		for(int i = n;i>=1;i--)
		{
			ans = 0,pos = 0;
			for(int j = 1;j<i;j++)
			{
				ans+=a[i]-a[j];
				pos++;
				if(ans>m)
				{
					maxn = max(maxn,pos-1);
				}
				else
				{
					maxn = max(maxn,pos+1);
				}
			}
		}
		cout<<maxn<<endl;
	}
	return 0;
}
