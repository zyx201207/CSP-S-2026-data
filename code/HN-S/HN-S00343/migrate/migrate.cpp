// dlc666 是我最敬佩的 les or gay 
#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
// 一个事实，因为最短，使用可以跳肯定要跳最远？
// 当 d = 2 时，2 1 和 1 2 组成一对
// 当 d = 3 时，3 2 和 2 3 组成一对（3 1 可到的 1 3 、2 2 都可以到） 
// 以此类推， d = x 时，x 与 x - 1 是一对 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int c; cin >> c;
	int t; cin >> t; 
	while(t--) {
		int n; cin >> n;
		long long d; cin >> d;
		vector<long long> x(n); 
		for(int i = 0; i < n; i++) {
			cin >> x[i];
		}		
		long long sum = 0; 
		for(int i = 0; ; i++) {
			if(i + 3 >= n) break;
			if((x[i + 3] - x[i + 1]) <= d) continue;
			if((x[i + 1] - x[i + 0]) <= d) continue;
			if((x[i + 3] - x[i + 2] <= d) && (x[i + 2] - x[i + 1] <= d) && (x[i + 1] - x[i] <= d)) {
				sum++; 
			}
		}
		cout << sum << endl;
	} 

	return 0;
} 
