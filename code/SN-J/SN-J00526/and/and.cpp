#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;

int n,m,a[N],ans = -1,num;

vector<int> vis;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout); 
	cin >> n >> m;
	for(int i = 1;i<=n;i++) {
		cin >> a[i];
		vis.push_back(i);
	}
	for(int i = 29;i>=0;i--) {
		vector<int> cnt;
		for(auto j : vis) {
			if((a[j] >> i) & 1) cnt.push_back(j);
		}
		if(cnt.size() >= m) vis = cnt; 
	}
	for(auto i : vis) {
		if(ans == -1) ans = a[i];
		else ans = (ans & a[i]);
		num++;
		if(num == m) break;
	}
	cout << ans;
	return 0;
}
