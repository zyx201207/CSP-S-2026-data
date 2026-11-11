#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[1000001];
long long ccount[1000001];
int main() {

	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i ++) {
		cin >> a[i];
	}
	for(int i = 1; i <= n; i ++) {
		stack<int> st;
		bool pd[1000001];
		for(int k = 1; k <= n; k ++) pd[k] = 0;
		for(int j = i; j <= n; j++) {
			if(pd[a[j]] == 0) {
				pd[a[j]] = 1;
				st.push(a[j]);
			} else {
				while(!st.empty()) {
					int x = st.top();
					if(x == a[j]) {
						st.pop();
						st.push(a[j]);
						break;
					} else {
						pd[x] = 0;
						st.pop();
					}
				}
			}
		}
		while(!st.empty()) {
			int x = st.top();
			ccount[x] ++;
			st.pop();
		}
	}
	for(int i = 1; i <= m; i ++) {
		cout << ccount[i] << " ";
	}
	return 0;
}
// T4:what??!! 大样例不过     预期50 
