#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
using namespace std;
struct node {
	long long x;
	string c;
};
long long n, num;
string s;
vector<node> a;
int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for(int i = 0;i < n;i++) {
		cin >> num >> s;
		a.push_back({num, s});
	}
	long long l = 0, r = a.size() - 1, ans = 0;
	while(l <= r) {
		if(a[l].c != a[r].c) {
			if(a[l].x < a[r].x) {
				a[r].x -= a[l].x;
				ans += a[l].x;
				l++;
			} else if(a[l].x == a[r].x) {
				ans += a[l].x;
				l++;
				r--;
			} else {
				a[l].x -= a[r].x;
				ans += a[r].x;
				r--;
			}
		} else {
			if(a[l].x == a[r].x) {
				l++;
				r--;
			} else if(a[l].x < a[r].x) {
				a[r].x -= a[l].x;
				l++;
			} else {
				a[l].x -= a[r].x;
				r--;
			}
		}
	}
	cout << ans;
	return 0;
}
