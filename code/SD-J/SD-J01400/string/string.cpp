//前三个题咋恁简单
//第四题应该没人一眼秒吧
//我居然一眼秒了前三个题
//但愿不挂分 
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2E5 + 10;
int a[N];
char s[N];
signed main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(false); 
	int n, sum = 0;
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> a[i] >> s[i]; 
		sum += a[i];
	}
//	cout << "sum:" << sum << "\n";
	int head = 0, last = n, ans = 0;
	while(head <= last) {
//		pre += a[++head];
//		cout << "pre" << pre << "\n";
//		cout << head << " " << last << "\n"; 
		if(s[head] == s[last]) {
			if(a[head] > a[last]) {
				a[head] -= a[last--]; 
			} else if(a[head] < a[last]) {
				a[last] -= a[head++];		
			} else {
				last--, head++;
			}
		} else {
			if(a[head] > a[last]) {
				ans += a[last];
				a[head] -= a[last--]; 
			} else if(a[head] < a[last]) {
				ans += a[head];
				a[last] -= a[head++];		
			} else {
				ans += a[last];
				last--, head++;
			}
		}
	}
	cout << ans << "\n";
	return 0;
}

