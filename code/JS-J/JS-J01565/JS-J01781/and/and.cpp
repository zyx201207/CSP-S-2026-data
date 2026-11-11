#include <iostream>
using namespace std;

const int N(2e5+5), and0 = 0x7fffffff;
int n, m, a[N], ans, lg2[(1<<20)+5];
bool task1to5(false), task6(false), task7(false), task8to10(false), task11to12(false), tsxzA(true), tsxzB(true), task16to17(true);

bool vis[N];
void dafenshan(int x, int lst=0) {
	if (x == m) {
		int sum = and0;
		for (int i=1; i<=n; i++) {
			if (vis[i]) {
				sum &= a[i];
			}
		}
		if (sum>ans) {
			ans = sum;
		}
		return;
	}
	for (int i=lst+1; i<=n; i++) {
		vis[i] = true;
		dafenshan(x+1, i);
		vis[i] = false;
	}
}

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	for (int i=1; i<=(1<<20); i++) {
		lg2[i] = lg2[i-1];
		if ((1<<(lg2[i]+1)) <= i) ++lg2[i];
	}
	cin >> n >> m;
	if (n<=20) task1to5 = true;
	else if (n<=2000 && m==1) task6 = true;
	else if (n<=2000 && m==n) task7 = true;
	else if (n<=2000 && m==2) task8to10 = true;
	else if (m == n-1) task11to12 = true;
	for (int i=1; i<=n; i++) {
		cin >> a[i];
		if (tsxzA && lg2[a[i]]==lg2[a[i]+1]) tsxzA = false;
		if (tsxzB && a[i]!=i-1) tsxzB = false;
		if (task16to17 && a[i]>=4) task16to17 = false;
	}
	if (task1to5) {
		dafenshan(0);
		cout << ans;
	}
	else if (task6) {
		for (int i=1; i<=n; i++) {
			if (a[i] > ans) ans = a[i];
		}
		cout << ans;
	}
	else if (task7) {
		ans = and0;
		for (int i=1; i<=n; i++) {
			ans &= a[i];
		}
		cout << ans;
	}
	else if (task8to10) {
		for (int i=1; i<n; i++) {
			for (int j=i+1; j<=n; j++) {
				if ((a[i]&a[j]) > ans) {
					ans = a[i]&a[j];
				}
			}
		}
		cout << ans;
	}
	else if (tsxzA) {
		int t[25];
		for (int i=0; i<25; i++) t[i]=0;
		for (int i=1, k; i<=n; i++) {
			k = lg2[a[i]+1];
			t[k]++;
		}
		int sum = 0;
		for (int k=24; k>=0; k--) {
			sum += t[k];
			if (sum >= m) {
				ans = (1<<k)-1;
				break;
			}
		}
		cout << ans;
	}
	else if (tsxzB) {
		int sum = and0;
		for (int i=n; i>n-m; i--) {
			sum &= a[i];
		}
		ans = sum;
		cout << ans;
	}
	else if (task16to17) {
		int t[4] = {0, 0, 0, 0};
		for (int i=1; i<=n; i++) {
			++t[a[i]];
		}
		if (m <= t[3]) ans = 3;
		else if (m <= t[3]+t[2]) ans = 2;
		else if (m <= t[3]+t[2]+t[1]) ans = 1;
		else ans = 0;
		cout << ans;
	}
	return 0;
}
