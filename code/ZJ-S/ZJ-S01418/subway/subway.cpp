#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int M=5000010;
const int N=1000;
ll x, y;
ll c, n, m, d, q;//测试点样例，线路数目，站数目，最多线路数，计划数量 
struct Way//i线路经过站数，i线路经过的j个站， i线厅->站台的t 
{
	ll k;
	ll a[N];
	ll t[N];
 } way[N];
ll w[M];//i线地铁口->站厅的t
struct Map
{
	vector<ll> sta;
	vector<ll> wa;
}mapp[N];//哪里可以到i站 
bool vis[N];
vector<int> cur[N];
int find1(ll x, vector<ll> p)
{
	for(ll i = 0; i < (ll)sizeof(p); i++)
	{
		if(p[i] == x) return i;
	}
	return 0;
}
int find2(ll x, ll p[N])
{
	for(int i = 1; i <= sizeof(p); i++)
	{
		if(p[i] == x) return i;
	}
	return 0;
}
ll maxn = -1e18;
void dfs(ll loc, ll des, ll cnt)
{
	cout << 1;
	ll f = find1(des, mapp[loc].sta);
	if(f)
	{
		ll f2=find2(des,way[mapp[loc].wa[f]].a);
		cnt += way[mapp[loc].wa[f]].t[f2];
		cnt += w[des];
		maxn = max(maxn, cnt);
		return ;
	}
	ll f2 = 1;
	for(int i : mapp[loc].sta)
	{
		if(!vis[i])
		{
			cout << i;
			vis[i] = 1;
			dfs(i, des, cnt+way[mapp[loc].wa[f2]].t[find2(i,way[mapp[loc].wa[f2]].a)]+way[mapp[loc].wa[i]].t[find2(loc,way[mapp[loc].wa[f2]].a)]);
			vis[i] = 0;
		}
		++f2;
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
//	freopen("subway.in","r",stdin);			//不要忘记打开！！！！！ 
//	freopen("subway.out","w",stdout);			//不要忘记打开！！！！！ 
	cin >> c >> n >> m >> d >> q;
	if(c == 0)
	{
		for(int i = 1; i <= m; i++)
		{
			cin >> w[i];
		}
		for(int i = 1; i <= n; i++)
		{
			cin >> way[i].k;
			for(int j = 1; j <= way[i].k; j++)
			{
				cin >> way[i].a[j] >> way[i].t[j];
			}
			for(int j = 1; j <= way[i].k; j++)
			{
				for(int k = j+1; k <= way[i].k; k++)
				{
					mapp[way[i].a[k]].sta.push_back(way[i].a[j]);
					mapp[way[i].a[j]].sta.push_back(way[i].a[k]);
//					cout << k << " " << j << " " << way[i].a[k] << " " << way[i].a[j] << '\n';
					mapp[way[i].a[k]].wa.push_back(i);
					mapp[way[i].a[j]].wa.push_back(i);
				}
			}
		}
		for(int i = 1; i <= m; i++)
		{
//			cout << "!!" << i << '\n';
			for(int j = 0; j < mapp[i].sta.size(); j++)
			{
//				cout << mapp[i].sta[j] << " " << mapp[i].wa[j] << '\n';
			}
		}
		while(q--)
		{
			maxn = -1e18;
			cin >> x >> y;
			vis[x] = 1;
			dfs(x, y, w[x]);
			cout << maxn << '\n';
		}
	}
	
	return 0;
}
