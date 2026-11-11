#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,m;
int a[500010];
int b[500010];
int v[300010];
int vis[500010];
int ans[300010];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int j=1;j<=n;j++)
	{
		memset(v,0,sizeof(v));
		int r=0;
		for(int i=j;i<=n;i++)
		{
			// cout<<a[i]<<"  ";
			if(v[a[i]]!=0&&i>vis[b[r]]&&vis[a[i]]>=vis[b[1]])
			{
				r=v[a[i]];
				v[a[i]]=r;
				b[r]=a[i];
			}
			else
			{
				b[++r]=a[i];
				v[a[i]]=r;
			}
			vis[a[i]]=i;
			// for(int k=1;k<=r;k++)
			// 	cout<<b[k]<<" ";
			// cout<<'\n';
		}
		// cout<<'\n';
		for(int i=1;i<=r;i++)
			ans[b[i]]++;
	}
	for(int i=1;i<=m;i++)
		cout<<ans[i]<<" ";
	return 0;
}