#include <bits/stdc++.h>

using namespace std;
using ll = long long;

/*int qread() {
	bool b = true;
	int x = 0;
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
}*/
int /*us*/qread() {
	int x = 0;
	char ch = getchar();
	while(ch>='0' && ch<='9') {
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	return x;
}

void qwrite(int x) {
	if(!x) return ;
	qwrite(x/10);
	putchar(x%10 + '0');
}

const int maxN = 500 + 10, maxM = 5e5 + 10;
int w[maxM];
ll n, m, ans, d;
int c, q;

struct edge {
	int k;
	int a[maxN], t[maxN];
} s[maxN];

/*ll dis[maxM][maxM];
bool vis[maxM];
void dfs(int srt, int trg, int cur, int pre, int tm) {
	for(int i=1; i<=s[cur].k; i++) {
		if(i == pre) continue;
		if(s[cur].a[i] == trg) {
			dis[srt][trg] = min(dis[srt][trg],
			 dis[srt][cur]+s[cur].t[i]+s[cur].t[pre])
		}
	}
}*/

int main() { //subway 0' 18:23
	ios::sync_with_stdio(false);
	cin.tie(); cout.tie();
	
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	
	c = qread(), n = qread(), m = qread(), d = qread(), q = qread();
	for(int i=1; i<=m; i++) w[i] = qread();
	for(int i=1; i<=n; i++) {
		s[i].k = qread();
		for(int j=1; j<=s[i].k; j++) s[i].a[j] = qread(), s[i].t[j] = qread();
	}
	/*for(int k=1; k<=m; k++) for(int i=1; i<=m; i++) if(i != k)
				for(int j=i+1; j<=m; j++) if(j != k) {
						if(dis[i][j] > dis[i][k]+dis[k][j]) {
							dis[i][j] = dis[i][k]+dis[k][j]
						}
					}*/
	
	while(q--) {
		int x = qread(), y = qread();
		
		//#7~#11 A ki<=2
		ll ans1 = w[x] + w[y], ans2 = w[x] + w[y];
		for(int id1 = s[x].a[1], pre1 = x, nx; 2==s[id1].k; id1=s[id1].a[nx]) {
			nx = s[id1].a[1] == pre1 ? 2 : 1;
			int pe = 1 == nx ? 2 : 1;
			ans1 += s[id1].t[pe] + s[id1].t[nx];
			if(id1 == y) {
				break;
			}
		}
//		int id2 = s[x].a[2], pre2 = x;
		for(int id2 = s[x].a[1], pre2 = x, nx; 2==s[id2].k; id2=s[id2].a[nx]) {
			nx = s[id2].a[1] == pre2 ? 2 : 1;
			int pe = 1 == nx ? 2 : 1;
			ans1 += s[id2].t[pe] + s[id2].t[nx];
			if(id2 == y) {
				break;
			}
		}
		
		cout << min(ans1, ans2) << endl;
	}
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}

/*
#1
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

32
17
#2
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3

35
16
*/
