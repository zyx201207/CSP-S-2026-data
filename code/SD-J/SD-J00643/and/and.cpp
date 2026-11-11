#include <bits/stdc++.h>
using namespace std;
int m,n;
int a[100005];
int maxx=-1,ans=-1;
int main()
{
	freopen("and.in" , "r" , stdin);
	freopen("and.out" , "w" , stdout);										
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		maxx=max(maxx,a[i]);
	}
	if(m==1)
	{
		cout<<maxx;
		return 0;
	}
	if(n<=2000&&m==2)
	{
		for(int i=1;i<=n;i++)
			for(int j=1;j<=i;j++)
			{
				ans=max(ans,a[i]&a[j]);
			}
		cout<<ans;
		return 0;
	}
	return 0;
}
