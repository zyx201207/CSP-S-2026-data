#include<bits/stdc++.h>
using namespace std;
int n,m;
long long int a[200005];
int ans=0;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
	}
	if(m==2)
	{
	
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			if((a[i] and a[j]) > ans)
			{
				ans = a[i] and a[j];
			}
		}
	}
	cout << ans;
	return 0;
}
else if(m==1)
{
	for(int i=1;i<=n;i++)
	{
		
		
			if((a[i] and a[i]) > ans)
			{
				ans = a[i] and a[i];
			}
	}
	cout << ans;
	return 0;
}
else if(m==n)
{
	ans = a[1];
	for(int i=2;i<=n;i++)
	{
		ans = ans and a[i];
	}
	cout << ans;
	return 0;
}
	return 0;
}