#include<bits/stdc++.h>
using namespace std;
const int MAXN = 5e3 + 5, MAXM = 3e3 + 5;
int n, m, a[MAXN], cnt[MAXM];
stack<int> cd;
bool is[MAXM];
int main(){
	ios::sync_with_stdio(false); cin.tie(nullptr);
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	for(int i = 1; i <= n; i++){
		for(int j = i; j <= n; j++){
			if(is[a[j]]){
				while(cd.top() != a[j]){
					is[cd.top()] = 0;
					cd.pop();
				}
			}
			else{
				is[a[j]] = 1;
				cd.push(a[j]);
			}
		}
		while(!cd.empty()){
			cnt[cd.top()]++;
			cd.pop();
		}
		memset(is, 0, sizeof(is));
	}
	for(int i = 1; i <= m; i++){
		cout << cnt[i] << " ";
	}
	return 0;
}