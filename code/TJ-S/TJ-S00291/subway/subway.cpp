#include<bits/stdc++.h>
using namespace std;
#define int long long

int ttt,n,m,d,qo;
int gm[600005];
int b[600005];
int ji[801][801] , dp[805][805];
struct ysr
{
	int p,w;
};
vector<ysr> vm[600005] , vd[801] , vdd[801];
vector<ysr> u[801];
struct zdj
{
	int p,w;
	int friend operator < (zdj a,zdj b)
	{
		return a.w > b.w;
	}
};
priority_queue <zdj> q;

signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> ttt >> n >> m >> d >> qo;
	for(int i = 1;i <= m;i++) cin >> gm[i];
	for(int i = 1;i <= n;i++)
	{
		int t;
		cin >> t;
		for(int j = 1;j <= t;j++)
		{
			int t1,t2;
			cin >> t1 >> t2;
			b[t1]++;
			vm[t1].push_back({i,t2});
			vd[i].push_back({t1,t2});
		}
	}
	for(int i = 1;i <= n;i++)
	{
		for(int j = 0;j < vd[i].size();j++)
		{
			if(b[vd[i][j].p] > 1) vdd[i].push_back(vd[i][j]); 
		}
	}
	for(int i = 1;i <= n;i++)
	{
		for(int j = 1;j <= n;j++)
		{
			if(i == j) continue;
			dp[i][j] = -1;
			ji[i][j] = -1;
		}
	}
	
	for(int i = 1;i <= m;i++)
	{
		if(b[i] <= 1) continue;
		for(int j = 0;j < vm[i].size();j++)
		{
			for(int z = 0;z < vm[i].size();z++)
			{
				if(j == z) continue;
				//cout << vm[i][j].p << " " << vm[i][z].p << '\n';
				int o = vm[i][j].w + vm[i][z].w;
				if(ji[vm[i][j].p][vm[i][z].p] == -1)
				{
					ji[vm[i][j].p][vm[i][z].p] = o;
					ji[vm[i][z].p][vm[i][j].p] = o;
					continue;
				}
				ji[vm[i][j].p][vm[i][z].p] = min(ji[vm[i][j].p][vm[i][z].p] , o);
				ji[vm[i][z].p][vm[i][j].p] = min(ji[vm[i][z].p][vm[i][j].p] , o);
			}
		}
	}
	
	for(int i = 1;i <= n;i++)
	{
		for(int j = 1;j <= n;j++)
		{
			if(ji[i][j] != 0 and ji[i][j] != -1)
			{
				u[i].push_back({j,ji[i][j]});
			}
		}
	}
	//for(int i = 1;i <= n;i++) cout << u[i].size() << " "; cout << '\n';
	for(int i = 1;i <= n;i++)
	{
		while(!q.empty()) q.pop();
		q.push({i , 0});
		while(!q.empty())
		{
			zdj xl = q.top();
			//cout << xl.p << " " << xl.w << " ";
			q.pop();
			for(int j = 0;j < u[xl.p].size();j++)
			{
				if(dp[i][u[xl.p][j].p] <= xl.w + u[xl.p][j].w and dp[i][u[xl.p][j].p] != -1) continue;
				dp[i][u[xl.p][j].p] = xl.w + u[xl.p][j].w;
				q.push({u[xl.p][j].p , xl.w + u[xl.p][j].w});
			}
		}
	}
	
//	for(int i = 1;i <= n;i++)
//	{
//		for(int j = 1;j <= n;j++)
//		{
//			cout << dp[i][j] << " ";
//		}
//		cout << '\n';
//	}

	for(int i = 1;i <= qo;i++)
	{
		int ans = 1e17;
		int t1,t2;
		cin >> t1 >> t2;
		for(int j = 0;j < b[t1];j++)
		{
			for(int z = 0;z < b[t2];z++)
			{
				ans = min(vm[t1][j].w + vm[t2][z].w + dp[vm[t1][j].p][vm[t2][z].p] + gm[t1] + gm[t2] , ans);
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
