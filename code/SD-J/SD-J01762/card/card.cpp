#include<bits/stdc++.h>
using namespace std;
stack<int> st;
int n,m;
int a[500010];
bool vis[500010];
long long t[300010];
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
		for(int j=i;j<=n;j++)
		{
			if(!vis[a[j]])
			{
				st.push(j);
				vis[a[j]]=1;
			}
			else
			{
				while(!st.empty() && a[st.top()]!=a[j])
				{
					vis[a[st.top()]]=0;
					st.pop();
				}
			}
		}
		while(!st.empty())
		{
			t[a[st.top()]]++;
			st.pop();
		}
		memset(vis,0,sizeof(vis));
	}
	for(int i=1;i<=m;i++)
	{
		cout<<t[i]<<' ';
	}

	return 0;
}
