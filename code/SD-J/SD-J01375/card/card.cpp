#include<iostream>
#define int long long
using namespace std;
int n,m,f,flag;
int a[500010],ans[500010],pre[300010],vis[500010];
signed main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	f=1;
	for(int i=1; i<=n; i++)
	{
		cin>>a[i];
		if(a[i]<a[i-1])
		{
			f=0;
		} 
	}
//	if(f==1)
//	{
//		for(int i=1; i<=n; i++)
//		{
//			if(i==i+1)
//			{
//				a[i]=0;	
//			}			
//		}
//		for(int i=1; i<=n; i++)
//		{
//			for(int j=i; j<=n; j++)
//			{
//				ans[a[j]]++;
//			}
//		}
//		for(int i=1; i<=m; i++)
//		{
//			cout<<ans[i]<<' ';
//		}
//		return 0;
//	}
	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=m; j++)
		{
			pre[j]=0;
		}
		for(int j=1; j<=n; j++)
		{
			vis[j]=0;
		}
		for(int j=i; j<=n; j++)
		{
			if(pre[a[j]]!=0&&vis[pre[a[j]]]==0)
			{
				for(int k=pre[a[j]]; k<=j-1; k++)
				{
					vis[k]=1;
				}
			}
			pre[a[j]]=j;
		}
		for(int j=i; j<=n; j++)
		{
			if(vis[j]==0)
			{
				ans[a[j]]++;
			}
		}
	}
	for(int i=1; i<=m; i++)
	{
		cout<<ans[i]<<' ';
	}
	return 0;
} 
/*
4 3
1 2 1 3
*/
/*
10 3
3 1 2 1 3 2 3 1 2 1
*/
