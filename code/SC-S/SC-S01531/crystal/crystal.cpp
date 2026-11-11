#include<bits/stdc++.h>
using namespace std;


long long sum[500005];
int n, m, a[500005], ans;

bool check(int l, int r, long long avg){
	long long d = 0;
	for(int i = l; i <= r; i++){
		d += abs(a[i] - avg);
	}
	return d > m;
}

int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		sum[i] = sum[i - 1] + a[i];
	}
	sort(a + 1, a + 1 + n);
	for(int l = 1; l <= n; l++){
		for(int r = l; r <= n; r++){
			double avg = (double)(sum[r] - sum[l - 1]) / (r - l + 1);
			if(ceil(avg) - avg > avg - floor(avg)){
				avg = floor(avg);
			}
			else{
				avg = ceil(avg);
			}
			if(check(l, r, (long long)avg)) break;
			ans = max(ans, r - l + 1);
		}
	}
	cout << ans;
	return 0;
}