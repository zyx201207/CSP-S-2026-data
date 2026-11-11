#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
int w[500005],check[50005][505];
int n,m,d,q;
int a[505][20005];
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
		if(a[i][now]!=0&&check[a[i][now]][i]<=1)
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
			t[i][x]=t1;
			la=x;
		}
	}
	for(int i=1;i<=q;i++)
	{
		int l,r;
		cin>>l>>r;
		cout<<dfs(l,r,0)+w[l]+w[r]<<endl;
	}
	return 0;
} 
/*0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3*/
