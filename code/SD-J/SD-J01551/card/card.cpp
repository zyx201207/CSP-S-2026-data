#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005],pos=0,f=0,sum[500005];
int b[500005],vis[500005],visi[500005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		pos=0;
		f=0;
		for(int j=1;j<=n+m+10;j++)
		{
			b[j]=0;
			vis[j]=0;
			visi[j]=0;
		}
		for(int j=i;j<=n;j++)
		{
			if(vis[a[j]]==0)
			{
				b[++pos]=a[j];
				vis[a[j]]=1;
				visi[a[j]]=pos;
			}
			else
			{
				for(int k=visi[j];k<=n;k++)
				{
					b[k]=-1;
					vis[b[k]]=0;
					visi[b[k]]=0;
				}
				b[++pos]=a[j];
				visi[a[j]]=pos;
			}
		}
		for(int j=1;j<=pos;j++)
		{
			for(int k=1;k<=n;k++)
			{
				if(b[j]==k)
				{
					sum[k]++;
				}
			}
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<sum[i]<<" ";
	}
	return 0;
}

