#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
const int N=5e5+5,M=3e5+5;
int n,m,a[N],ans[M];
deque<int> q;
unordered_map<int,int> cnt;
signed main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	IOS;cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int p=1;p<=n;p++)
	{
		cnt.clear();
		for(int i=p;i<=n;i++)
		{
			++cnt[a[i]];
			if(cnt[a[i]]==2)
			{
				while(!q.empty() && q.back()!=a[i])
				{
					--cnt[q.back()];
					q.pop_back();
				}
				q.pop_back();
			}
			q.push_back(a[i]);
			cnt[a[i]]=1;
		}
		while(!q.empty())
		{
			++ans[q.front()];
			q.pop_front();
		}
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<' ';
	return 0;
}