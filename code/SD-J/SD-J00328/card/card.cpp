#include <bits/stdc++.h>
using namespace std;

const int MAXC = 3e5 + 8;
const int MAXA = 5e5 + 8;
long long n,m,cnt[MAXC],a[MAXA];
bool e;

void f(int head) {
	if(e) return;
	cnt[a[head]]++;
	for(int i = n ; i >= 1 ; i--) {
		if(a[i] == a[head]) {
			if(i == n) {
				e = 1;
				return;
			}
			f(i + 1);
		}
	}
}

int main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i = 1 ; i <= n ; i++) cin >> a[i];
	for(int i = 1 ; i <= n ; i++) {
		e = 0;
		f(i);
	}
	for(int i = 1 ; i <= m ; i++) {
		cout << cnt[i] << " ";
	}
	cout << "\n";
	return 0;
}
