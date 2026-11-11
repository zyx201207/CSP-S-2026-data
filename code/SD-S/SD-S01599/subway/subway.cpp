#include<algorithm>
#include<iostream>
#include<vector>

using namespace std;

typedef long long LL;
const int N = 503 , M = 1e5 + 5;
const LL INF = 1e18;

struct Node
{
	int x;
	LL vl;
};

LL to[N][N] = {0};
//LL hp_to[N][N] = {0};

LL w[N] = {0};

int n , m , c , q , d;

vector <Node> vlist[M];
//vector <int> can[N];

void build()
{
	for(int i = 1;i <= n;++i)
	{
		for(int j = 1;j <= n;++j)
		{
			if(i == j)
			{
				continue;
			}
			to[i][j] = INF;
		}
	}
	
	
	for(int i = 1;i <= m;++i)
	{
		for(int j = 0;j < vlist[i].size();++j)
		{
//			int n_use = vlist[i][j];
//			can[n_use].push_back(i)
			for(int k = 0;k < vlist[i].size();++k)
			{
				if(j == k)
				{
					continue;
				}
				
				Node x = vlist[i][j];
				Node y = vlist[i][k];
				if(to[x.x][y.x] > x.vl + y.vl)
				{
					to[x.x][y.x] = x.vl + y.vl;
				}
				to[y.x][x.x] = to[x.x][y.x];
			}
		}
	}
	
	for(int k = 1;k <= n;++k)
	{
		for(int i = 1;i <= n;++i)
		{
			for(int j = 1;j <= n;++j)
			{
				if(to[i][k] + to[k][j] < to[i][j])
				{
					to[i][j] = to[i][k] + to[k][j];
					to[j][i] = to[i][j];
				}
			}
		}
	}
	
//	for(int i = 1;i <= n;++i)
//	{
//		for(int j = 1;j <= n;++j)
//		{
//			cout << to[i][j] << " ";
//		}
//		cout << endl;
//	}
	
	return ;
}

LL sol(int x , int y)
{
	LL res = INF;
	for(int i = 0;i < vlist[x].size();++i)
	{
		for(int j = 0;j < vlist[y].size();++j)
		{
			LL vl_x = vlist[x][i].vl;
			LL vl_y = vlist[y][j].vl;
			
			LL vl = to[vlist[x][i].x][vlist[y][j].x];
			
			res = min(res , vl_x + vl_y + vl);
		}
	}
	return res;
}

int main()
{
	freopen("subway.in" , "r" , stdin);
	freopen("subway.out" , "w" , stdout);
	
	cin >> c >> n >> m >> d >> q;
	
	for(int i = 1;i <= m;++i)
	{
		cin >> w[i];
	}
	
	
	
	int t = 0 , sum;
	LL n_vl = 0;
	
	for(int i = 1;i <= n;++i)
	{
		cin >> sum;
		for(int j = 0;j < sum;++j)
		{
			cin >> t >> n_vl;
			vlist[t].push_back({i , n_vl});
		}
	}
	
	
	
	build();
	
	int x = 0 , y = 0;
	
	for(int i = 1;i <= q;++i)
	{
		cin >> x >> y;
		LL res = w[x] + w[y];
		
		LL ans = res + sol(x , y);
		
		cout << ans << endl;
	}
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
/*
fre
fcl
*/
