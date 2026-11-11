#include<bits/stdc++.h>
using namespace std;
#define int long long

const int M = 5e5 + 5;
const int INF = 0x7f7f7f7f7f7f7f7f;

struct Edge
{
	int to,n;
	int w;
};
Edge e[M << 1];
int flag[M];
int h[M];
int tot;
int d[M];
priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > q;
int c,n,m,di,qu;
int st[M];

namespace ljn
{
	void add(int u,int v,int w)
	{
		e[++tot] = {v,h[u],w};
		h[u] = tot;
	}
	int sf(int s)
	{
		for(int i = 1 ; i <= m ; i++)
		{
			d[i] = 0x7f7f7f7f7f7f7f;
			flag[i] = 0;
		} 
		d[s] = 0;
		q.push({0,s});
		while(!q.empty())
		{
			
			int u = q.top().second;
			int w = q.top().first;
			q.pop();
			for(int i = h[u] ; ~i ; i = e[i].n)
			{
				int v = e[i].to;
				d[v] = min(d[v],w + e[i].w);
				flag[v] = true;
				q.push({d[v],v}); 					

			}
		}
	}
	void solve()
	{
		ios::sync_with_stdio(false);
		cin.tie(0);
		memset(h,-1,sizeof(h));
		
		cin >> c >> n >> m >> di >> qu;
		for(int i = 1 ; i <= m ; i++)
		{
			int w;
			cin >> w;
			add(i,i + m,w);
			add(i + m,i,w);
		}
//		int cnt = 0;
//		int a[25];
//		for(int i = 1 ; i <= n ; i++)
//		{
//			int k;
//			cin >> k;
//			for(int j = 1 ; j <= k ; j++)
//			{
//				int w;
//				cin >> a[j] >> w;
//				cout << 2;
//				if(e[tot + 1].to != 0)
//				{
//					cout << 1;
//				}
//				add(a[j] + m,a[j] + m + cnt + j,w);
//			}
//			int tmp = k;
//			while(tmp > 1)
//			{
//				add(a[k - 1] + m + cnt + tmp - 1,a[k] + m + cnt + tmp,0);
//				tmp--;
//			}
//			cnt += k;
//		}
//		for(int i = 1 ; i <= qu ; i++)
//		{
//			int x,y;
//			cin >> x >> y;
//			sf(x);
//			cout << d[y] << '\n';
//		}
		return ;
	}
}
signed main()
{
	ljn::solve();
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

*/
