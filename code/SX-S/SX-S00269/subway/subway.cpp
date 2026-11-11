#include <bits/stdc++.h>
using namespace std;

struct nd {
	int v, w;
} ndd;
vector<nd> e[1119];
int c, n, m, d, q, k;
int w[500007];
int ao[500007];

void djk(int s) {

}

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	if (c >= 7 && c <= 11) {
		cin >> k;
		int sa, sb, sc, sd;
		for (int i = 1; i <= k; i++) {
			cin >> sa >> sb >> sc >> sd;
			ndd.v = sc;
			ndd.w = sb + sd;
			vector[sa].push_back(ndd);

		}
		int st, en;
		while (q--) {
			cin >> st >> en;
			djk(st);
			int ans = dis[ed] + w[st] + w[en] +;
			cout <<;
		}
	}
	return 0;
}
