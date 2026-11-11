#include<bits/stdc++.h>
using namespace std;
int n, m, a[500010], q[500010], ans[300010];
int main(){
	freopen("card.in", "r", stdin);
	freopen("card.in", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	for(int ju = 1; ju <= n; ju++){
		int flag[300010];
		memset(flag, 0, sizeof(flag));
		int l = 0;
		for(int i = ju; i <= n; i++){
			q[++l] = a[i];
			for(int j = 1; j < l; j++){
				if(q[j] == a[i]){
					l = j;
				}
			}
		}
		for(int i = 1; i <= l; i++){
			if(flag[q[i]] == 0) ans[q[i]]++;
			flag[q[i]] = 1;
		}
	}
	for(int i = 1; i <= m; i++) cout << ans[i] << " ";
	return 0;
}
