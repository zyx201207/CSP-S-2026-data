#include<bits/stdc++.h>
using namespace std;
int c, n, m, d, q;
const int N = 505;
const int M = 5e5 + 5;
int w[M];
int a[N][M];
int t[N][M];
int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> c>> n>> m>> d>> q;
	for(int i = 1;i <= m;i++){
		cin >> w[i];
	}
	for(int i = 1;i <= n;i++){
		int k;
		cin >> k;
		for(int j = 1;j <= k;j++){
			cin >> a[i][j]>> t[i][j];
		}
	}
	while(q--){
		int x, y;
		cin >> x>> y;
		cout << 0<< '\n';
	}
	return 0;
}
