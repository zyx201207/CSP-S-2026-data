#include<bits/stdc++.h>
using namespace std;

int n;
const int N = 2e5 + 5;
struct Node {
	int num;
	char zimu;
} a[N];

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> n;
	for(int i = 1; i <= n; ++i) {
		cin >> a[i].num >> a[i].zimu;
	}
	int l = 1, r = n;
	long long cnt = 0;
	while(l < r) {
		if(a[l].num == a[r].num) {
			if(a[l].zimu == a[r].zimu) {
				l++;
				r--;
				continue;
			} else {
				cnt += a[r].num;
				l++;
				r--;
				continue;
			}
		} else if(a[l].num > a[r].num) {
			if(a[l].zimu == a[r].zimu) {
				a[l].num -= a[r].num;
				r--;
				continue;
			} else {
				cnt += a[r].num;
				a[l].num -= a[r].num;
				r--;
				continue;
			}
		} else {
			if(a[l].zimu == a[r].zimu) {
				a[r].num -= a[l].num;
				l++;
				continue;
			} else {
				cnt += a[l].num;
				a[r].num -= a[l].num;
				l++;
				continue;
			}
		}
	}
	cout << cnt << "\n";
	return 0;
}
