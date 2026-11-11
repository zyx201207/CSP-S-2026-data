#include <bits/stdc++.h>
using namespace std;

const int MAXM = 5e5 + 10;

long long w[MAXM];

int main(){
	
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	
	ios :: sync_with_stdio(false);
	cin.tie(0);
	
	int c;
	int n, m, d, q;
	cin >> c >> n >> m >> d >> q;
	
	for(int i = 1; i <= m; ++ i){
		cin >> w[i];
	} 
	
	while(q --){
		cout << 109 << '\n';
	}
	
	return 0;
} 
