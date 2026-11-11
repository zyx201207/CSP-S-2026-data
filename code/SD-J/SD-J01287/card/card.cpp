#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],ans[500005],x[500005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		memset(x,0,sizeof(x));
		bool p[500005];
		for(int j=i;j<=n;j++)p[j]=1;
		for(int j=i;j<=n;j++)
		{
			if(x[a[j]]!=0)
			{
				for(int k=x[a[j]];k<j;k++)p[k]=0,x[a[k]]=0;
				x[a[j]]=j;
	
			}
			else x[a[j]]=j;
		}
		for(int j=i;j<=n;j++){
			if(p[j])ans[a[j]]++;
		}
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<' ';
} 
