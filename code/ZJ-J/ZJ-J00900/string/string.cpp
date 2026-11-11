#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 10;

ll num[N];
char op[N];

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int n;
	cin>>n;
	int tot = 0;
	for(int i = 1; i <= n; i++) {
		ll a;
		char c;
		cin>>a>>c;
		if(op[tot] == c) {
			num[tot] += a;
		}else {
			tot++;
			num[tot] = a;
			op[tot] = c;
		}
	}
	
	int l = 1, r = tot;
	ll ans = 0;
	while(l < r) {
		if(op[l] != op[r]) {
			if(num[l] > num[r]) {
				ans += num[r];
				num[l] -= num[r];
				r--;
			}else if(num[l] < num[r]) {
				ans += num[l];
				num[r] -= num[l];
				l++;
			}else {
				ans += num[l];
				l++;
				r--;
			}
		}else {
			if(num[l] > num[r]) {
				num[l] -= num[r];
				r--;
			}else if(num[l] < num[r]) {
				num[r] -= num[l];
				l++;
			}else {
				l++;
				r--;
			}
		}
	}
	
	cout<<ans;
	
	return 0;
}