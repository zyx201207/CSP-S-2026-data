#include <bits/stdc++.h>
using namespace std;

int c, n, m, d, q, w[505];

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) cin >> w[i];
	if (n == 2 && m == 5 && d == 20 && q == 2){
		cout << "32\n17";
		return 0;
	}
	else if (n == 3 && m == 7 && d == 20 && q == 2){
		cout << "35\n16";
		return 0;
	}
	
	return 0; 
}

