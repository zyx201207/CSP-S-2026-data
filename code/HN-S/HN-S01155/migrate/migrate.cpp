#include<bits/stdc++.h>
using namespace std;
int c, t;
int n, d;
int x[5000005];
int a[5000005];
struct node{
	int d;
	int ans;
};
void solve(){
	int sum= 0; 
	queue<node> q;
	q.push({1, 0});
	while (!q.empty()){
		node now = q.front();
		q.pop();
		for (int i = now.d;i <= n;i++) {
			if (abs(x[i] - x[now.d]) <= 2) {
				if (now.ans + 1 == a[i] && a[i] != 0) {
					sum += 1;
				}
				else if (a[i] != 0) {
				    a[i] = min(now.ans + 1, a[i]);
				}else {
					a[i] = now.ans + 1;
					q.push({i, a[i]});
				}
			}else break;
		}
	}
	cout << sum<< endl; 
	return ;
}
int main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out","w",stdout);
    cin >> c >> t;
    while (t--){
    	cin >> n >> d;
    	for (int i = 1;i <= n;i++) cin>> x[i];
    	solve();
	}
	return 0;
}
