#include<bits/stdc++.h>
using namespace std;
long long a[200010],ans=-1;
int n,m;
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
			long long x=a[i]&a[j];
			ans=max(ans,x);
		}
	}
	
	cout<<ans;
	return 0;
}