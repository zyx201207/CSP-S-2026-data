#include<bits/stdc++.h>
using namespace std;
int a[500005];
bool ap[500005];
int ans[500005];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		queue<int>qu;
		for(int j=i;j<=n;j++)
		{
			qu.push(a[i]);
		}
		bool flag=1;
		stack<int>st;
		while(flag)
		{
			if((!qu.empty())&&(!ap[qu.front()]))
			{
				ap[qu.front()]=1;
				st.push(qu.front());
				qu.pop();
			}
			else
			{
				while(1)
				{
					if((!st.empty())&&(!qu.empty())&&(st.top()!=qu.front()))
					{
						ap[st.top()]=0;
						st.pop();
					}
					else if((!st.empty())&&(!qu.empty())&&(st.top()==qu.front()))
					{
						ap[st.top()]=0;
						st.pop();
						flag=0;
					}
					if(qu.empty())
					{
						flag=0;
						while(!st.empty())
						{
							ans[st.top()]++;
							st.pop();
						}
						for(int lp=1;lp<=n;lp++)
						{
							ap[lp]=0;
						}
						break;
					}
				}
			}
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<ans[i]<<' ';
	}
	return 0; 
}
