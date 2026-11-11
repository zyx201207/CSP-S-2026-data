#include<bits/stdc++.h>
using namespace std;

int w[1000000004], k[1000000004], a[1000000004][1000000004], t[1000000004][1000000004], x[1000000004], y[1000000004];
int main(){
    int c, n, m, d, q;
    cin >> c >> n >> m >> d >> q;
    for(int i = 0; i <= m; i++){
        cin >> w[i];
    }
	for(int i = 1; i <= n; i++){
		cin >> k[i];
		for(int i = 1; i <= k[i]; i++){
			cin >> a[i][j] >> t[i][j];
		}
	}
	for(int r = 1; r <= q; r++){
		cin >> x[r] >> y[r];
	}
    return 0;
}
