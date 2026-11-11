#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, m, k = 1;
int ans[500005], a[500005];
signed main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	while(k <= n){
		map <int, pair<bool, int> > v;
		for(int i = k;i <= n;i++){
			if(v[a[i]].first){
				for(int j = v[a[i]].second;j < i;j++){
					v[a[j]].first = 0;
					v[a[j]].second = 0;
				}
				v[a[i]].first = 1;
				v[a[i]].second = i;
			}
			else{
				v[a[i]].first = 1;
				v[a[i]].second = i;
			}
		}
		for(int q = 1;q <= n;q++){
			if(v[a[q]].first){
				ans[a[q]]++;
			}
		}
		k++;
	}
	for(int i = 1;i <= m;i++){
		cout << ans[i] << " ";
	}
	return 0;
}
