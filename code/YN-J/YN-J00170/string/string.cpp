#include <bits/stdc++.h>
using namespace std;
long long ans;

struct node {
	long long t, id;
	char c;
};
node a[200005];
int n;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	
	for (int i = 1; i <= n; i++) {
		
		cin >> a[i].t >> a[i].c;
	}
	
	int l = 1, r = n;
	
	while (l < r) {
		if (a[l].c == a[r].c) {
			long long  tot = min(a[l].t, a[r].t);
			a[l].t -= tot;
			a[r].t -= tot;
		}
		
		else {
			long long tot = min(a[l].t, a[r].t);
			
			if (a[r].t == tot) {
				a[l].id += tot;
				a[l].t -= tot;
				a[r].t -= tot;
			} else {
				a[r].id += tot;
				a[l].t -= tot;
				a[r].t -= tot;
			}
			
		}
		
		if (a[l].t == 0) {
			l++;
		}
		
		if (a[r].t == 0) {
			r--;
		}
	}
	
	for (int i = 1; i <= n; i++) {
		
		ans += a[i].id;
	}
	
	cout << ans;
	
	return 0;
}

