#include<bits/stdc++.h>
using namespace std;
const long long MAXN=5e5+5;
int n,m;
int a[MAXN];
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	int mi=1e9,mii=0;
	for(int i=1;i<=m;i++)
	{
		for(int i=1;i<=n;i++)
		{
			if(a[i]<mi)
			{
				mi=a[i];
				mii=i;
			}
				
		}
		a[mii]++;
		mi=1e9;
	}
	sort(a+1,a+n+1);
	int ans=1;
	for(int i=1;i<=n;i++)
	{
		if(a[i]==a[i-1])
			ans++;
	}
	cout<<ans;
	return 0;
}
