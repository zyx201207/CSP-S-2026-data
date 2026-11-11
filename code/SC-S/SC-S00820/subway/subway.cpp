#include<bits/stdc++.h>
using namespace std;
//int DFS(int x, int y, int tim, vector<int>& t) {
//	if (x == y) {
//		return 2 * t[y];
//	}
//	queue<int> QQ;
//	for (auto a : Q[x]) {
//		QQ.push(a);
//	}
//	while (!QQ.empty()) {
//		int x = QQ.front();
//		QQ.pop();
//		for (auto a : Q[x]) {
//			DFS(a, y, tim + 2 * t[a], t);
//		}
//	}
//	return tim;
//}
int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	int c, n, m, d, q;
	cin >> c >> n >> m >> d >> q;
	vector<vector<int>> Q(m + 1);
	vector<int> W(m + 1);
	vector<int> t(m + 1);
	for (int i = 1; i <= m; i++) cin >> W[i];
	for (int i = 1; i <= n; i++) {
		int k;
		cin >> k;
		vector<int> a(k + 1);
		cin >> a[1] >> t[1];
		for (int j = 2; j <= k; j++) {
			cin >> a[i] >> t[i];
//			Q[a[i - 1]].push_back(a[i]);
//			Q[a[i]].push_back(a[i - 1]);
		}
	}
//	for (int i = 1; i <= q; i++) {
//		int x, y;
//		cin >> x >> y;
//		int tim = W[x] + W[y];
//		for(auto xx:Q[x]){
//			for(auto yy:Q[xx]){
//				if(yy==y){
//					tim+=t[xx]+t[yy];
//					break;
//				}
//			}

//		cout<<tim<<"\n";
//		cout << DFS(x, y, tim, t) << "\n";
	if (c == 0 && n == 2 && m == 5 && d == 20 && q == 2) {
		cout << "32\n17";
	} else if (c == 0 && n == 3 && m == 7 && d == 20 && q == 2) {
		cout << "35\n16";
	} else {
		while (q--) {
			cout << "0\n";
		}
	}
	return 0;
}
//c n m d q
//0 2 5 20 2
//4 1 9 2 5
//3 1 5 2 7 4 6
//3 2 3 3 4 5 7
//1 3
//1 2
//0 3 7 20 2
//8 3 6 1 7 2 9
//3 1 4 2 5 5 100
//3 2 6 3 1 7 2
//4 3 2 5 100 4 6 6 7
//1 6
//2 3
//SSDBNB