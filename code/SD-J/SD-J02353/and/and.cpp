#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<int> b, c, d;
int ans = 0;
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		b.push_back(x);
	}
	for(int i = 30; i >= 0; i--) {
		c=d;
		int cnt = 0;
		for(int j = 0; j < b.size(); j++) {
			if((b[j]&(1<<i))>0) {
//				cout << b[j] << ' ' << (1<<i) << endl;
				c.push_back(b[j]);
				cnt++;
			}	
		}
		if(cnt>=m) {
//			cout << cnt  << ' ' << m << endl;
			ans=ans|1<<i;
			swap(b,c);
		}
	}
	cout << ans;
	return 0;
} 
