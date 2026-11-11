#include<bits/stdc++.h>
using namespace std;
long long a[2000007];
long long w[5007][5007];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,T;
	cin>>c>>T;
	while(T--)
	{
		int n;
		long long d;
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>a[i];
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(abs(a[i]-a[j])<=d) w[i][j]=abs(a[i]-a[j]);
				else w[i][j]=0; 
			}
		}
		long long ans=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				for(int q=1;q<=n;q++)
				{
					if(w[i][j]==w[i][q]&&w[i][j]!=0) ans++;
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}