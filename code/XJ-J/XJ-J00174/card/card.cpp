#include<bits/stdc++.h>
using namespace std;
int n,m;
int zhan[500005],a[500005],tong[300005],xi,tong2[300005];
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
		memset(tong,0,sizeof(tong));
		memset(zhan,0,sizeof(zhan));
		xi=0;
		
		for(int j=i;j<=n;j++)
		{
			if(tong[a[j]]==0)
			{
				zhan[xi++]=a[j];
				tong[a[j]]++;
			}
			else
			{
			    xi--;
				for(int k=xi;k>=0;k--)
				{
					if(zhan[k]!=a[j])
					{
						tong[zhan[k]]--;
						zhan[k]=0;
						xi--;
					}
					else break;
				}
				xi++;
			}
			
		}
		for(int j=0;j<=xi-1;j++)
		{
			tong2[zhan[j]]++;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<tong2[i]<<" ";
	}
	return 0;
}
