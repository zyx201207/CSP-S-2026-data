//SN-J00802 王欣甜 西安市铁一中学 
#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 2e5 + 5;
int n;
int a[maxn];
char c[maxn];
ll sl[maxn], sr[maxn];
int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> a[i] >> c[i];
		sl[i] = sl[i - 1] + a[i];
	}
	for(int i = n; i > 0; i--) {
		sr[i] = sr[i + 1] + a[i]; 
	}
	int l = 1, r = n;
	ll p = 0, ans = 0;
	while(l < r) {
		if(sl[l] > sr[r]) {
			if(c[l] != c[r])ans += sr[r] - p;
			p = sr[r];
			r--;
		}else {
			if(c[l] != c[r])ans += sl[l] - p;
			p = sl[l];
			l++;
		}
	}
	cout << ans << endl;
}
