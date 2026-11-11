#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5 + 10,inf = (1 << 15);
int c,n,m,d,q,w[N],k[N],a,t,num[N + 500],ans[N / 5];
bool flag[N + 500];
struct query{
	int idx,x,y;
}qr[N / 5];
bool cmp(query x,query y)
{
	return x.x < y.y;
}
struct edge{
	int v,w;
};
vector<edge> e[N + 500];
struct data{
	int idx,val;
	friend operator<(const data &x,const data &y){
		return x.val < y.val;
	}
};
priority_queue<data> q1;
void dij()
{
	while(!q1.empty())
	{
		data u = q1.top();
		q1.pop();
		if(flag[u.idx])
		{
			continue;
		}
		flag[u.idx] = true;
		for(int i = 0;i < e[u.idx].size();i++)
		{
			edge v = e[u.idx][i];
			if(num[v.v] > num[u.idx] + v.w)
			{
				num[v.v] = num[u.idx] + v.w;
				q1.push({v.v,num[v.v]});
			}
		}
	}
}
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1;i <= m;i++)
	{
		cin >> w[i];
	}
	for(int i = 1;i <= n;i++)
	{
		cin >> k[i];
		for(int j = 1;j <= k[i];j++)
		{
			cin >> a >> t;
			e[m + i].push_back({a,t});
			e[a].push_back({m + i,t});
		}
	}
	for(int i = 1;i <= q;i++)
	{
		cin >> qr[i].x >> qr[i].y;
		qr[i].idx = i;
	}
	sort(qr + 1,qr + 1 + q,cmp);
	for(int i = 1;i <= q;i++)
	{
		if(qr[i].x != qr[i - 1].x)
		{
			for(int i = 1;i <= m + n;i++)
			{
				num[i] = inf;
				flag[i] = false;
			}
			num[qr[i].x] = 0;
			q1.push({qr[i].x,0});
			dij();
		}
		ans[qr[i].idx] = w[qr[i].x] + num[qr[i].y] + w[qr[i].y];
	}
	for(int i = 1;i <= q;i++)
	{
		cout << ans[i] << "\n";
	}
	return 0;
}
