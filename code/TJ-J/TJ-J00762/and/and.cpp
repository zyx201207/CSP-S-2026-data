#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
int n, m, num[maxn], ans;
bool vis[maxn];
void dfs(int x, int and_num){
	if(x >= m) {
		ans = max(ans, and_num);
		return;
	}
	for(int i = 0; i < n; i++){
		if(!vis[i]){
			vis[i] = 1;
			if(x == 0){
				dfs(x + 1, num[i]);	
			}
			else{
				dfs(x + 1, and_num & num[i]);
			}
			vis[i] = 0;
		}
	}
} 
int main(){
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout); 
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		cin >> num[i];
	}
	dfs(0, 0);
	cout << ans;
	return 0;
}
