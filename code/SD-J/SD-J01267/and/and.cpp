#include <bits/stdc++.h>
using namespace std;

const int N = 2e5, M = 30;
long long a[N + 5], b[N + 5][M + 5];
bool k[N + 5];

int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for(int i = 1;i <= n;i++) cin >> a[i];
	for(int i = 1;i <= n;i++){
		long long w = a[i];
		int j = 0;
		while(w > 0){
			b[i][j] = (w % 2);
			w = w / 2;
			j++;
		}
	}
	long long ans = 0;
	for(long long j = 30;j >= 0;j--){
		int ct = 0;
		for(int i = 1;i <= n;i++){
			if(k[i] == 0) ct += b[i][j];
		}
		if(ct >= m){
			for(int i = 1;i <= n;i++){
				if(b[i][j] == 0 && k[i] == 0) k[i] = 1;
			}
			ans += (1ll << j);
		}
	}
	cout << ans << endl;
	return 0;
}
