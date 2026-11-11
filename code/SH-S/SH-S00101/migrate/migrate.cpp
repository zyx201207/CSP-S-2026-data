#include<bits/stdc++.h>
using namespace std;
long long a[5005];
long long q[5005][5005];
long long u[5005][5005];
int main()
{	
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;	
	while(t--)
	{	
		int n;
		long long d;
		long long ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		for(int i=1;i<=n;i++)
		{	
			for(int j=1;j<=n;j++)
			{
				q[i][j]=1000000000000000009;
			}
			q[i][i]=0;
			}
		for(int i=1;i<=n;i++)
		{
			for(int j=i-1;j>=1;j--)
			{
				if(a[i]-a[j]<=d)
				{
					q[i][j]=1;
					q[j][i]=1;
				}
				else
				{
					break;
				}
			}
		}
		for(int k=1;k<=n;k++)
		{
			for(int i=1;i<=n;i++)
			{
				for(int j=1;j<=n;j++)
				{
					if((q[i][k]+q[k][j])<q[i][j])
					{
						q[i][j]=q[i][k]+q[k][j];
						u[i][j]=1;
					}
					else if((q[i][k]+q[k][j])==q[i][j] and k!=i and k!=j and q[i][j]!=1)
					{
						u[i][j]++;
					} 
				}
			}
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				if(u[i][j]==2 or u[j][i]==2)
				{
					ans++;
				 } 
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
