#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5 + 5;
int n, m, a[N], bit[N][35], vis[N], sum;
vector<int> ans;

signed main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	sum = n;
	for(int i = 1;i <= n;i++) cin >> a[i];
	for(int i = 1;i <= n;i++){
		int t = a[i], w = 0;
		int bitt[35];
		while(t){
			int d = t % 2;
			bitt[++w] = d;
			t /= 2;
		}
		for(int j = 1;j <= w;j++) bit[i][j + 30 - w] = bitt[w - j + 1];
//		for(int j = 1;j <= 30;j++) cout << bit[i][j] << ' ';
//		cout << endl;
	}
	int p = 0;
	while(p <= 30 && sum > m){
		p++;
		vector<int> t;
		for(int i = 1;i <= n;i++){
			if(vis[i]) continue;
			if(bit[i][p] == 1) t.push_back(i);
		}
//		for(int i:t) cout << i << ' ';
//		cout << '\n';
		if(t.size() < m){
			continue;
		}
		if(t.size() == m){
			ans = t;
			break;
		}
		else {
//			cout << "hhhhhh";
			ans.clear();
			for(int i = 0;i < m;i++) ans.push_back(t[i]);
			for(int i = 1;i <= n;i++) vis[i] = 1;
			for(int i:t) vis[i] = 0;
		}
	}
//	cout << "ans:\n";
//	for(int i:ans) cout << i << ' ';
//	cout << '\n';
	if(ans.size() == 0) cout << 0;
	else{
		int t = a[ans[0]];
		for(int i:ans) t &= a[i];
		cout << t;
	}
	return 0;
}
