#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500010];
int x[300010];
int vis[300010];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		stack<int> st;
		for(int j=1;j<=m;j++) vis[j]=0;
		for(int j=i;j<=n;j++)
		{
			if(!vis[a[j]])
			{
				st.push(a[j]);
				vis[a[j]]++;
			}
			else
			{
				while(st.top()!=a[j])
				{
					vis[st.top()]--;
					st.pop();
				}
			}
		}
		while(!st.empty())
		{
			x[st.top()]++;
			st.pop();
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<x[i]<<" ";
	}
	return 0;
}
