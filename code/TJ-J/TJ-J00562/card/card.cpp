#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=5e5+7;
const int maxm=3e5+7;
int n,m,a[maxn],ans[maxm];
signed main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin >> n >> m;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
	}
	for(int i=1;i<=n;i++)
	{
		priority_queue<int> q;
		for(int x=i;x<=n;x++) q.push(a[x]);
		ans[q.top()]++;
		int be=q.top();
		q.pop();
		while(!q.empty())
		{
			if(q.top()!=be)
			{
				ans[q.top()]++;
				be=q.top();
				q.pop();
			}
		}
	}
	for(int i=1;i<=m;i++) cout << ans[i] << " ";
	return 0;
}
