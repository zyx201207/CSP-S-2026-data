#include<bits/stdc++.h>

using namespace std;

#define int long long
#define mem(a,b) memset(a,b,sizeof(a))
#define pii pair<int,int>

namespace SOL1{
	const int N = 15; 
	int n,k,vis[N],dis[N];
	vector<int> e[N];
	void init()
	{
		for(int i = 1;i<=n;i++)e[i].clear(),e[i].shrink_to_fit();
	}
	void solve()
	{
		init();
		cin>>n>>k;
		int ans = LLONG_MAX;
		for(int i = 1,u,v;i<n;i++)
		{
			cin>>u>>v;
			e[u].push_back(v);
			e[v].push_back(u);
		}
		for(int t = 0;t<(1<<n);t++)
		{
			int cnt = 0;
			if(__builtin_popcount(t) != k)continue; 
			for(int i = 1;i<=n;i++)
			{
				if((1<<(i-1))&t)
				{
					bool flg = 0;
					for(auto v:e[i])
					{
						if((1<<(v-1))&t)flg = 1;
					}
					if(!flg)cnt++;
				}
			}
			if(cnt > 2)continue;
			priority_queue<pii> q;
			mem(dis,0x3f),mem(vis,0);
			for(int i = 1;i<=n;i++)
			{
				if((1<<(i-1))&t)
				{
					dis[i] = 0;
					q.push({0,i});
				}
			}
			int mxv = 0;
			while(!q.empty())
			{
				int u = q.top().second;
				q.pop();
				if(vis[u])continue;
				vis[u] = 1;
				for(auto v:e[u])
				{
					if(dis[v] > dis[u]+1)
					{
						dis[v] = dis[u]+1;
						q.push({-dis[v],v});
					}
				}
			}
			for(int i = 1;i<=n;i++)
			{
				mxv = max(mxv,dis[i]);
			}
			ans = min(ans,mxv);
		}
		cout<<ans<<'\n';
	}
}

namespace SOL2{
	const int N = 1e5+15;
	int n,k;
	void solve()
	{
		cin>>n>>k;
		
		for(int i = 1,u,v;i<n;i++)
		{
			cin>>u>>v;
		}
		if(n == k)return cout<<0<<'\n',void();
		int mf = (n-1)/2;
		if(k >= mf)return cout<<"1\n",void();
		cout<<1+(mf-k+3)/4<<'\n';
		
	}
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
#ifndef DEBUG
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
#else
	freopen("hub5.in","r",stdin);
#endif
	int c,T;
	cin>>c>>T;
	while(T--)
	{
		if(c <= 3)SOL1::solve();
		if(c == 13 || c == 14)SOL2::solve();
	}

	return 0;
}
