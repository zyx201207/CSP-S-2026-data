#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
#define int long long
#define cin.tie(nullptr) -> sync_with_stdio(false)
int n;
struct stu {
	int a; char c;
} s[N];
int ans = 0;
int preL[N];
int preR[N];
signed main() { IOS;
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; ++i) {
		cin >> s[i].a >> s[i].c;
		preL[i] = preL[i - 1] + s[i].a;
	}
	
	for(int i = n; i >= 1; --i) {
		preR[i] = preR[i + 1] + s[i].a;
	}
	int l = 1, r = n, Rl = 0, Rr = 0;
	while(Rl < preR[1] - Rr) {
		if(preL[l] - Rl == preR[r] - Rr) {
			ans += (preL[l] - Rl) * (s[l].c == s[r].c);
			++l, --r;
			Rl = preL[l], Rr = preR[r];
		} else if(preL[l] - Rl < preR[r] - Rr) {
			while(preR[r] - Rr) {
				ans += (preL[l] - Rl) * (s[l].c == s[r].c);
				Rr += preL[l] - Rl;
				Rl = preL[l++];
			} --r;
		} else {
			while(preL[l] - Rl) {
				ans += (preR[r] - Rr) * (s[l].c == s[r].c);
				Rl += preR[r] - Rr;
				Rr = preR[r--];
			} ++l;
		}
	} cout << ans;
	return 0;
}