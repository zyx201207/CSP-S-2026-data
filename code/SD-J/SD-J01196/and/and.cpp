#include <bits/stdc++.h>
using namespace std;

const int MaxN = 2e5, M = 40;
long long is1[M + 5];
long long a[MaxN + 5], b[MaxN + 5];
bool out[MaxN + 5];

int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
//		a[i] = b[i];
	}
	for(int i = 1;i <= n;i++){
		for(int j = 0;j <= 31;j++){
			if((a[i] >> j) & 1ll) is1[j]++;
		}
	}
	vector <int> ok;
	long long ans = 0;
	for(int i = 31;i >= 0;i--){
		for(int j = 1;j <= n;j++){
			if(out[j] == true) continue;
			if((a[j] >> i) & 1ll) ok.push_back(j);
		}
		if(ok.size() >= m){
			ans += (1ll << i);
			for(int j = 1;j <= n;j++){
				out[j] = true;
			}
			for(int j = 0;j < ok.size();j++){
				out[ok[j]] = false;
			}
		}
		ok.clear();
	}
	cout << ans << endl;
	return 0;
}
