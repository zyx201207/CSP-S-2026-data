#include<bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 10;
int n, ans;
long long m;
long long a[maxn], sum[maxn];

int binary_search(int i){
	int l = 1, r = i, j = i;
	while(l <= r){
		int mid = (l + r) / 2;
		if((i - mid + 1) * a[i] - (sum[i] - sum[mid - 1]) <= m){
			j = mid;
			r = mid - 1;
		}else	l = mid + 1;
	}
	return j;
}

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i ++){
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	for(int i = 1; i <= n; i ++){
		sum[i] = sum[i - 1] + a[i];
	}
	for(int i = 1; i <= n;i ++){
		ans = max(ans, i - binary_search(i) + 1);
	}
	cout << ans;
	return 0;
}
