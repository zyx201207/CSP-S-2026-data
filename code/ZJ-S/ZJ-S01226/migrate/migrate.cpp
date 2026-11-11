#include<bits/stdc++.h>
#define int long long
using namespace std;
int c, T, n, d, x[2000005], L[2000005], R[2000005], LL[2000005], RR[2000005], res;
vector<int> vec;
vector< pair<int, int> > Segs;
signed main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin >> c >> T;
	while (T--){
		cin >> n >> d;
		for (int i = 0; i <= n + 1; i++)
			L[i] = R[i] = LL[i] = RR[i] = 0;
		for (int i = 1; i <= n; i++)
			cin >> x[i];
		int l = 1;
		Segs.clear();
		for (int i = 2; i <= n; i++){
			if (x[i] - x[i - 1] > d){
				Segs.emplace_back(l, i - 1);
				l = i;
			}
		}
		Segs.emplace_back(l, n);
		res = 0;
		for (auto tmp : Segs){
			int sl = tmp.first, sr = tmp.second;
			int pos = sl;
			for (int i = sl; i <= sr; i++){
				while (pos <= sr && x[pos] < x[i] - d)
					pos++;
				L[i] = pos;
			}
			pos = sr;
			for (int i = sr; i >= sl; i--){
				while (pos >= sl && x[pos] > x[i] + d)
					pos--;
				R[i] = pos;
			}
			pos = sl - 1;
			for (int i = sl; i <= sr; i++){
				while (pos < sr && R[pos + 1] <= i)
					pos++;
				LL[i] = pos;
			}
			pos = sr + 1;
			for (int i = sr; i >= sl; i--){
				while (pos > sl && L[pos - 1] >= i)
					pos--;
				RR[i] = pos;
			}
			vec.clear();
			for (int i = sl + 1; i + 1 < sr; i++){
				int u = LL[i + 1], v = RR[i];
				if (R[u] == i + 1 && L[v] == i){
					if (u == i || v == i || u == i + 1|| v == i + 1)
						continue;
					vec.emplace_back(i);
				//	cerr << i << "\n";
				}
			}
			for (int i = 0; i < vec.size(); i++){
				int ll = (i == 0 ? sl : min(vec[i - 1], L[vec[i] + 1]));
				int rr = (i + 1 == vec.size() ? sr : max(vec[i + 1] + 1, R[vec[i]]));
				int u = LL[vec[i] + 1], v = RR[vec[i]];
			//	cerr << vec[i] << " " << ll << " " << rr << " " << u << " " << v << "\n";
				if (u < ll || v > rr)
					continue;
				else
					res = (res + (u - ll + 1) * (rr - v + 1));
			//	cerr << res << "\n";
			}
		}
		cout << res << "\n";
	}
	return 0;
}
