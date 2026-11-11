#include<bits/stdc++.h>
using namespace std;
int ca[500010];
int ans[300010];
int zt[300010];
int you[300010];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout); 
	int n,m;
	cin>>n>>m;
	int z=0;
	for(int i=1;i<=n;i++)
		cin>>ca[i];
	for(int i=1;i<=n;i++)
	{
		z=0;
		for(int j=i;j<=n;j++)
		{
			if(zt[ca[j]]==0)
				zt[ca[j]]=1;				
			else
				if(zt[ca[j]]==1)
				{
					for(int u=1;u<=n;u++)
					{
						if(zt[ca[u]]==1)
							zt[ca[u]]=0;
					}
					zt[ca[j]]=2;
					you[z]=ca[j];
					z++;						
				}
				else
				{
					int lz=z;
					bool x=false;
					for(int u=0;u<z;u++)
					{
						if(x==true)
							zt[you[u]]=0;
						if(you[u]==ca[j])
						{
							lz=u+1;
							x=true;
						}		
					}
					z=lz;
				}
		}
		for(int j=1;j<=n;j++)
		{
			if(zt[ca[j]]!=0)
			{
				ans[ca[j]]++;
				zt[ca[j]]=0;
			}
		}
	}	
	for(int i=1;i<=m;i++)
		cout<<ans[i]<<" ";
	return 0;
}
