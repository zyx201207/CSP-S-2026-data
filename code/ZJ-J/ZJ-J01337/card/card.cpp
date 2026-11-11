#include<bits/stdc++.h>
using namespace std;
int n,m,a[600005],q[600005],c[600005],ans[600005],d[600005],cnt;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		cnt=0;
		for(int j=1;j<=m;j++)
		{
			c[j]=0;
			d[j]=0;
		}
		for(int j=i;j<=n;j++)
		{
			if(!c[a[j]])
			{
				q[++cnt]=a[j];
				c[a[j]]=cnt;
			}
			else 
			{
				for(int k=c[a[j]]+1;k<=cnt;k++) c[q[k]]=0;
				cnt=c[a[j]];
			}
		}
		for(int j=1;j<=cnt;j++) d[q[j]]=1;
		for(int j=1;j<=m;j++) ans[j]+=d[j];
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
	return 0;
}