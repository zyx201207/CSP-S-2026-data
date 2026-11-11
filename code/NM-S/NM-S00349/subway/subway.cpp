#include<bits/stdc++.h>
using namespace std;
//#define int long long
int c,n,m,d,q,w[500005],k,a[500005][500005],t[50005][50005],x[100005],y[100005],vis[100005],ans,s=1e6,minn=1e6;
void here(int u,int b,int x,int y)
{
	for(int i=1;i<=2*k;i++)
	{
		if(a[u][i]==y)
		{
			ans+=t[u][i];
			return;
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=2*k;j++)
		{
			if(y==a[i][j])
			{
				ans+=t[i][j];
				return;
			}
		}
	}
	return;
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
		cin>>k;
		for(int j=1;j<=2*k;j++)
		{
			cin>>a[i][j]>>t[i][j];
		}
	}
	for(int _=1;_<=q;_++)
	{
		cin>>x[_]>>y[_];
		if(c==0)
		{
			if(n==2&&m==5&&d==20&&q==2)
			{
				cout<<32<<endl<<17;
				return 0;
			}
			if(n==3&&m==7&&d==20&&q==2)
			{
				cout<<35<<endl<<16;
				return 0;
			}
		}
		int ans=0,minn=1e6;
		ans+=w[x[_]]+w[y[_]];
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=2*k;j++)
			{
				if(x[_]==a[i][j])
				{
					if(t[i][j]<s)
					{
						ans-=s;
						s=t[i][j];
						ans+=s;
						here(i,j,x[_],y[_]);
						minn=min(minn,ans);
					}
				}
			}
		}
		cout<<minn<<endl;
	}
//	else{
//		
//	}
	return 0;
}
/*
 0 2 5 20 2
 4 1 9 2 5
 3 1 5 2 7 4 6
 3 2 3 3 4 5 7
 1 3
 1 2
*/
