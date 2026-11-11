#include <iostream>
#include <algorithm>
using namespace std;

long long a[500005];
int n;
long long m;
bool check(int num){
	long long now = 0;
	for (int i = 1; i < num; i++)
		now += a[num] - a[i];
	if (now <= m) return true;
	for (int i = num + 1; i <= n; i++){
		now -= a[i-1] - a[i-num];
		now += (a[i] - a[i-1]) * (num - 1);
		if (now <= m) return true;
	}
	return false;
}
int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a+1, a+n+1);
	int l = 1, r = n;
	while (l < r){
		int mid = (l + r + 1) / 2;
		if (check(mid)) l = mid;
		else r = mid - 1;
	}
	cout << l << '\n';
	return 0;
}

