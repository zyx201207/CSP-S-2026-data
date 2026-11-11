#include<bits/stdc++.h>
using namespace std;
const int MAXN=500005;
const int MAXM=300005;
int ans[MAXM];
int a[MAXN];
int ins[MAXM];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	stack<int> s;
	fill(ans,ans+m+1,0);
	fill(ins,ins+m+1,0);
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int j=1;j<=n;j++)
	{
		for(int i=j;i<=n;i++)
		{
			int v=a[i];
			if(!ins[v])
			{
				s.push(v);
				ins[v]=1;
			}
			else
			{
				while(s.top()!=v)
				{
					ins[s.top()]=0;
					s.pop();
				}
			}
		}
		while(!s.empty())
		{
			ans[s.top()]++;
			ins[s.top()]=0;
			s.pop();
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<ans[i]<<" ";
	}
	return 0;
}
