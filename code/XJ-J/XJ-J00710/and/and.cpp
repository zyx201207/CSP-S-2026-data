#include<bits/stdc++.h>
using namespace std;
int a[200005];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,i,j,t,ans;
	ans=0;
	cin>>n>>m;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(i=1;i<n;i++)
	{
		for(j=i+1;j<=n;j++)
		{
			int x,y;
			x=a[i];
			y=a[j];
			if((x&&y)>ans)
			{
				ans=(x&&y);
			}
		}
	}
	cout<<ans;
	return 0;
} 
