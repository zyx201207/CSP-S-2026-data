#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],b[5005][5005],s[5005],mx,ans;
bool fA=1,fB=1;

int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	if(n<=5000)
	{
		for(int i=1;i<=n;i++)
		  cin>>a[i];
		sort(a+1,a+1+n);
		for(int i=2;i<=n;i++)
		  s[i-1]+=b[i][1]=a[i]-a[i-1];
		for(int i=2;i<=n;i++)
		  for(int j=i+1;j<=n;j++)
			s[j-1]+=b[j][i]=b[j-1][i-1]+b[j][i-1]-b[j-1][i-2];
		for(int i=1;i<=n;i++)
		{
			if(s[i]>=mx&&s[i]<=m)
			{
				mx=s[i];
				ans=i;
			}
		}
//		for(int i=1;i<=n;i++)
//		{
//			for(int j=1;j<=n;j++)
//			  cout<<b[j][i]<<' ';
//			cout<<'\n';
//		}
//		for(int i=1;i<=n;i++)
//		  cout<<s[i]<<' ';
//		cout<<'\n';
		cout<<ans+1;
	}
	else
	{
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			if(a[i]!=i)
			  fA=0;
			if(i>=3&&a[i]-a[i-1]!=a[i-1]-a[i-2])
			  fB=0;
		}
		if(fA)
		{
			long long sum=0;
			for(int i=1;i<=n;i++)
			{
				if(sum+i-1>m)
				{
					cout<<i-1;
					return 0;
				}
				else
				  sum+=i-1;
			}
			cout<<n;
			return 0;
		}
		if(fB)
		{
			long long sum=0,cs=a[2]-a[1];
			for(int i=1;i<=n;i++)
			{
				if((sum+i-1)*cs>m)
				{
					cout<<i;
					return 0;
				}
				else
				  sum+=i-1;
			}
			cout<<n;
		}
	}
	return 0;
}
