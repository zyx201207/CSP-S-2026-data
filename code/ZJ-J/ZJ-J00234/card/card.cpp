#include<bits/stdc++.h>
using namespace std;
int a[500005];
int t[500005];
int ans[500005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	stack<int>q;
	for(int s=1;s<=n;s++)
	{
		for(int i=s;i<=n;i++)
		{
			if(t[a[i]]==1)
			{
				while(q.size())
				{
					int x=q.top();
					q.pop();
					t[x]=0;
					if(x==a[i])
					{
						break;
					}
				}
			}
			q.push(a[i]);
			t[a[i]]=1;
		}
		while(q.size())
		{
			int x=q.top();
			q.pop();
			ans[x]++;
		}
		for(int i=1;i<=m;i++)
		{
			t[i]=0;
		}
	}
	for(int i=1;i<m;i++)
	{
		cout<<ans[i]<<" ";
	}
	cout<<ans[m];
	return 0;
}//°¦ 
