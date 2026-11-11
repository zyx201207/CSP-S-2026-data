#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5003;
const int INF = 0x3f3f3f3f3f3f3f3f;
int C, T;
int n, d, a[N];
int f[N][N], mi[N];
int ans = 0;
inline int read()
{
	int f = 1, res = 0, c = getchar();
	while(!('0' <= c && c <= '9')){ if(c == '-') f = -1; c = getchar();}
	while('0' <= c && c <= '9'){ res = res*10 + c - '0'; c = getchar();}
	return f * res;
}

void biu(int x)
{
	for(int i = x+1;i <= n && a[i]-a[x] <= d;i++)
		f[i][mi[x]+1] += f[x][mi[x]], mi[i] = min(mi[i], mi[x]+1);
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	C = read(), T = read();
	while(T--)
	{
		ans = 0;
		n = read(), d = read();
		for(int i = 1;i <= n;i++) a[i] = read();
		for(int u = 1;u < n;u++)
		{
			memset(f, 0, sizeof f);
			memset(mi, 0x3f, sizeof mi);
			f[u][0] = 1, mi[u] = 0;
			biu(u);
			for(int v = u+1;v <= n;v++)
			{
				if(mi[v] == INF) break;
				if(f[v][mi[v]] == 2) ans++;
				//else if(f[v][mi[v]] > 2) break;
				biu(v);
			}
			/*
			for(int i = u;i <= n;i++)
				if(mi[i] < INF)
					cout << f[i][mi[i]] << " ";
			cout << "\n";
			* */
		}
		
		
		cout << ans << "\n";
	}
	
	return 0;
}
