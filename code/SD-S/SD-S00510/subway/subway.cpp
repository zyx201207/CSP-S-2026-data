#include<bits/stdc++.h>
using namespace std;
const long long M = 1e18 + 50;
long long c,n,m,d,Q,x,y,_k,w[500050],minn;
struct node
{
	int x;
	long long w;
	friend bool operator <(const node a,const node b)
	{
		return a.w > b.w;
	}
};
long long dp[505][505],v[505];
node a[21][500050];
long long k[500050];
vector<node> e[505];
priority_queue<node> q;
void dij(int s)
{
	for(int i = 1;i <= n;i++)
	{
		dp[s][i] = M;
		v[i] = 0;
	}
	dp[s][s] = 0;
	q.push({s,0});
	while(!q.empty())
	{
		node f = q.top();
		q.pop();
		if(v[f.x] == 1)continue;
		v[f.x] = 1;
		for(auto i : e[f.x])
		{
			if(dp[s][i.x] > dp[s][f.x] + i.w)
			{
				dp[s][i.x] = dp[s][f.x] + i.w;
				if(!v[i.x])q.push({i.x,dp[s][i.x]});
			}
		}
	}
	return;
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld %lld %lld %lld %lld",&c,&n,&m,&d,&Q);
	for(int i = 1;i <= m;i++)scanf("%lld",&w[i]);
	for(int i = 1;i <= n;i++)
	{
		cin >> _k;
		for(int j = 1;j <= _k;j++)
		{
			scanf("%lld %lld",&x,&y);
			a[++k[x]][x] = {(int)i,y};
		}
	}
	/*cerr << endl;
	for(int i = 1;i <= m;i++)
	{
		for(int j = 1;j <= k[i];j++)
		{
			cerr << a[j][i].x << " ";
		}
		cerr << endl;
	}
	cerr << endl;*/
	for(int i = 1;i <= m;i++)
	{
		for(int j = 1;j <= k[i];j++)
		{
			for(int h = j + 1;h <= k[i];h++)
			{
				e[a[j][i].x].push_back({a[h][i].x,a[j][i].w + a[h][i].w});
				e[a[h][i].x].push_back({a[j][i].x,a[j][i].w + a[h][i].w});
			}
		}
	}
	/*for(int i = 1;i <= n;i++)
	{
		for(auto j : e[i])cerr << j.x << "," << j.w << " ";
		cerr << endl;
	}
	cerr << endl;*/
	for(int i = 1;i <= n;i++)
	{
		dij(i);
	}
	//cerr << dp[1][2] << " " << dp[2][1] << endl;
	while(Q--)
	{
		minn = M;
		scanf("%lld %lld",&x,&y);
		for(int j = 1;j <= k[x];j++)
		{
			for(int h = 1;h <= k[y];h++)
			{
				minn = min(minn,a[j][x].w + a[h][y].w + dp[a[j][x].x][a[h][y].x]);
			}
		}
		printf("%lld\n",minn + w[x] + w[y]);
	}
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

Oct31==Dec25?

0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3

*/
