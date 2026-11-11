#include<bits/stdc++.h>
using namespace std;
int c,t,n,d;
int INF=1e9;
int x[10001],f[10001][10001],ff[10001][10001];
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--)
    {

		int ans=0;
		cin>>n>>d;
    	for(int i=1;i<=n;i++)
    	{
    		cin>>x[i];
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				f[i][j]=INF;
			}
			f[i][i]=0;
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<i;j++)
			{
				if(x[i]-x[j]<=d)
				{
					f[j][i]=f[i][j]=x[i]-x[j];
				}
			}
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				for(int k=1;k<=n;k++)
				{
					if(f[i][k]+f[k][j]==f[i][j])ff[i][j]+=1;
					else if(f[i][k]+f[k][j]<f[i][j])
					{
						f[i][j]=f[i][k]+f[k][j];ff[i][j]=0;
					}
				}
			}
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(ff[i][j]==2)ans+=1;
			}
		}
		cout<<ans<<endl;
	}
    return 0;
}
