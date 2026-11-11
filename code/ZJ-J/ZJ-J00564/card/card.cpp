#include<bits/stdc++.h>
using namespace std;

const int N = 5e5+10;
const int M = 3e5+10;
int n,m;
int a[N]; 
int ans[M];
int vis[N];

int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i = 1;i<=n;i++)
	{
		int tot = 0;
		for(int j = i;j<=n;j++)
		{
			bool b = 0;
			for(int k = 1;k<=tot;k++)
			{
				if(a[j] == vis[k])
				{
					b = 1;
					tot = k;
					break;
				}
			}
			if(b == 0)
			{
				vis[++tot] = a[j];
			}
		}
		for(int j = 1;j<=tot;j++)
		{
			ans[vis[j]]++;
		}
	}
	for(int i = 1;i<=m;i++)
	{
		cout<<ans[i]<<" ";
	}
	return 0;
}
