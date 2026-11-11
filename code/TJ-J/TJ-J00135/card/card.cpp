#include<bits/stdc++.h>
using namespace std;

stack<int> st;
int n,m;
int a[500010];
bool flag[500010];
int ans[500010];

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
		memset(flag,0,sizeof(flag));
		while(!st.empty())
		{
			st.pop();
		}
		for(int j=i;j<=n;j++)
		{
			if(flag[a[j]])
			{
				while(st.top()!=a[j])
				{
					flag[st.top()]=false;
					st.pop();
				}
			}
			else
			{
				st.push(a[j]);
				flag[a[j]]=true;
			}
		}
		for(int j=1;j<=m;j++)
		{
			if(flag[j])
			{
				ans[j]++;
			}
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<ans[i]<<" ";
	}
	return 0;
}
