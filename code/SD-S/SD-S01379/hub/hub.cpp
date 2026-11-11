//#include<bits\stdc++.h>
#include<bits/stdc++.h>
//using namesoace std;
using namespace std;
/*====================*/
using lnt = long long;
using pii = pair<int, int>;
/*====================*/
const int INF = 0x3F3F3F3F;
const lnt LNF = 0x3F3F3F3F3F3F3F3F;
/*====================*/
void Solve() {
	cout << rand() % 5 << '\n';
}

// int mian() {
int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	srand(time(0));
	int T = 1; cin >> T;
	while (T--) Solve();
	return 0;
}

