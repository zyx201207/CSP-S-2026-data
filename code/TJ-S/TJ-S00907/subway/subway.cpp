#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
int c, n, m, d, q;
long long ans;
int w[N], a[5010][110], t[5010][110], x, y;

int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q; 
	for(int i = 1; i <= m; i++){
		cin >> w[i];
	}
	for(int i = 1; i <= n; i++){
		int k;
		cin >> k;
		for(int j = 1; j <= k; j++){
			cin >> a[i][j] >> t[i][j];
		}
	}
	while(q--){
		cin >> x >> y;
		
	}
	
	return 0;
}
