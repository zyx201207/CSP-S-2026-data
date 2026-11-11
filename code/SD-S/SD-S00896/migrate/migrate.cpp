#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
int c,t,n,d;
int x[666666];
int vis[666666],ans=1e8;
int dfs(int a,int b,int d)
{
	int i=a+1;
	while(x[i]-x[a]<=d)
	{
		if(ans>dfs(a,i,d)+dfs(i,b,d))
		{
			ans=dfs(a,i,d)+dfs(i,b,d);
			vis[ans]++;
		}
		else if(ans==dfs(a,i,d)+dfs(i,b,d))
		{
			vis[ans]++;
		}
		i++;
	}
	return ans;
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	int ak=0;
	while(t--)
	{
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>x[i];
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				memset(vis,0,sizeof(vis));
				ans=0x3ffff;
				dfs(i,j,d);
				for(int k=1;k<=abs(i-j);k++)
				{
					if(vis[k]==2)ak++;
				}
			}
		}
		cout<<ak<<"\n";
	}
	return 0;
 } 
