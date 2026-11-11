#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, m, a[500005], vis[300005], ans[300005];
stack<int> st;
signed main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];
	if(m == 2){
		if(a[n] == 1){
			cout << n << " ";
			if(a[n - 1] == 1) cout << 0;
			else cout << n - 1;
		}else{
			if(a[n - 1] == 1) cout << n - 1 << " ";
			else cout << "0 ";
			cout << n;
		}return 0;
	}for(int i = 1; i <= n; i++){
		for(int j = i; j <= n; j++){
			if(vis[a[j]]){
				while(st.top() != a[j]){
					vis[st.top()] = 0;
					st.pop();
				}
			}else{
				vis[a[j]] = 1;
				st.push(a[j]);
			}
		}while(!st.empty()){
			ans[st.top()]++;
			vis[st.top()] = 0;
			st.pop();
		}
	}for(int i = 1; i <= m; i++) cout << ans[i] << " ";
	return 0;
}
