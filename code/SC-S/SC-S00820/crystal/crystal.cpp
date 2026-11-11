#include<bits/stdc++.h>
using namespace std;
using LL = long long;
LL N, M, ans = 0;
int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> N >> M;
	vector<LL> A(N), S(N, 0), D;
	int f = 0;
	for (LL i = 0; i < N; i++) {
		cin >> A[i];
		if (A[i] != i + 1) f = 1;
	}
	if (f == 0) {
		return cout << min(N, M + 1), 0;
	}
//		S[i] = S[i - 1] + A[i] - A[i - 1];
	sort(A.begin(), A.end());
	for (LL i = 1; i < N; i++) S[i] = S[i - 1] + A[i] - A[i - 1], D.push_back(S[i]);
//
//	for (auto x : S) cout << x << " ";
	LL i = 0, l = -1, r = 1, cnt = 0, num = 1;
	while (i < N) {
		LL li = S[i] - S[l], ri = S[r] - S[i];
		if (l >= 0 && r < N) {
			LL x = min(li, ri);
			if (x == li) {
//				cout << A[l] << " " << A[i] << "\n";
				l--;
				cnt += x;
				num++;

			} else {
//				cout << A[r] << " " << A[i] << "\n";
				r++;
				cnt += x;
				num++;
			}
		} else if (l >= 0) {
//			cout << A[l] << " " << A[i] << "\n";
			l--;
			cnt += li;
			num++;
		} else if (r < N) {
//			cout << A[r] << " " << A[i] << "\n";
			r++;
			cnt += ri;
			num++;
		}
		if (cnt > M) {
			num--;
			ans = max(ans, num);
			i++;
			l = i - 1, r = i + 1;
			num = 1;
			cnt = 0;
		} else if (l < 0 && r >= N) {
			ans = max(ans, num);
			i++;
			l = i - 1, r = i + 1;
			num = 1;
			cnt = 0;
		}
	}
	cout << ans;
	return 0;
}
//5 5
//1 2 4 8 9
//5 8
//-3 -1 2 2 7
//3 1
//1 2 3