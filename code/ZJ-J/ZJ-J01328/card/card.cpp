#include <bits/stdc++.h>
using namespace std;

#define int long long
int n, m;
int a[500010];
//int mark[500010];
int ans[500010], Ans[200010];
int last[200010];
int flag[500010];
signed main(){
	
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
	}
	/*cout << n << ' ' << m << endl;
	for (int i = 1; i <= n; i++){
		cout << a[i] << endl;
	}*/
	int cnt = 0;
	for (int r = 1; r <= n; r++){
		if (cnt > 1e8) break;
		memset(last, 0, sizeof(last));
		memset(flag, 0, sizeof(flag));
		for (int i = r; i <= n; i++){
			if (last[a[i]] == 0){
				last[a[i]] = i;
				cnt++;
			} else {
				if (flag[last[a[i]]] == 0){
					for (int j = last[a[i]]; j < i; j++){
						cnt++;
						flag[j] = 1;
					}
				}else {
					cnt++;
				}
				
				last[a[i]] = i;
			}
		}
		for (int i = r; i <= n; i++){
			//flag[i] = flag[i-1] + flag[i];
			
			if (flag[i] == 0){
				ans[a[i]]++;
				//cout << flag[i] << ' ' << last[a[i]] << endl;
			}
		}
	}
	for (int i = 1; i <= m; i++){
		cout << ans[i] << ' ';
	}
	
	return 0;
}
