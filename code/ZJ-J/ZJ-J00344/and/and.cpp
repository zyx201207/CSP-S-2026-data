#include <bits/stdc++.h>
using namespace std;
#define int long long
long long a[200005];
signed main(){
	freopen("and.in", "r",stdin);
	freopen("and.out", "w",stdout);
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; ++i){
		cin >>a[i];
	}
	sort(a + 1, a + n + 1, greater<int>());
	if(m == 1){
		cout << a[1];
		return 0;
	}else if(m == 2){
		int aanss = -1;
		for(int i = 1; i < n; ++i){
			for(int j = i + 1; j <= n; j++){
				aanss = max(aanss, a[i] & a[j]);
			}
		}
		cout << aanss;
	}else if(m == n){
		int aaannnsss = a[1];
		for(int i = 2; i <= n; ++i){
			aaannnsss = aaannnsss & a[i];
		}
		cout << aaannnsss;
	}else if(m == n - 1){
		int aaaannnnssss = -1;
		for(int i = 1; i <= n; ++i){
			if(i == 1){
				int nas = a[2];
				for(int j = 3; j <= n; ++j){
					nas = nas & a[j];
				}
				aaaannnnssss = max(aaaannnnssss, nas);
			}else{
				int nnas = a[1];
				for(int j = 2; j <= n; ++j){
					if(j == i){
						continue;
					}
					nnas = nnas & a[i];
				}
				aaaannnnssss = max(aaaannnnssss, nnas);
			}
		}
		cout << aaaannnnssss;
	}else{
		int ans = a[1];
		for(int i = 2; i <= m; ++i){
			ans = ans & a[i];
		}
		cout << ans;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}