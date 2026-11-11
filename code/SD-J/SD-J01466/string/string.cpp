#include<bits/stdc++.h>
#define endl '\n'
#define udmap unordered_map
#define udset unordered_set
using namespace std;
typedef long long LL;
typedef unsigned long long uLL;

const int N = 2e5 + 10;
int n;

struct node {
	LL cnt;
	char c;
} a[N];

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	cin >> n;
	for(int i = 1; i <= n; i++) {
		int x;
		char b;
		cin >> x >> b;
		a[i] = {x, b};
	}
	LL l = 1, cntl = 1, r = n, cntr = a[n].cnt;
	LL ans = 0;
	while(l < r) {
		int suml = a[l].cnt - cntl + 1, sumr = cntr;
		if(suml == sumr) {
			if(a[l].c != a[r].c) ans += suml;
			l++;
			cntl = 1;
			r--;
			cntr = a[r].cnt;
		} else if(suml > sumr) {
			if(a[l].c != a[r].c) ans += sumr;
			cntl += sumr;
			r--;
			cntr = a[r].cnt;
		} else {
			if(a[l].c != a[r].c) ans += suml;
			l++;
			cntl = 1;
			cntr -= suml;
		}
	}
	cout << ans;
	return 0;
}

