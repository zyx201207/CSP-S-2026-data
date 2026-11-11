#include<bits/stdc++.h>
using namespace std;
long long ans[500001],j,i,l=0,q,mn[500001],n,m,a[500001];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n;i++)
	cin>>a[i];
	for(i=1;i<=n;i++)
	{
		l=0;
		for(j=i;j<=n;j++)
		{
			bool s=true;
			for(q=1;q<=l;q++)
			{
				if(mn[q]==a[j])
				{
					l=q;
					s=false;
					break;
				}
			}
			if(s)
			{
				mn[++l]=a[j];
			}
		}
		for(j=1;j<=l;j++)
		{
			ans[mn[j]]++;
		}
	}
	for(i=1;i<=m;i++)
	{
		cout<<ans[i]<<' ';
	}
	return 0;
}
