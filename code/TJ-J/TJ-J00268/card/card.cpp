#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500005],cnt[300005];
signed main()
{
	cin.tie(0);
	cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	int temp1=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		temp1=max(a[i],temp1);
	}
	int temp=m;
	stack<int> s;
	while(temp--)
	{
		int vis[300005]={0};
		for(int i=m-temp+1;i<=n;i++)
		{
			if(vis[a[i]]==0)
			{
				s.push(a[i]);
				vis[a[i]]=1;
			}
			else
			{
				while(!s.empty() && s.top()!=a[i])
				{
					s.pop();
				}
				vis[a[i]]=0;
			}
		}
		while(!s.empty())
		{
			cnt[s.top()]++;
			s.pop();
		}
	}
	for(int i=1;i<=temp1;i++)
	{
		if(cnt[i]!=0)
		{
			cout<<cnt[i]<<' ';
		}
	}
	return 0;
}
