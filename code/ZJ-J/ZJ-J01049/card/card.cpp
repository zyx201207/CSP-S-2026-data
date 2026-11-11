#include<bits/stdc++.h>
using namespace std;
const int N = 5 * 1e5 + 10;
int n,m,dep = 1;
int a[N];
int t[N];
int ans[N];

int findnum(int k,int i) {
	for(i; i <= n; i++) if(t[i] == k) return i;
	return 0;
}
int main() {
	freopen("card.in","r",stdin);
	freopen("catd.out","w",stdout);
	cin >> n >> m;
	for(int i = n; i >= 1; i--) cin >> a[i];

	for(int i = 1; i <= n; i++) {
		for(int j = i; j <= n; j++) {
			int num = findnum(a[i],i);
			if(num < 1) {
				t[dep] = a[i];
				dep++;
			} else {
				for(int k = num; k <= n; k++) t[i] = 0;
				dep = num;
			}
		}
		for(int j = 1; j <= dep; j++) ans[t[j]]++;
	}

	for(int i = 1; i <= m; i++) cout << ans[i];
	return 0;
}
