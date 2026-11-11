#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
int w[500005],check[50005][505];
int n,m,d,q;
int a[505][20005];
int b[505][20005];
int t[505][20005];
int dfs(int now,int end,int x)
{
	int mmin=1e9;
	if(now==end)
	{
		return t[x][end];
	}
	for(int i=1;i<=n;i++)
	{
		if(a[i][now]!=0&&check[a[i][now]][i]<=5)
		{
			check[a[i][now]][i]++;
			if(x==i)
			{
				mmin=min(dfs(a[i][now],end,i),mmin);
			}
			else
			{
				mmin=min(dfs(a[i][now],end,i)+t[x][now]+t[i][now],mmin);
			}
			check[a[i][now]][i]--;
		}
		/*if(b[i][now]!=0&&check[b[i][now]][i]<=5)
		{
			check[b[i][now]][i]++;
			if(x==i)
			{
				mmin=min(dfs(b[i][now],end,i),mmin);
			}
			else
			{
				mmin=min(mmin,dfs(b[i][now],end,i)+t[x][now]+t[i][now]);
			}
			check[b[i][now]][i]--;
		}*/
	}
	return mmin;
}
int dfss(int now,int end,int x)
{
	int mmin=1e9;
	if(now==end)
	{
		return t[x][end];
	}
	for(int i=1;i<=n;i++)
	{
		/*if(a[i][now]!=0&&check[a[i][now]][i]<=5)
		{
			check[a[i][now]][i]++;
			if(x==i)
			{
				mmin=min(dfs(a[i][now],end,i),mmin);
			}
			else
			{
				mmin=min(dfs(a[i][now],end,i)+t[x][now]+t[i][now],mmin);
			}
			check[a[i][now]][i]--;
		}*/
		if(b[i][now]!=0&&check[b[i][now]][i]<=5)
		{
			check[b[i][now]][i]++;
			if(x==i)
			{
				mmin=min(dfss(b[i][now],end,i),mmin);
			}
			else
			{
				mmin=min(mmin,dfss(b[i][now],end,i)+t[x][now]+t[i][now]);
			}
			check[b[i][now]][i]--;
		}
	}
	return mmin;
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>n>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	{
		int k,x,t1,la=0;
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			cin>>x>>t1;
			a[i][la]=x;
			b[i][x]=la;
			t[i][x]=t1;
			la=x;
		}
	}
	for(int i=1;i<=q;i++)
	{
		int l,r,x;
		cin>>l>>r;
		x=dfs(l,r,0);
		if(x>=1e9)
		{
			x=dfss(l,r,0);
		}
		cout<<x+w[l]+w[r]<<endl;
	}
	return 0;
} 

