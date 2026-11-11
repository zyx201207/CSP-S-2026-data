#include <bits/stdc++.h>
using namespace std;

#define int long long

int c,t;
int n,m;
int a[5005];
int s[5005][5005];
int x[5005][5005];

signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>m;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				s[i][j]=9e18,x[i][j]=0;
			}
		}
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			s[i][i]=0;
			x[i][i]=1;
		}
		for(int l=1;l<=n;l++)
		{
			for(int i=l;i<=n;i++)
			{
				int j=i+1;
				while(j<=n&&a[i]+m>=a[j])
				{
					if(s[l][j]==9e18) s[l][j]=s[l][i]+1,x[l][j]=1;
					else if(s[l][i]+1==s[l][j]) x[l][j]++;
					j++;
				}
			}
		}
//		for(int i=1;i<=n;i++)
//		{
//			for(int j=1;j<=n;j++)
//			{
//				cout<<s[i][j]<<" ";
//			}
//			cout<<"\n";
//		}
//		cout<<"\n";
//		for(int i=1;i<=n;i++)
//		{
//			for(int j=1;j<=n;j++)
//			{
//				cout<<x[i][j]<<" ";
//			}
//			cout<<"\n";
//		}
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				if(x[i][j]==2) ans++;
			}
		}
		cout<<ans<<"\n";
	}
	
	return 0;
}
/*
0 1
10 3
0 3 6 7 8 9 10 11 14 17
*/