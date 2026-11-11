#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e6 + 5;
int C , T;
int n , a[N] , f[N] , g[N] , d ,ans;
int ch[N];
vector <int> v;
bool check(int l , int r)
{
	int last = (v.empty() ? l : f[v[v.size() - 1]]);
	while(last < r)
	{
		if(!v.empty() && v[v.size() - 1] == last)
		{
//			cout << "noo (" << l << "," << r << ")\n";
//			cout << last << endl; 
			return 0;
		}
		v.push_back(last);
		last = f[last];
	}
	if(v.empty() || v[v.size() - 1] != r)
	{
		v.push_back(r);
	 } 
//	cout << "path (" << l << "," << r << "):";
//	for(auto i : v)
//	{
//		cout << i << ",";
//	}
//	cout << endl;
	int cnt = 0;
	for(int i = 0;i < ((int)(v.size())) - 2;i ++)
	{
		if(i < 0) continue;
		//cnt += (v[i + 1] - max(g[v[i + 2]] , v[i] + 1));
		cnt += (min(f[v[i]] , r) - max(g[min(f[f[v[i]]] , r)] , v[i] + 1));
		if(cnt >= 2) return 0;
	} 
	v.pop_back();
	if(!v.empty()) v.pop_back();
	return cnt == 1;
}
void solve()
{
	cin >> n >> d;
	for(int i = 1;i <= n;i ++)
	{
		cin >> a[i];
	}
	for(int i = 1;i <= n;i ++)
	{
		g[i] = 1e9;
		f[i] = 0;
		for(int j = 1;j <= n;j ++)
		{
			if(abs(a[i] - a[j]) > d) continue;
			if(j >= i) f[i] = max(f[i] , j);
			if(j <= i) g[i] = min(g[i] , j);
		}
		//cout << f[i] << " ";
	}
	//cout << endl;
	f[n] = n + 1;
	g[1] = 0;
	ans = 0;
	for(int i = 1;i <= n;i ++)
	{
		v.clear();
		for(int j = i;j <= n;j ++)
		{
			//if(i == 8) cout << check(i , j) << " ";
			if(check(i , j))
			{
				ans ++;
			}
		}
	}
	cout << ans << endl;
}
signed main()
{
	freopen("migrate.in" , "r" , stdin);
	//freopen("migrate.out" , "w" , stdout);
	cin >> C >> T;
	while(T --)
	{
		solve();
	}
    return 0;
}
//Expected 24pts
//mondayrain

//bu yao tian cuo zhun kao zheng hao!!!!!!!!!!!!!!!!!!!!
//bu yao xie cuo wen jian ming
//bu yao bu kai freopen
//bu yao bu kai longlong
//bu yao kai xiao shu zu

/*
0 1
5 2
1 2 4 5 7
*/
