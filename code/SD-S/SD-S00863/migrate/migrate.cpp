#include <bits/stdc++.h>
using namespace std;

const int M = 2e6;
int a[M + 5];
long long d;

	int n;
bool check(int l, int r){
	if(abs(a[l] - a[r]) <= d) return false;
	vector <pair <long long, pair <long long, long long>>> qe(5000000);
	int tp = 0, ed = 0;
	qe[0] = {l, {0, 1}};
	vector <long long> dep(500000), num(500000);
	while(tp <= ed){
		int x = qe[tp].first, y = qe[tp].second.first, z = qe[tp].second.second;
		tp++;
		for(int i = x + 1;i <= n;i++){
			if(a[i] - d > a[x]) break;
			if(a[i] - d <= a[x]){
				if(dep[i] == y + 1 || dep[i] == 0){
					num[i] += z;
					if(dep[i] == 0){
						dep[i] = y + 1;
						qe[++ed] = {i, {dep[i], num[i]}};
					}
				}
			}
		}
	}
	if(num[r] != 2) return false;
	else return true;
}

int main(){
	freopen("migrate.in" , "r",  stdin);
	freopen("migrate.out", "w", stdout);
	int c, t;
	cin >> c >> t;
	for(int cas = 1;cas <= t;cas++){
		cin >> n >> d;
		for(int i = 1;i <= n;i++) cin >> a[i];
		long long ans = 0;
		for(int l = 1;l <= n;l++){
			for(int r = l + 1;r <= n;r++){
				if(check(l, r)) ans++;
			}
		}
		cout << ans << endl;
	}
	return 0;
} 
