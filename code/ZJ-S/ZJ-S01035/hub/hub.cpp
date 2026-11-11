#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e6 + 5,maxn = 1005;
vector <int> G [N];
int vis [N],f [N],viss [N];
int c,T;
int n,k;
int ans;
int dis [maxn] [maxn],dep [maxn],fa [maxn];
bool check ()
{
	int rt = 0;
	for (int i = 1;i <= n;i ++)
		if (vis [i])
		{
			rt = i;
			break;
		}
	stack <int> s;
	s.push (rt);
	while (! s.empty ())
	{
		int u = s.top ();s.pop ();
		f [u] = 0;
		for (int v : G [u])
		{
			if (! f [v]) continue;
			s.push (v);
		}
	}
	rt = 0;
	for (int i = 1;i <= n;i ++)
		if (f [i])
		{
			rt = i;
			break;
		}
	if (! rt) return 1;
	s.push (rt);
	while (! s.empty ())
	{
		int u = s.top ();s.pop ();
		f [u] = 0;
		for (int v : G [u])
		{
			if (! f [v]) continue;
			s.push (v);
		}
	}
	for (int i = 1;i <= n;i ++)
		if (f [i]) return 0;
	return 1;
}
int cal ()
{
	int sum = 0;
	for (int i = 1;i <= n;i ++)
	{
		for (int j = 1;j <= n;j ++)
		{
			if (vis [i]) continue;
			if (! vis [j]) continue;
			sum = max (sum,dis [i] [j]);
		}
	}
	return sum;
}
void dfs (int h)
{
	if (h == n + 1)
	{
		int s = 0;
		for (int i = 1;i <= n;i ++) s += vis [i],f [i] = vis [i];
		if (s != k) return ;
//		for (int i = 1;i <= n;i ++) cout << vis [i] << ' ';
//		cout << endl;
		if (check ())
		{
			ans = min (ans,cal ());
//			for (int i = 1;i <= n;i ++)
//				if (vis [i])  cout << i << ' ';
//			cout << endl;
		}
		return ;
	}
	vis [h] = 0;
	dfs (h + 1);
	vis [h] = 1;
	dfs (h + 1);
}
void dfss (int u,int faa)
{
//	cout << u << ' ' << faa << endl;
	viss [u] = 1;
	for (int v : G [u])
	{
		if (v == faa) continue;
		if (viss [v]) continue;
		dep [v] = dep [u] + 1;
		fa [v] = u;
		dfss (v,u);
	}
	return ;
}
void solve ()
{
	cin >> n >> k;
	for (int i = 1;i <= n;i ++) G [i].clear (),vis [i] = 0;
	for (int i = 1;i <= n;i ++)
		for (int j = 1;j <= n;j ++) dis [i] [j] = 1e18;
	for (int i = 1;i < n;i ++)
	{
		int u,v;
		cin >> u >> v;
		G [u].push_back (v);
		G [v].push_back (u);
	}
	for (int rt = 1;rt <= n;rt ++)
	{
		dep [rt] = 0;
		for (int i = 1;i <= n;i ++) viss [i] = 0;
		dfss (rt,0);
	//	cout<<"111\n";
		for (int i = 1;i <= n;i ++)
		{
			for (int j = 1;j <= n;j ++)
			{
				if (i == j) continue;
				if (i == rt) dis [i] [j] = dis [j] [i] = min (dis [i] [j],dep [j]);
				else
				{
					int x = i,y = j;
					if (dep [x] < dep [y]) swap (x,y);
					int dd = 0;
					while (dep [x] > dep [y]) x = fa [x],dd ++;
					while (x != y) dd += 2,x = fa [x],y = fa [y];
					dis [i] [j] = dis [j] [i] = min (dis [i] [j],dd);
				}
			}
		}
	}
	ans = 1e18;
	dfs (1);
	cout << ans << endl;
}
signed main ()
{
	ios::sync_with_stdio(false);cin.tie(nullptr);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,T;
	cin >> c >> T;
	while (T --) solve ();
	return 0;
}