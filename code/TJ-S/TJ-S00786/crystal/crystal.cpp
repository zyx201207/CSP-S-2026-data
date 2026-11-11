#include <bits/stdc++.h>
using namespace std;
int a[10000005],ans,s;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m,q;
	cin >> n >> m;
	if(n%2==1)
	{
		q=n/2+1;
	}
	else
	{
		q=n/2;
	}
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		if(a[i]<=a[q])
		{
			ans+=a[q]-a[i];
			s++;
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(ans<=m)
		{
			cout << s;
			break;
		}
		else
		{
			s--;
			ans-=a[q]-a[i];
		}
	}
	return 0;
} 
