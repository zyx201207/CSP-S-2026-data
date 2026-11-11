#include<bits/stdc++.h>
using namespace std;
int tong[300010],a[500010];
bool vis[300010];
stack<int> s;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		memset(vis,0,sizeof(vis));
		while(!s.empty()) s.pop();
		for(int j=i;j<=n;j++)
		{
			if(vis[a[j]])
			{
				while(s.top()!=a[j])
				{
					vis[s.top()]=0;
					s.pop();
				}
				continue;
			}
			s.push(a[j]),vis[a[j]]=1;
		}
		while(!s.empty())
		{
			tong[s.top()]++;
			s.pop();
		}
	}
	for(int i=1;i<=m;i++) cout<<tong[i]<<' ';
	return 0;
}
