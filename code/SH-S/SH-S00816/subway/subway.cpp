#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

const int N = 505,M = 5e5 + 5;
int w[M],K[N];
long long dis[N][N];
struct Station {int line[25],cur = 0,t[25];} st[M];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	// c = testid
	// n = line number
	// m = station number
	// d = max line number in a station
	// q = plan number
	cin >> c >> n >> m >> d >> q;
	for (int i = 1;i <= m;i++)
		cin >> w[i];
	for (int i = 1;i <= n;i++) {
		cin >> K[i];
		for (int j = 1;j <= K[i];j++) {
			int tmpa,tmpt;
			cin >> tmpa >> tmpt; // station time
			st[tmpa].line[++st[tmpa].cur] = i, 
			st[tmpa].t[st[tmpa].cur] = tmpt;
		}
	}
	memset(dis,0x3f,sizeof dis);
	for (int i = 1;i <= m;i++) {
		for (int j = 1;j <= st[i].cur;j++) {
			for (int k = 1;k <= st[i].cur;k++) {
				if (j == k) dis[st[i].line[j]][st[i].line[k]] = 0;
				else {
					long long tmp = min(dis[st[i].line[j]][st[i].line[k]],1ll * st[i].t[j] + 1ll * st[i].t[k]);
					dis[st[i].line[j]][st[i].line[k]] = dis[st[i].line[k]][st[i].line[j]] = tmp;
				}
			}
		}
	}
	for (int i = 1;i <= n;i++)
		for (int j = 1;j <= n;j++)
			for (int k = 1;k <= n;k++)
				dis[i][j] = min(dis[i][j],dis[i][k] + dis[k][j]);
	while (q--) {
		int XX,YY;
		cin >> XX >> YY;
		long long ans = 1e18;
		for (int i = 1;i <= st[XX].cur;i++)
			for (int j = 1;j <= st[YY].cur;j++)
				ans = min(ans,w[XX] + st[XX].t[i] + dis[st[XX].line[i]][st[YY].line[j]] + st[YY].t[j] + w[YY]);
		cout << ans << '\n';
	}
	return 0;
}
