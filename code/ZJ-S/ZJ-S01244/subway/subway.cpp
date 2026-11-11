#include<bits/stdc++.h>
using namespace std;
const long long INF = 1e18;
const long long Q = 1e5;
const long long M = 5e5;
const long long N = 500;
long long c,n,m,d,q,w[M+10],x,y,a,t,dis[M+N+10],k,inq[N+M+10];
queue<long long> qu;
vector<long long> e2[N+M+10];
vector<pair<long long,long long>> e[N+M+10];
void add(long long u,long long v,long long w)
{
	e[u].push_back({v,w});
	e[v].push_back({u,w});
}
struct node
{
	long long v1,v2,nums,res;
}p[Q+10];
bool cmp1(node xx,node yy)
{
	return xx.v1<yy.v1;
}
bool cmp2(node xx,node yy)
{
	return xx.nums<yy.nums;
}
bool vis[N+M+10];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; i++)    cin >> w[i];
	if(c>=12 && c<=19)
	{
		for(int i = 1; i <= n; i++)
		{
			cin >> k;
			for(int j = 1; j <= k; j++)
			{
				cin >> a >> t;
				e2[m+i].push_back(a);
				e2[a].push_back(m+i);
			}
		}	
		for(int i = 1; i <= q; i++)
		{
			cin >> p[i].v1 >> p[i].v2;
			p[i].nums = i;
		}
		sort(p+1,p+q+1,cmp1);
		for(int i = 1; i <= q; i++)
		{
			queue<pair<long long,long long>> q;
			for(int i = 1; i <= n+m; i++)    vis[i] = 0;
			for(int i = 1; i <= n+m; i++)    dis[i] = INF;
			long long s = p[i].v1;
			dis[s] = 0;
			vis[s] = 1;
			q.push({s,0});
			while(!q.empty())
			{
				pair<long long,long long> cur = q.front();
				q.pop();
				for(auto nxt : e2[cur.first])
				{
					if(vis[nxt])    continue;
					dis[nxt] = cur.second+1;
					vis[nxt] = 1;
					q.push({nxt,dis[nxt]});
				}
			}
			while(p[i].v1==s && i<=n)
			{
				p[i].res = w[p[i].v1]+w[p[i].v2]+t*dis[p[i].v2];
				i++;
			}
		}
		sort(p+1,p+q+1,cmp2);
		for(int i = 1; i <= q; i++)    cout << p[i].res << "\n";
		return 0;
	}
	for(int i = 1; i <= n; i++)
	{
		cin >> k;
		for(int j = 1; j <= k; j++)
		{
			cin >> a >> t;
			add(m+i,a,t);
		}
	}
	for(int i = 1; i <= q; i++)
	{
		cin >> x >> y;
		while(!qu.empty())    qu.pop();
		for(int j = 1; j <= n+m; j++)    inq[j] = 0;
		for(int j = 1; j <= n+m; j++)    dis[j] = INF;
		dis[x] = 0;
		qu.push(x);
		inq[x] = 1;
		while(!qu.empty())
		{
			long long cur = qu.front();
			inq[cur] = 0;
			qu.pop();
			for(auto nxt : e[cur])
			{
				if(dis[nxt.first] > dis[cur]+nxt.second)
				{
					dis[nxt.first] = dis[cur]+nxt.second;
					if(!inq[nxt.first])
					{
						inq[nxt.first] = 1;
						qu.push(nxt.first);
					}
				}
			}
		}
		cout << dis[y]+w[x]+w[y] << "\n";
	}
	return 0;
}
