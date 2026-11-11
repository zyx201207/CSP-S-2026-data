#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,m;
int a[200010];
int v[200010][31];
int vis[200010];
int b[200010];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		int k=a[i],num=0;
		while(k)
		{
			v[i][num]=k%2;
			num++;
			k/=2;
		}
	}
	// for(int i=1;i<=n;i++)
	// {
	// 	for(int j=7;j>=0;j--)
	// 	{
	// 		cout<<v[i][j]<<" ";
	// 	}
	// 	cout<<'\n';
	// }
	int r=0,rr=0,l=0;
	for(int i=1;i<=n;i++)
	{
		vis[++r]=i;
	}
	for(int j=30;j>=0;j--)
	{
		l=r;
		rr=0;
		while(r)
		{
			if(v[vis[r]][j]==1)
				b[++rr]=vis[r];
			r--;

		}
		if(rr>=m)
		{
			for(int i=1;i<=rr;i++)
				vis[++r]=b[i];
		}
		else
		{
			r=l;
		}
		// for(int i=1;i<=r;i++)
		// 	cout<<a[vis[i]]<<" ";
		// cout<<'\n';
		if(r==m)
			break;
	}
	if(r<m)
		cout<<0;
	else
	{
		ll ans=a[vis[1]];
		// cout<<ans<<" ";
		for(int i=2;i<=r;i++)
		{
			ans&=a[vis[i]];
			// cout<<a[vis[i]]<<" ";
		}
		cout<<ans;
	}
	return 0;
}