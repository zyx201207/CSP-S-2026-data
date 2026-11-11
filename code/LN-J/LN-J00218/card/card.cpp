#include<bits/stdc++.h>
using namespace std;
int n,m,ans[300010],a[500010],vis[5010];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(n<=10000)
	{
		for(int i=1;i<=n;i++)
		{
			stack<int> s;
			for(int j=i;j<=n;j++)
			{
				if(vis[a[j]])
				{
					while(s.top()!=a[j])
					{
						vis[s.top()]--;
						s.pop();
					}
					//cout<<s.top()<<" ";
				}
				else
				{
					s.push(a[j]);
					vis[a[j]]++;
				}
			}
			for(int j=1;j<=m;j++)
			{
				if(vis[j])
				{
					ans[j]++;
					//cout<<j<<" ";
					vis[j]=0;
				}
			}
		}
	}
	else if(m<=2)
	{
		if(m==1)
		{
			cout<<n;
			return 0;
		}
		if(m==2)
		{
			for(int i=1;i<=n;i++)
			{
				if(a[i]==1 && a[n]==1)
				{
					ans[1]++;
				}
				else if(a[i]==2 && a[n]==2)
				{
					ans[2]++;
				}
				else
				{
					ans[1]++;
					ans[2]++;
				}
			}
			for(int i=1;i<=m;i++)
			{
				cout<<ans[i]<<" ";
			}
			return 0;
		}
	}
	else
	{
		for(int i=1;i<=n;i++)
		{
			ans[a[i]]=i;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<ans[i]<<" ";
	}
	return 0;
}
