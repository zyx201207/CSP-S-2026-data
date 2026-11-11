#include<bits/stdc++.h>

using namespace std;

const int P=998244353;
const int N=1e6+10,M=2e6+10;

long long n,m;
long long a[N],ans[N];
map<long long,long long> mp;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(n<=5000)
	{
		for(int i=1;i<=n;i++)
		{
			mp.clear();
			deque<int> dq;
			for(int j=i;j<=n;j++)
			{
				dq.push_back(a[j]);
				mp[a[j]]++;
				if(mp[a[j]]>=2)
				{
					dq.pop_back();
					while(!dq.empty() and mp[a[j]]>=2)
					{
						int x=dq.back();
						mp[x]--;
						dq.pop_back();
					}
					dq.push_back(a[j]);
				}
			}
			while(!dq.empty())
			{
				int x=dq.back();
				dq.pop_back();
				ans[x]++;
			}
		}
		for(int i=1;i<=m;i++)
		{
			cout<<ans[i]<<" ";
		}
	}
	else
	{
		for(int i=1;i<=m;i++)
		{
			cout<<1<<" ";
		}
	}
	return 0;
}
/*
4 3
1 2 1 3
*/
/*
1:2 4 8 10
2:3 6 9
3:1 5 7
*/
