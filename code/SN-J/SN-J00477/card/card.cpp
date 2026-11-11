#include<bits/stdc++.h>
using namespace std;

int n, m, a[500010], c[300010], ans[300010];
stack<int> b;

int main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			c[j] = 0;
		}
		for(int j = i; j <= n; j++){
			if(!c[a[j]]){
				b.push(a[j]);
				c[a[j]]++;
			}else{
				while(b.top() != a[j]){
					c[b.top()]--;
					b.pop();
				}
				c[b.top()]--;
				b.pop();
				b.push(a[j]);
				c[a[j]]++;
			}
		}
		while(!b.empty()){
			ans[b.top()]++;
			b.pop();
		}
	}
	for(int i = 1; i <= m; i++){
		cout << ans[i] << " ";
	}
	cout << "\n";
	return 0;
}
