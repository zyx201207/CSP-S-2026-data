#include<bits/stdc++.h>

using namespace std;

long long n, m;

long long a[500010];
long long sum[500010];

bool check(int x){
	for(int i = x; i <= n; i++){
		long long num = sum[i] - sum[i - x];
		long long xx = a[i] * x - num;
		if(xx <= m){
			return true;
		}
	}
	return false;
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
		sum[i] = sum[i - 1] + a[i];
	}
	int l = 1;
	int r = n;
	int ret = -1;
	while(l <= r){
		int mid = (l + r) >> 1;
		if(check(mid)){
			l = mid + 1;
			ret = mid;
		}else{
			r = mid - 1;
		}
	}
	cout << ret;
	
	return 0;
}