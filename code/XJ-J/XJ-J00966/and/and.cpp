#include<bits/stdc++.h>
using namespace std;

int n,m;
long long a[200005],ans;

int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]; 
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			long long ans1=a[i];
			for(int p=0;p<=m-2;p++)
			{
				ans1&=a[j+p];
			}
			ans=max(ans,ans1);
		} 
	} 
	
	cout<<ans;
	return 0;
}
