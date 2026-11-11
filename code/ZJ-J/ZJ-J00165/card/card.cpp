#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[500005];
bool vis[500005];
int cnt[500005];
signed main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	int i,j;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(n<=5000)
	{
		for(i=1;i<=n;i++)
		{
			stack<int>st;
			memset(vis,0,sizeof(vis));
			for(j=i;j<=n;j++)
			{
				if(vis[a[j]]==0)
				{
					vis[a[j]]=1;
					st.push(a[j]);
				}
				else
				{
					while(!st.empty()&&st.top()!=a[j])
					{
						vis[st.top()]=0;
						st.pop();
					}
				}
			}
			while(!st.empty())
			{
				cnt[st.top()]++;
				st.pop();
			}
		}
		for(i=1;i<=m;i++)
		{
			cout<<cnt[i]<<' ';
		}
	}
	else
	{
		for(i=1;i<=n;i++)
		{
			if(a[i]!=a[i-1])
			{
				cnt[a[i]-1]=i-1;
			}
		}
		cnt[m]=n;
		for(i=1;i<=m;i++)
		{
			cout<<cnt[i]<<' ';
		}
	}
	return 0;
}
