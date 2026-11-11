#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int a[N],ans[N],x[N];

int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(m==1)
	{
		cout<<n;
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		int k=0;
		for(int j=i;j<=n;j++)
		{
			if(x[a[j]]==0)x[a[j]]=++k;
			else
			{
				k=x[a[j]];
				for(int l=1;l<=m;l++)
				{
					if(x[l]>k)x[l]=0;
				}
			}
		}
		for(int j=1;j<=m;j++)
		{
			if(x[j])ans[j]++;
			x[j]=0;
		}
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<' ';	
	return 0;
}
