#include<bits/stdc++.h>
using namespace std;
int n,m,a[200009],i,ans;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(i=1;i<=n-m+1;i++)
	{
		int t=a[i];
		for(int j=i;j<=i+m-1;j++)
		{
			t&=a[j];
		}
		ans=max(t,ans);
	}
	cout<<ans;
	return 0;
} 
