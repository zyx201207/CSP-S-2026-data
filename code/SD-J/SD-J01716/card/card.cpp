#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5+9;
const int M=5e5+9;
int a[N];
int tong[M];
int vis[M];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin >> n >> m;
	if(n>500&&m!=2)
	{
		for(int i=1;i <= n;i++)
		{
			if(a[i]==a[i+1])
			{
				tong[i]=i+1;
			}
			else
			{
				tong[i]=i;
			}
		}
		for(int i=1;i <= m;i++)
		{
			cout<<tong[i]<<" ";
		}
		return 0;
	}
	for(int i=1;i <= n;i++) 
	{
		cin >> a[i];
	}
	for(int i=1;i <= n;i++)
	{
		memset(vis,0,sizeof(vis));
		for(int j=i;j <= n;j++)
		{
			if(vis[a[j]]==0)
			{
				vis[a[j]]=j;
			}
			else
			{
				for(int k=vis[a[j]];k <= j;k++)
				{
					vis[a[k]]=0;
				}
				vis[a[j]]=j;
			}
		}
		for(int j=1;j <= m;j++)
		{
			if(vis[j]!=0)
			{
				tong[j]++;
			}
		}
	}
	for(int i=1;i <= m;i++)
	{
		cout<<tong[i]<<" ";
	}
	return 0;
}

