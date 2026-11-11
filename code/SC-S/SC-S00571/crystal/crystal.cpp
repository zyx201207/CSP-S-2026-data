#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[500005] , minn[500005];
signed main(){
	freopen("crystal.in" , "r" , stdin);
	freopen("crystal.out" , "w" , stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n , m;cin >> n >> m;
	for(int i = 1;i <= n;i++)cin >> a[i];
	sort(a + 1 , a + 1 + n);
	for(int i = 1;i <= n;i++) minn[i] = a[i] - a[i - 1];
	int p1 = 1 , p2 = 1 , cnt = 0 , ans = 0;
	while(p2 <= n){
		if(cnt <= m){
			p2++;
			cnt += (p2 - p1 + 1) * minn[p2];
		} 
		else if(cnt > m){
			cnt -= a[p2] - a[p1];
			p1++;
		}
		ans = max(ans , p2 - p1 + 1);
		//cout << p1 << " " << p2 << "\n";
	}
	cout << ans << "\n";
}