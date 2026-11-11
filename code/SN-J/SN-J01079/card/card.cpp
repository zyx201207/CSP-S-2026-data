#include<bits/stdc++.h>
using namespace std;
long long n, m, a[500005], f[300005], ans[300005];
int main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for(int i = n; i >= 1; i --){
		cin >> a[i];
	}
	for(int i = 1; i <= n; i ++){
		if(f[a[i]] != 0){
			for(int j = f[a[i]] + 1; j < i; j ++){
				if(f[a[j]] > f[a[i]]){
					f[a[j]] == 0;
				}
			}
		}
		f[a[i]] = i;
		for(int j = 1; j <= m; j ++){
			if(f[a[j]] != 0){
				ans[a[j]] ++;
			}
			cout << ans[a[j]] << " ";
		}
		cout << endl;
	}
	for(int i = 1; i <= m; i ++){
		cout << ans[i] << " ";
	}
	return 0;
}


