#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int c,t,n,d;
	
	cin>>c>>t;
	for(int i=1;i<=t;i++)
	{
		cin>>n>>d;
		int a[10005];
		for(int j=1;j<=n;j++) cin>>a[j];
		bool f[10005]={0},flag;
		for(int j=1;j<n-2;j++)
		{
			for(int k=j+3;k<=n;k++)
			{
				if(a[k]-a[j]<=d) break;
				flag=0;
				int g=j,gg=0;
				while(1)
				{
					g=upper_bound(a+g,a+k+1,a[g]+d)-a-1;
					if(g==k)
					{
						flag=1;
						break;
					}
					if(g=gg) break;
					f[g]=1;
					gg=g;
				}
				if(!flag) break;
				g=k;
				flag=0;			
				while(1)
				{
					g=lower_bound(a+j,a+g+1,a[g]-d)-a;
					if(g==j)
					{
						flag=1;
						break;
					}
					if(f[g])
					{
						flag=1;
					}
					f[g]=1;
				}				
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
