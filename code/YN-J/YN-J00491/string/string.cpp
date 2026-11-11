#include<bits/stdc++.h>
using namespace std;

bool MST;
#define int long long
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define N 200010
int n;
struct node {
	int a;
	char c;
} p[N];
int sum = 0;
void solve_() {
	cin >> n;
	rep(i, 1, n) {
		cin >> p[i].a >> p[i].c;
	}
	int l = 1, r = n;
	while (l < r) {
		if (p[l].a >= p[r].a) {
			if (p[l].c != p[r].c) {
				sum += p[r].a;
			}
			p[l].a -= p[r].a;
			r--;
		} else {
			if (p[l].c != p[r].c) {
				sum += p[l].a;
			}
			p[r].a -= p[l].a;
			l++;
		}
	}
	cout << sum << "\n";
}
bool MED;
signed main() {
//	cerr << abs(&MST - &MED) / 1024 / 1024 << "MB\n";
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	solve_();
	return 0;
}
