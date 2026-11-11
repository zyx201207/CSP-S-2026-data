#include <bits/stdc++.h>
using namespace std;
#define int long long
int n , m , a[500005] , cnt[300005];
vector<int> lst[300005];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin >> n >> m;
	for (int i = 1 ; i <= n ; i++){
		cin >> a[i];
		lst[a[i]].push_back(i);
	}
	for (int i = 1 ;  i <= n ; i++){
		int j;
		for (j = i ; j <= n ; j++){
			int l = 0 , r = lst[a[j]].size()-1 , ans = -1;
			while (l <= r){
				int mid = l+r >> 1;
				if (lst[a[j]][mid] > j) ans = mid , r = mid-1;
				else l = mid+1;
			}
			if (ans == -1) break;
			j = ans;
		}
		for ( ; j <= n ; j++) cnt[a[j]]++;
	}
	for (int i = 1 ; i <= m ; i++) cout << cnt[i] << " ";
	return 0;
}
