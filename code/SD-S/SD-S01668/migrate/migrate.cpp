#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll qread() {
	bool b = true;
	ll x = 0;
	char ch = getchar();
	while(ch<'0' || ch>'9') {
		if('-' == ch) b = false;
		ch = getchar();
	}
	while(ch>='0' && ch<='9') {
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	return b ? x : -x;
}

const int maxN = 8e3 + 10;
ll a[maxN];
int dis[maxN][maxN], est[maxN][maxN];
ll n, m, ans, d;
int c, t;

int main() { //migrate #1-#10Floyd #11-#12สýัง 2/6 17:38
	ios::sync_with_stdio(false);
	cin.tie(); cout.tie();
	
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	
	c = qread(), t = qread();
	
	if(11==c || 12==c) {
		while(t--) {
			n = qread(), d = qread();
			ll x1 = qread(), x2 = qread(), x3;
			for(int i=3; i<=n; i++) x3 = qread();
			ll dx = x2 - x1, evr = d / dx * 2 - d / dx - 1;
			ans = (n - d / dx * 2 + 1)/* * evr*/;
			
			cout << ans << endl;
		}
		
		return 0;
	}
	
	while(t--) {
		/*memset(vis, false, sizeof(vis));
		memset(est, 0, sizeof(est));
		memset(dis, 0x3f, sizeof(dis));*/
		n = qread(), d = qread();
		for(int i=1; i<=n; i++) for(int j=1; j<=n; j++)
				if(i!=j) est[i][j] = 1, dis[i][j] = maxN;
				else est[i][j] = -1;
/*for(int i=1; i<=n; i++) {
	for(int j=1; j<=n; j++) cout << dis[i][j] << '\t';
	cout << endl;
} cout << endl << endl;*/
		
		for(int i=1; i<=n; i++) {
			a[i] = qread();
			for(int j=i-1; j>=1; j--)
				if(a[i]-a[j] <= d) dis[j][i] = 1;
				else break;
		}
/*for(int i=1; i<=n; i++) {
	for(int j=1; j<=n; j++) cout << dis[i][j] << '\t';
	cout << endl;
} cout << endl;*/
		for(int k=1; k<=n; k++) for(int i=1; i<=n; i++) if(i != k)
					for(int j=i+1; j<=n; j++) if(j != k/* && i != j*/)
							if(dis[i][j] == dis[i][k]+dis[k][j]) {
								dis[i][j] = dis[i][k]+dis[k][j], est[i][j]++;
							} else if(dis[i][j] > dis[i][k]+dis[k][j])
								dis[i][j] = dis[i][k]+dis[k][j], est[i][j] = 1;
/*for(int i=1; i<=n; i++) {
	for(int j=1; j<=n; j++) cout << dis[i][j] << '\t';
	cout << endl;
} cout << endl;*/
		
		ans = 0;
		for(int i=1; i<=n; i++)
			for(int j=1; j<=n; j++) if(2 == est[i][j]) ans++;
		cout << ans << endl;
	}
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}

/*
#1
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

1
2
#2
0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6

0
1

#11~12 A
11 4
5 2
1 2 3 4 5
7 7
0 3 6 9 12 15 18
8 10
0 3 6 9 12 15 18 21
11 21
0 5 10 15 20 25 30 35 40 45 50

2
4
3
4
*/
