// 张睿航 SN-S00360 西安市第六中学 
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
int zhn;
ll zhm;
ll zha[500005];
ll zhs[500005];
int zhans = 0;

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> zhn >> zhm;
	for(int i = 1; i <= zhn; i ++) {
		cin >> zha[i];
	}
	sort(zha + 1, zha + zhn + 1);
	for(int i = 1; i <= zhn; i ++) {
		zhs[i] = zhs[i - 1] + zha[i];
	}
	for(ll i = 2; i < zhn; i ++) {
		int l = 1, r = i - 1, ans;
		while(l <= r) {
			ll mid = l + (r - l + 1) / 2;
			if((zha[i] * (ll)(i - mid) - (zhs[i - 1] - zhs[mid - 1])) <= zhm) {
				r = mid - 1;
				ans = i - mid + 1;
			}
			else {
				l = mid + 1;
			}
		}
		zhans = max(zhans, ans);
	}
	cout << zhans;
	return 0;
}
