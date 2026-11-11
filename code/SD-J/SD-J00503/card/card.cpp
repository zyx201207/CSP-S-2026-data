#include<bits/stdc++.h>
using namespace std;
int n, m;
vector<int> a, ans, b;
int main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	a.resize(n + 1);
	b.resize(m + 1);
	ans.resize(m + 1);
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		b[a[i]] = max(b[a[i]], i);
	}
	for(int i = 1; i <= n; i++){
		int l = i;
		while(l <= n){
			ans[a[l]]++;
			l = b[a[l]] + 1;
		}
	}
	for(int i = 1; i <= m; i++){
		cout << ans[i] << " ";
	}
	cout << endl; 
	return 0;
} 
