#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,m,ans=0;
	int a[100001];
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	if(m==1)
	{
		for(int i=0;i<n;i++)
		{
			ans=max(a[i],ans);
		}
		cout<<ans;
		return 0;
	} 
	if(m==2)
	{
		for(int i=0;i<n;i++)
		{
			for(int j=i+1;j<n;j++)
			{
				ans=max(ans,a[i]&a[j]);
			}
		}
		cout<<ans;
		return 0;
	}
	cout<<n+m;
	return 0;
} 
