#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 2e5+7;
ll n, m, a[MAXN], ans = -1e9;
bool A = true, B = true;
int bit1(ll num){
	int cnt = 0;
	while(num){
		if((num&1) == 1)	cnt++;
		num >>= 1;
	}
	return cnt;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);	cout.tie(0);
	cin >> n >> m;
	for(int i = 1;i <= n;++i){
		cin >> a[i];
		ans = max(ans, a[i]);
		if(bit1(a[i]+1) != 1)	A = false;
		if(a[i] != i-1)	B = false;
	}
	if(m == 1){
		cout << ans;
		return 0;
	}
	if(m == 2){
		ans = 0;
		for(int i = 2;i <= n;++i){
			for(int j = 1;j < i;++j){
				ans = max(ans,a[i] & a[j]);
			}
		}
		cout << ans;
		return 0;
	}
	if(m == n-1){
		ans = 0;
		for(int i = 1;i <= n;++i){
			ll now;
			if(i != 1)	now = a[1];
			else now = a[2];
			for(int j = 2;j <= n;++j){
				if(j != 1)	now &= a[j];
			}
			ans = max(ans, now);
		}
		cout << ans;
		return 0;
	}
	if(m == n){
		ans = a[1];
		for(int i = 2;i <= n;++i){
			ans &= a[i];
		}
		cout << ans;
		return 0;
	}
	if(ans <= 4){
		ll b[5] = {};
		for(int i = 1;i <= n;++i){
			b[a[i]]++;
		}
		if(b[4] >= m){
			cout << 4;	return 0;
		}
		if(b[3] >= m){
			cout << 3;	return 0;
		}
		if(b[3] + b[2] >= m){
			cout << 2;	return 0;
		}
		if(b[1] >= m){
			cout << 1;	return 0;
		}
		cout << 0; return 0;
	}
	if(A){
		sort(a+1,a+n+1);
		cout << a[n-m+1];
		return 0;
	}
	cout << 0;
	return 0;
} 
