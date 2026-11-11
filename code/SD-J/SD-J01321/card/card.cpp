#include<bits/stdc++.h>
using namespace std;
int a[500010];
stack <int> temp;
bool t[500010];
int ans[500010];
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
	for(int i=1;i<=n;i++)
	{
		memset(t,0,sizeof t);
		for(int j=i;j<=n;j++)
		{
			if(!t[a[j]])
			{
				t[a[j]]=1;
				temp.push(a[j]);
			}
			else
			{
				while(temp.top()!=a[j]&&!temp.empty())
				{
					t[temp.top()]=0;
					temp.pop();
				}
			}
		}
		while(!temp.empty())
		{
			int cur=temp.top();
			temp.pop();
			ans[cur]++;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<ans[i]<<" ";
	}
	return 0;
}
