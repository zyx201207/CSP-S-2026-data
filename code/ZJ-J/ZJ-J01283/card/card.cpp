#include <bits/stdc++.h>
using namespace std;
const int Maxn = 2e5 + 5;
int n;
int a[Maxn];
int main() {
	srand(time(0));
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; i++){
		cout << rand() % n + 1 << " ";
	}
	return 0;
}

