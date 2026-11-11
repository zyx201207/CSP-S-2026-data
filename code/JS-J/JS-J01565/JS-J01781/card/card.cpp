#include <iostream>
#include <vector>
using namespace std;

const int N(5e5+5), M(3e5+5);
int n, m, a[N], pos[M];
long long t[M];
vector<int> desk;
bool tsxzA = true;

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for (int i=1; i<=n; i++) {
		cin >> a[i];
		if (tsxzA && a[i-1]>a[i]) tsxzA = false;
	}
	if (tsxzA) {
		for (int i=1; i<=n; i++) {
			t[a[i]]++;
		}
		for (int i=1; i<=m; i++) {
			t[i] += t[i-1];
		}
	}
	else {
		for (int i=1; i<=n; i++) {
			desk.resize(1);
			for (int j=i; j<=n; j++) {
				if (pos[a[j]] == 0) {
					desk.push_back(a[j]);
					pos[a[j]] = desk.size();
				}
				else {
					while (int(desk.size())>pos[a[j]]) {
						pos[desk.back()] = 0;
						desk.pop_back();
					}
				}
			}
			for (int j=1; j<=m; j++) {
				if (pos[j] > 0) {
					t[j]++;
					pos[j] = 0;
				}
			}
		}
	}
	for (int i=1; i<=m; i++) {
		cout << t[i] << ' ';
	}
	return 0;
}
