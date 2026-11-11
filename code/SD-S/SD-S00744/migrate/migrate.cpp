#include<bits/stdc++.h>
using namespace std;
int cc,t;
int n;
long long d;
long long x[200005];
long long f[305][305];
int main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>cc>>t;
	while(t--)
	{
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>x[i];
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(i==j) f[i][j]=0;
				else f[i][j]=1e18;
			}
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;x[j]-x[i]<=d;j++)
			{
				f[i][j]=1;
			}
		}
		for(int k=1;k<=n;k++)
		{
			for(int i=1;i<=n;i++)
			{
				for(int j=i+1;j<=n;j++)
				{
					long long mi=f[i][k]+f[k][j];
					f[i][j]=min(f[i][j],mi);
				}
			}
		}
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=i;j<=n;j++)
			{
				int cnt=0;
				for(int k=i+1;k<=j-1;k++)
				{
					if(f[i][k]+f[k][j]==f[i][j]) cnt++;
				}
				if(cnt==2) ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
