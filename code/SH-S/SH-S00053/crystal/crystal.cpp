#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
using namespace std;
typedef long long ll;
const int MAXN = 5e5 + 10;

ll n,m;
ll a[MAXN],d[MAXN];
ll ans;

bool compare(ll x,ll y){
	return x < y;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	sort(a + 1,a + n + 1,compare);
	
	if(n * (n + 1) >= 2e8){
		sort(a + 1,a + n + 1,compare);
		int t = a[ans + 1] - a[ans];
		while(m >= t * ans){
			m -= t * ans;
			ans++;
			t = a[ans + 1] - a[ans];
		}
		cout << ans;
		return 0;
	}
	
	for(int i = 1;i <= n;i++){
		ll t = 1;
		ll mm = m;
		for(int j = i - 1;j > 0;j--){
			if(mm < a[i] - a[j]){
				break;
			}
			mm -= a[i] - a[j];
			t++;
		}
		ans = max(ans,t);
	}
	cout << ans << endl;
	
	return 0;
}
