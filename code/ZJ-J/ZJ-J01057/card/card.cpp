#include<bits/stdc++.h>
using namespace std;
queue<int> q;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	int a[n+5]={},ans[m+5]={};
	bool used[300005];
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		memset(used,false,sizeof(used));
		for(int j=i;j<=n;j++)
		{
			if(used[a[j]])
				while(q.front()!=a[j])
					q.pop();
			else
			{
				q.push(a[j]);
				used[a[j]]=true;
			}
		}
		while(!q.empty())
		{
			ans[q.front()]++;
			q.pop();
		}
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<' ';
	return 0;
}