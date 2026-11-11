#include<bits/stdc++.h>
#define int long long
using namespace std;

int C, T, n, m;
int arr[10010];
pair<int, int> f[10010][10010];

int dfs(int st, int ed)
{
//	cout<<st<<':'<<ed<<endl;
	queue<pair<int, int> > q;
	q.push({st, 0});
	int minn = 0x3f3f3f3f;
	int res = 0;
	while(!q.empty())
	{
		auto p = q.front();
		int d = p.first;
		int v = p.second;
		q.pop();
//		cout<<d<<' '<<v<<endl;
		if(v > minn) break;
		if(d == ed && v == minn)
		{
			res ++;
			continue;
		}
		if(d == ed)
		{
			res = 1;
			minn = v;
			continue;
		}
		
		for(int i = d + 1; i <= n ; i ++)
		{
			if(arr[i] - arr[d] > m) break;
			q.push({i, v + 1});
		}
	}
	return res;
}

void solve1()
{
	int ans = 0;
	cin>>n>>m;
	for(int i = 1; i <= n ; i ++)
	{
		cin>>arr[i];
	}
	
	for(int i = 1; i <= n ; i ++)
	{
		for(int j = i + 3; j <= n; j ++)
		{
			int sol = dfs(i, j);
			if(sol == 2)
			{
//				cout<<i<<' '<<j<<endl;
				ans ++;
			}
		}
	}
	cout<<ans<<endl;
	return;
}

void solve2()
{
	int ans = 0;
	memset(f,0,sizeof f);
	cin>>n>>m;
	for(int i = 1; i <= n ; i ++)
	{
		cin>>arr[i];
	}
	
	for(int k = 1; k <= n ; k ++)
	{
		for(int i = 1; i + k - 1 <= n ; i ++)
		{
			int r = i + k - 1;
			if(arr[r] - arr[i] <= m)
			{
				f[i][r] = {1, 1};
				continue;
			}
			int minn = 0x3f3f3f3f;
			for(int j = i + 1; j < i + k - 1; j ++)
			{
				int sum = f[i][j].second + f[j][r].second;
				if(sum == minn)
				{
					f[i][r].first += f[i][j].first * f[j][r].first;
				}
				if(sum < minn)
				{
					f[i][r].first =  f[i][j].first * f[j][r].first;
					minn = sum;
					f[i][r].second = sum;
				}
			}
			if(f[i][r].first / (f[i][r].second - 1) == 2)
			{
				ans++;
//				cout<<i<<' '<<r<<endl;
			}
		}
	}
	
//	for(int i = 1; i <= n; i ++)
//	{
//		for(int j = 1; j <= n ; j ++)
//		{
//			cout<<(f[i][j].first / (f[i][j].second - 1))<<' ';
//		}
//		cout<<endl;
//	}
	
	cout<<ans<<endl;
	return;
}

signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>C>>T;
	while(T--)
	{
		if(C <= 4)
		{
			solve1();
		}
		solve2();
		
	}
	return 0;
}
