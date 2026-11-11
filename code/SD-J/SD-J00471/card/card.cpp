#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500010];
map<int,int>mp,ans;
stack<int>s;
signed main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			s.push(a[j]);
			if(mp.count(a[j]))
			{
				s.pop();
				while(!s.empty()&&s.top()!=a[j])
				{
					mp.erase(s.top());
					s.pop();
				}
			}
			mp[a[j]]++;
		}
		for(auto j:mp)
		{
			ans[j.first]++;
		}
		while(!s.empty())
		{
			s.pop();
		}
		mp.clear();
	}
	for(int i=1;i<=m;i++)
	{
		cout<<ans[i]<<" ";
	}
	return 0;
}

