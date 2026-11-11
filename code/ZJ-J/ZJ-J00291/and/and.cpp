#include<bits/stdc++.h>
using namespace std;
int n,m,ans;
int a[200005];
bool b[200005];
int f(int st,int ll)
{
	int maxs=0;
	for(int i=st;i<=n;i++)
	{
		if(ll==2)
		{
			for(int j=i+1;j<=n;j++)
			{
				maxs=max(maxs,a[j]&a[i]);
			}
		}
		else
		{
			int ff=f(i+1,ll-1);
			maxs=max(maxs,ff&a[i]);
		}
	}
	return maxs;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	ans=f(1,m);
	printf("%d",ans);
	return 0;
}