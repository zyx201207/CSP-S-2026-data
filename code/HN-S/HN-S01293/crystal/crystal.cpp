#include <bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 5e5 + 5;
int n;
long long m;
long long csp, ans;
int a[maxn]; 
long long check(int l, int r, long long mid){
	csp = 0;
	int ans = 0;
	for(int i = l; i <= r; i++){
		if(a[i] <= mid){
			csp++;
			ans += mid - a[i];
		}
	}
	return ans;//前缀和 + 贪心 
} 
long long akcsps(int i, int j){
	int akjl = i; 
	int aksr = j;
	while(akjl <= aksr){//二分法 
		int mid = akjl + aksr >> 1;
		if(check(i, j, a[mid]) <= m){
			akjl++;
			ans = max(ans, csp);
		}else{
			aksr--;
		}
	}
	return ans;
}
signed main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	long long ans = 0;
	sort(a + 1, a + 1 + n);
	cout << akcsps(1, n);
	return 0;
} 
