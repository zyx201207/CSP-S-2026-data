#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,d,l,r,q,w[2000005],a[505][2005],t[505][2005],kk[100001],minx=1e18L,sum;
void dfs(int tan,int k,int s)
{
//	cout<<tan<<' '<<k<<' '<<s<<'\n';
	if(s>minx)
	{
		return ;
	}
	if(k==r)
	{
		minx=min(minx,s+w[k]);
		return ;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=kk[i];j++)
		{
			if(a[i][j]==k)
			{
				dfs(i,a[i][j+1],s+t[i][j]+t[i][j+1]);
			}
		}
	}
}
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>kk[i];
		for(int j=1;j<=kk[i];j++)
		{
			cin>>a[i][j]>>t[i][j];
		}
	}
	while(q--)
	{
		minx=1e18L,sum=0;
		cin>>l>>r;
		sum=w[l];
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=kk[i];j++)
			{
				if(a[i][j]==l)
				{
					dfs(i,a[i][j+1],sum+t[i][j]+t[i][j+1]);
				}
			}
		}
		cout<<minx<<'\n';
	}
}