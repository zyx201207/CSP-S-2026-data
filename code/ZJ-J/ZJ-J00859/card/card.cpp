#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[50005],ans[50005];
bool vis[20005];
stack<int>s;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		memset(vis,0,sizeof(vis));
		for(int j=i;j<=n;j++)
		{
			if(vis[a[j]])
			{
				while(s.top()!=a[j])
					vis[s.top()]=0,s.pop();
			}
			else
				s.push(a[j]),vis[a[j]]=1;
		}
		for(int i=1;i<=m;i++)
			if(vis[i])
				ans[i]++;
	}
	for(int i=1;i<=m;i++)
		cout<<ans[i]<<" ";
}