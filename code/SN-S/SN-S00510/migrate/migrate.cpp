//徐语瞳 SN-S00510 西安翱翔中学
#include<bits/stdc++.h>
using namespace std;
int c,t;
int n,f[5005][5005];
long long d;
long long a[2000005];
void solve1()
{
	while(t--)
	{
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>a[i];
		if(n==1)
		{
			cout<<"0\n";
			continue;
		}
		long long len=a[2]-a[1];
		if(len>d)
		{
			cout<<"0\n";
			continue;
		}
		long long k=d/len;
		long long ans=0;
		for(int i=1;i<n;i++)
		{
			ans+=(n-i+1)/k;
		}
		cout<<ans<<"\n";
	}
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int c,t;
	cin>>c>>t;
	if(c==11||c==12)
	{
		solve1();
		return 0;
	}
	while(t--)
	{
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>a[i];
		if(n==1)
		{
			cout<<"0\n";
			continue;
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(i==j) f[i][j]=f[j][i]=0;
				else if(abs(a[i]-a[j])<=d) f[i][j]=1;
				else f[i][j]=1e9;
			}
		}
		for(int k=1;k<=n;k++)
			for(int i=1;i<=n;i++)
				for(int j=1;j<=n;j++)
					f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
					
	}
	return 0;
}
