#include <bits/stdc++.h>

#define ll long long

#define pii pair<long long, long long>

using namespace std;

priority_queue<ll> pq;

ll c, n, m, d, q, w[500005], op[5000005], tk[5000005], kd[5000005];

int main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1;i <= m;i ++){
		cin >> w[i];
	}
	for(int i = 1;i <= n;i ++){
		ll k;
		cin >> k;
		if(i == 1){
			for(int j = 1;j <= k;j ++){
				ll x, y;
				cin >> x >> y;
				op[x] = y;
				kd[x] ++;
			}
		}
		else{
			for(int j = 1;j <= k;j ++){
				ll x, y;
				cin >> x >> y;
				if(op[x] != 0){
					pq.push(- (op[x] + y));
				}
			}
		}
	}
	for(int i = 1;i <= q;i ++){
		int rx, ry;
		cin >> rx >> ry;
		if(kd[rx] == kd[ry])	cout << w[rx] + w[ry] << "\n";
		else	cout << w[rx] + w[ry] + -(pq.top()) << "\n";
	}
	return 0;
}
