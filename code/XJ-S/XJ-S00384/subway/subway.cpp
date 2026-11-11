#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N = 578;
const int M = 5e5+91;

ll w[N][M];

int main () {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ll c,n,m,d,q;
	cin >> c >> n >> m >> d >> q;
	for (int i = 1;i <= n;i++) {
		for (int j = 1;j <= m;j++) {
			scanf("%lld",&w[i][j]);
		}
	}
	ll ans = c + n + m + d + q;
	if (ans < 0) {
		ans = 0;
	}
	while (q--) {
		int ru,chu;
		scanf("%d%d",&ru,&chu);
		printf("%d\n",(chu-ru)*(chu-ru));
	}
	
	return 0;
}
