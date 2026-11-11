#include<bits/stdc++.h>
using namespace std;

#define int long long

int n,m,a[200005],b[200005][40],c[200005],ansb[40];

signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		int num=a[i];
		for(int j=1;j<=31;j++)
		{
			b[i][j]=num%2;
			num/=2;
		}
	}
	for(int i=1;i<=n;i++)
		c[i]=1;
	sort(a+1,a+n+1);
	for(int j=31;j>=1;j--)
	{
		int sum=0;
		for(int i=1;i<=n;i++)
			sum+=(b[i][j]&&c[i]);
		if(sum>=m)
		{
			ansb[j]=1;
			for(int i=1;i<=n;i++)
				if(!(b[i][j]&&c[i]))
				    c[i]=0;
		}
	}
	int w=1,ans=0;
	for(int j=1;j<=31;j++)
	{
		ans+=ansb[j]*w;
		w*=2;
	}
	cout<<ans;
	return 0;
}
