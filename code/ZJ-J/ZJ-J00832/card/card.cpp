#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
ll n,m,vis[300030]={0},ans[300030]={0},a[500050];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}	
	for(int i=1;i<=n;i++)
	{
		vector <int> de;
		memset(vis,0,sizeof(vis));
		for(int j=i;j<=n;j++)
		{
			if(!vis[a[j]])
			{
				de.push_back(a[j]);
				vis[a[j]]=1;
			}
			else
			{
				do
				{
					vis[de.back()]=0;
					de.pop_back();
				}while(de.back()!=a[j]);
				vis[de.back()]=0;
				de.pop_back();
				de.push_back(a[j]);
				vis[a[j]]=1;
			}
		}
		for(int i=1;i<=m;i++)
		{
			ans[i]+=vis[i];
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<ans[i]<<' ';
	}
	return 0;
}