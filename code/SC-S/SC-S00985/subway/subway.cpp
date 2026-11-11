#include<bits/stdc++.h>

using namespace std;

array<array<long long , 510> , 510> dis;
array<int , 510> cnt;

array<vector<pair<int , int> > , 510> sub;
array<long long , 500100> val;

array<vector<pair<int , int> > , 500100> sta;

int x = 0 , y = 0 , cost = 0 , id = 0 , a = 0 , b = 0;
int c = 0 , n = 0  , m = 0 , d = 0 , q = 0;

long long ans = 0 , tmp = 0;

int i = 0 , j = 0 , k = 0;

signed main()
{
	freopen("subway.in" , "r" , stdin);
	freopen("subway.out" , "w" , stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr); 
	
	cin >> c >> n >> m >> d >> q; 
	
	for(int i = 1;i <= m;++ i) cin >> val[i];
	
	for(int i = 1;i <= n;++ i)
	{
		cin >> cnt[i];
		
		for(int x = 1;x <= cnt[i];++ x)
		{
			cin >> tmp >> cost;
			
			sta[tmp].emplace_back(i , cost);
			sub[i].emplace_back(tmp , cost);
		}
	}
	
	for(int i = 1;i <= n;++ i)
	{
		for(int j = 1;j <= n;++ j)
		{
			dis[i][j] = (i == j ? 0 : 1e18);
		}
	}
	
	for(int i = 1;i <= n;++ i)
	{
		for(int x = 1;x <= cnt[i];++ x)
		{
			id = sub[i][x - 1].first , tmp = sub[i][x - 1].second;
			
			for(auto it : sta[id])
			{
				if(i == it.first) continue;
				dis[i][it.first] = min(dis[i][it.first] , 1ll * (tmp + it.second));
			}
		}
	}
	
	for(i = 1;i <= n;++ i)
	{
		for(j = 1;j <= n;++ j)
		{
			if(dis[i][j] == 1e18) dis[i][j] = -1;
		}
	}
	
	for(i = 1;i <= n;++ i)
	{
		for(k = 1;k <= n;++ k)
		{
			if(dis[i][k] == -1 || i == k) continue;
			 
			for(j = i + 1;j <= n;++ j)
			{
				if(dis[k][j] == -1) continue;
				
				if(dis[i][j] == -1 || dis[i][k] + dis[k][j] < dis[i][j])
				{
					dis[i][j] = dis[i][k] + dis[k][j];
				}
			}
		}
	}
	
	for(int i = 1;i <= q;++ i)
	{
		cin >> x >> y;
		ans = 1e18;
		
		for(auto itx : sta[x]) for(auto ity : sta[y])
		{
			a = itx.first , b = ity.first;
			if(a > b) swap(a , b);
			if(dis[a][b] == -1) continue;
			ans = min(ans , dis[a][b] + itx.second + ity.second);
		}
		
		cout << ans + val[x] + val[y] << '\n';
	}
	
	cout << endl;
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
 } 