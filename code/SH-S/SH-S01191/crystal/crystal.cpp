#include <bits/stdc++.h>
using namespace std;
int n;
long long m;
long long a[500010];

bool check(int x){
	long long sum = 0;
	bool flag = false;
	for (int i = 1; i <= x; i++){
		sum += (a[i]-a[i-1]) * (i-1);
	}
	if (sum <= m) flag = true;
	for (int i = 2; i+x-1 <= n; i++){
		int j = i+x-1;
		sum -= a[j-1] - a[i-1];
		sum += (a[j]-a[j-1]) * (x-1);
		if (sum <= m) flag = true;
	}
	return flag;
}

int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
	}
	sort(a+1, a+n+1);
	int l = 1, r = n;
	while (l <= r){
		int mid = l + r >> 1;
		if (check(mid)) l = mid + 1;
		else r = mid - 1;
	}
	cout << r << endl;
	return 0;
}
