#include <bits/stdc++.h>
using namespace std;
int a[500005], ans[200005];
signed main(){
    freopen("card.in", "r",stdin);
	freopen("card.out", "w",stdout);
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; ++i){
		cin >> a[i];
	}
	for(int i = 1; i<= n; ++i){
		map<int , int> m;
		bool af[500005] = {0};
		for(int j = i; j <= n; ++j){
			if(m[a[j]]== 1){
				int flag = 0;
				for(int k = 1; k < j; ++k){
					if(af[k]){
						continue;
					}
					if(a[k] == a[j]){
						flag = 1;
					}
					if(flag){
						m[a[k]] = 0;
						af[k] = 1;
					}
				}
			}
			m[a[j]]++;
		}
		for(auto it : m){
			cout << it.first << " " << it.second <<"\n";
			if(it.second > 0){
				ans[it.first]++;
			}
		}
		cout << "\n";
	}
	for(int i = 1; i <= m; ++i){
		cout << ans[i] << " ";
	}
    fclose(stdin);
    fclose(stdout);
	return 0;
}