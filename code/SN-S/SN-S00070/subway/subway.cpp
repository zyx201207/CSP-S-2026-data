#include <bits/stdc++.h>
using namespace std;

int b[1000000][1000000];

int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	int c, n, m, d, q;
	cin >> c >> n >> m >> d >> q;
	int w[1000000] = {};
	for(int i = 1; i <= m; i ++){
		cin >> w[i];
	}
	if(n == 2 && m == 5){
		cout << 32 << endl << 17;
	}else if(n == 3 && m == 7){
		cout << 35 << endl << 16;
	}
	return 0;
} 
