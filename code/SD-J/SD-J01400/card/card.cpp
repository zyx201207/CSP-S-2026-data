#include<bits/stdc++.h>
using namespace std;
const int N = 5E5 + 10;
const int M = 3E5 + 10;
int a[N], sum[M];
bool use[N];
stack<int> s;
signed main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(false);
	int n, m;
	bool flag = true;
	cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		if(a[i] < a[i-1]) flag = false;
	}
	if(flag) {
		//特殊性质A
		for(int i = 1; i <= n; i++) {
			if(a[i] != a[i+1]) cout << i << " "; 
		} 
		return 0;
	}
	if(n <= 5000) {
		for(int i = 1; i <= n; i++) {
			for(int j = i; j <= n; j++) {
//				cout << a[j] << " ";
				if(use[a[j]] == true) {
					while(s.top() != a[j]) {
						use[s.top()] = false;
						s.pop();
					}
				} else {
					s.push(a[j]);
					use[a[j]] = 1;
				}
			}
			while(!s.empty()) {
				sum[s.top()]++;
				use[s.top()] = false;
				s.pop();
			}
		}
//		cout << "\n";
		for(int i = 1; i <= m; i++) {
			cout << sum[i] << " ";
		}
		return 0;
	}
	if(m == 2) {
		sum[a[n]] = n;
		int res = 0;
		for(int i = 1; i <= n; i++) {
			if(a[i] == a[n]) res++;
		}
		if(a[n] == 1) {
			cout << sum[1] << " " << n - res << "\n";
		} else {
			cout << n - res << " " << n - res << "\n";
		}
		return 0; 
	}
	return 0;
}
//我能AK CSP-J吗 
//time 9:35 
//65min 切 3道 
//time 9:53 没思路啊 
//time 10:21 这是什么题目 
//time 10:33 坏了，这回炸了,只能写暴力了 
//time 11:01 被第四题AK了 
//time 11:17 完成暴力，惜败 J
//前三题的大样例都过了 
//预估 pts 352
//暴力的大样例也过了 
