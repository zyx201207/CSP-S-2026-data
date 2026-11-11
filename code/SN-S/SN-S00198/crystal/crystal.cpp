#include<bits/stdc++.h>
using namespace std;

long long n, m, a[500010], b[500010];

bool check(long long p){
	bool flag = false;
	for(int i = p; i <= n; i++){
		long long t = b[i] - b[i - p], l = p, ma = a[i];
		long long v = ma * l;
		if(v <= (t + m)){
			flag  = true;
		}
	}
	return flag;
}

int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	for(int i = 1; i <= n; i++){
		b[i] = b[i - 1] + a[i];
	} 
	long long L = 0, R = n + 1;
	while(L + 1 < R){
		long long mid = (L + R) >> 1;
		if(check(mid)){
			L = mid;
		}else{
			R = mid;
		}
	}
	cout << L << "\n";
	return 0;
}
