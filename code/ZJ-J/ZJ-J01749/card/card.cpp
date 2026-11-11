#include<bits/stdc++.h>
using namespace std;

int n,m,a[500010],ans[200010];

int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		bool vis[200010]={0};
		stack<int>s;
		for(int j=i;j<=n;j++)
		{
			if(!vis[a[j]])
			{
				s.push(a[j]);
				vis[a[j]]=1;
			}
			else
			{
				while(s.top()!=a[j])
				{
					int k=s.top();
					vis[k]=0;
					s.pop();
				}
			}
		}
		while(!s.empty())
		{
			int k=s.top();
			ans[k]++;
			s.pop();
		}
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
	return 0;
}

