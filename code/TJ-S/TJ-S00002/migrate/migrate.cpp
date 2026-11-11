#include<bits/stdc++.h>
using namespace std;
long long x[100000000],r[10000000];
int s,t,n,d,f;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrrate.out","w",stdout);
	cin>>s>>t;
	for(int i=1;i<=t;i++)
	{
		cin>>n>>d;
		for(int j=1;j<=n;j++)
		{
			cin>>x[j];
		}
		for(int j=1;j<=n;j++)
		{
			int u=j+1;
			while(x[u]-x[j]<d)
			{
				u++;
				
			}
			r[j]=u-j;
			
		}
		for(int p=1;p<n;p++)
		{
			
			for(int k=p+1;k<=n;k++)
			{
				int y=0;
				for(int z=k;z<=k;z++)
				{
				
					if(y<r[z])
					{
						y=r[k];
					}
				}
				int o=0;
				for(int z=y;z>=1;z--)
				{
					int q;
					for(int a=p;a<=k;a++)
					{
						if(r[a]==z)
						{
							o++;
							q=a;
						}
						
					}
					if(o>2)
					{
						break;
					}
					else if(o==2)
					{
						f++;
						break;
					}
					else if(o==1)
					{
						for(int v=q;v<=k-z;v++)
						{
							r[v]=r[v+z];
						}
						
					}
				}
			}
			
		} 
	} 
	cout<<f;
	return 0;
}

