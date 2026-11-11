#include <bits/stdc++.h>
using namespace std;
int n, m, a[500005], v[300005], ans[300005];
stack<int> s;
int main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++){
		for (int j = i; j <= n; j++){
			if (v[a[j]] == 0){
				s.push(a[j]);
				v[a[j]] = 1;
			}
			else{
				while (s.size() && s.top() != a[j]){
					v[s.top()] = 0;
					s.pop();
				}
			}
		}
		while (!s.empty()){
			v[s.top()] = 0;
			ans[s.top()]++;
			s.pop();
		}
	}
	for (int i = 1; i <= m; i++){
		cout << ans[i] << ' ';
	}
	return 0;
}
