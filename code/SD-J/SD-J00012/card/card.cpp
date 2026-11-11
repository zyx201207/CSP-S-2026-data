#include<bits/stdc++.h>
using namespace std;
int a[500010];
int vis[500010];
int s[500010];
int ans[500010];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		
	}
	for(int k=1;k<=n;k++)
	{
		memset(vis,0,sizeof(vis));
		memset(s,0,sizeof(s));
		for(int i=k;i<=n;i++)
		{
			if(vis[a[i]]){
				for(int j=s[a[i]];j<i;j++)
				{
					vis[a[j]]=0;
					s[a[j]]=0;
				}
				s[a[i]]=i;
				
				vis[a[i]]=1;
			}else {
				s[a[i]]=i;
				vis[a[i]]=1;
			}
//			for(int i=1;i<=n;i++)
//			{
//				cout<<vis[i]<<" ";
//			}
//			cout<<endl;;
		}
		for(int i=1;i<=m;i++)
		{
			if(vis[i])
			{
				ans[i]++;
			}
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<ans[i]<<" ";
	}
}
