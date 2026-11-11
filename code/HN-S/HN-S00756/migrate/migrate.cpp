#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N = 2e6 + 5;

int c, t, n, f[N][3], p[N];
int RT[N], len, fa[N];
ll d, a[N], ans;

vector<int> v[N];

void dfs(int x){
	ans += f[x][0] + f[x][1];
	// cout << x << ' ' << fa[x] << ' ' << ans << ' ' << f[x][0] << ' ' << f[x][1] << ' ' << f[x][2] << '\n';
	for(int i : v[x]){
		fa[i] = x;
		if(x - i == 1)f[i][0] = 0, f[i][1] = f[x][0] + f[x][1], f[i][2] = f[x][2] + fa[x] - x;
		else if(x - i == 2){
			if(p[x - 1] == fa[x])f[i][0] = f[x][2];
			f[i][0] += (p[x - 1] - x);
			if(p[x - 1] < fa[x] - 1)f[i][1] = f[x][0];
			if(p[x - 1] < fa[x])f[i][2] = f[x][2], f[i][1] += f[x][1];
			f[i][2] += (p[x] - p[x - 1]);
		}else{
			if(p[x - 1] == fa[x] && p[x - 2] < fa[x])f[i][0] = f[x][2];
			f[i][0] += (p[x - 1] - p[x - 2]);
			if(p[x - 1] < fa[x] - 1)f[i][1] = f[x][0];
			if(p[x - 1] < fa[x])f[i][1] += f[x][1];
			if(p[x - 1] < fa[x])f[i][2] += f[x][2];
			f[i][2] += (p[x] - p[x - 1]);
		}
		dfs(i);
	}
}

int main(){
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	for(; t; t--){
		cin >> n >> d;
		for(int i = 1; i <= n; i++)
			v[i].clear(), f[i][0] = f[i][1] = f[i][2] = 0;
		len = 0;
		for(int i = 1; i <= n; i++)
			cin >> a[i];
		for(int i = n; i >= 1; i--){
			p[i] = upper_bound(a + 1, a + n + 1, a[i] + d) - a - 1;
			if(p[i] == i)RT[++len] = i;
			else v[p[i]].push_back(i);
		}
		ans = 0;
		for(int i = 1; i <= len; i++)
			for(int j : v[RT[i]]){
				f[j][0] = f[j][1] = f[j][2] = 0;
				fa[j] = RT[i];
				dfs(j);
			}
		cout << ans << '\n';
	}
	return 0;
}
/*
0 1
10 3
-1000000000000000000 -999999999999999997 -999999999999999994 -999999999999999993 -999999999999999992 -999999999999999991 -999999999999999990 -999999999999999989 -999999999999999986 -999999999999999983

9
*/