#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
const int M=3e5+5;
int n,m;
int a[N],vis[M],c[N],xzh[N],x=1,sb,sd,ll[M],ccc;
int main()
{
//	freopen("card.in","r",stdin);
//	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		if(i==n)
		{
			ccc=a[i];
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			xzh[j]=a[j];
			if(vis[xzh[j]]==0)
		    {
			    vis[xzh[j]]++;
			    c[xzh[j]]=j;
		    }
			else if(vis[xzh[j]]==1)
			{
				vis[xzh[j]]++;
			}
			if(vis[xzh[j]]==2)
			{
				sb=c[xzh[j]]+1;
				sd=j-1;
				for(int k=sb;k<=sd;k++)
				{
					vis[xzh[k]]=0;
				}
				vis[xzh[j]]=1;
			}
		}
		for(int j=i;j<=m;j++)
		{
			if(vis[xzh[j]])
			{
				ll[xzh[j]]++;
			}
		}
	}
	for(int i=1;i<=m;i++)
    {
    	if(ccc==i)
    	{
    		cout<<n<<" ";
		}
		else
		{
			cout<<ll[i]<<" ";
		}
		
	}
	return 0;
}

