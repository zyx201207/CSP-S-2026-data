#include<bits/stdc++.h>
using namespace std;
struct node
{
	int station,step,line;
	bool way;
};
struct st
{
	int line,num;
};
st tost(int line,int num)
{
	st res;
	res.line = line,res.num = num;
	return res;
}
short c;
int n,m,d,Q,w[500010],k[510],x,y,ans = 1e9;
vector <st> stations[500010];
vector <int> a[510],t[510];
bitset <500010> vis;
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> n >> m >> d >> Q;
	for(int i = 1;i <= m;i++) cin >> w[i];
	for(int i = 1;i <= n;i++)
	{
		cin >> k[i];
		for(int j = 1;j <= k[i];j++)
		{
			int A,T;
			cin >> A >> T;
			a[i].push_back(A);
			t[i].push_back(T);
			stations[a[i][j]].push_back(tost(i,j));
		}
	}
	for(int i = 1;i <= Q;i++)
	{
		cin >> x >> y;
		int ans = w[x] + w[y];
		queue <node> q;
		for(st station : stations[x])
		{
			node s;
			s.station = station.num,s.step = w[x] + t[station.line][station.num],s.line = station.line;
			s.way = true;
			q.push(s);
			s.way = false;
			q.push(s);
		}
		vis[x] = true;
		while(!q.empty())
		{
			node u = q.front();
			q.pop();
			node v = u;
			if(v.way)
			{
				v.station = u.station + 1;
				if(a[v.line][v.station] == y) ans = min(ans,v.step + t[v.line][v.station] + w[y]);
				if(v.station <= k[v.line])
				{
					vis[a[v.line][v.station]] = true;
					for(st station : stations[a[v.line][v.station]])
					{
						if(station.line == v.line) continue;
						v.step += t[v.line][v.station] + t[station.line][station.num];
						v.line = station.line;
						v.station = station.num;
						v.way = true;
						q.push(v);
						v.way = false;
						q.push(v);
					}
				}
			}
			else
			{
				v.station = u.station - 1;
				if(a[v.line][v.station] == y) ans = min(ans,v.step + t[v.line][v.station] + w[y]);
				if(v.station >= 1)
				{
					vis[a[v.line][v.station]] = true;
					for(st station : stations[a[v.line][v.station]])
					{
						if(station.line == v.line) continue;
						v.step += t[v.line][v.station] + t[station.line][station.num];
						v.line = station.line;
						v.station = station.num;
						v.way = true;
						q.push(v);
						v.way = false;
						q.push(v);
					}
				}
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
