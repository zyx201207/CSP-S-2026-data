#include <bits/stdc++.h>
using namespace std;
int tong[300010],in[300010];
int a[500010];
stack <int> q;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			if(in[a[j]])
			{
				int t;
				do
				{
					t=q.top();
					q.pop();
					in[t]=0;
				}while(t!=a[j]&&!q.empty());
				q.push(a[j]);
				in[a[j]]=1;
			}
			else
			{
				in[a[j]]=1;
				q.push(a[j]);
			}
		}
		while(!q.empty())
		{
			q.pop();
		}
		for(int j=1;j<=m;j++)
		{
			if(in[j])
			{
				tong[j]++;
				in[j]=0;
			}
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<tong[i]<<" ";
	}
	return 0;
}
