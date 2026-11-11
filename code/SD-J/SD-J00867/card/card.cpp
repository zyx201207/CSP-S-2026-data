#include <bits/stdc++.h>
using namespace std;
bool have[300005];
int ans[300005];
int a[500005];
stack <int> q;
int main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
	}
	if (m == 1){
		cout << n;
		return 0; 
	}
	if (m == 2){
		for (int i = 1; i <= n; i++){
			if (a[i] == a[n]){
				ans[a[n]]++; 
			}else{
				ans[1]++;
				ans[2]++;
			}
		}
		for (int i = 1; i <= m; i++){
			cout << ans[i] << ' ';
		}
		return 0;
	}
	for (int i = 1; i <= n; i++){
		for (int j = i; j <= n; j++){
			if (!have[a[j]]){
				q.push(a[j]);
				have[a[j]]=1;
			}else{
				while(!q.empty() && a[j] != q.top()){
					have[q.top()] = 0;
					q.pop();
				}
				if (q.top() !=a[j]){
					have[q.top()] = 1;
					q.push(a[j]);
				}
			}
		}
		while(!q.empty()){
			ans[q.top()]++;
			have[q.top()] = 0;
			q.pop();
		}
	}
	for (int i = 1; i <= m; i++){
		cout << ans[i] << ' ';
	}
	return 0;
}
