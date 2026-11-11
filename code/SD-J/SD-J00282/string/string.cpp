#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 2e5 + 7;
int n, c[N];
char x;
ll ans, a[N];

void Solve(){
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i] >> x;
		c[i] = (int)(x - 'a');
		ans += a[i];
	}
	int l = 1, r = n;
	ll now = 0; 
	while(l < r){
		if(c[l] == c[r])
			ans -= 2 * min(a[l], a[r]);
		else
			ans -= min(a[l], a[r]);
		now = a[l] - a[r];
		if(now == 0){
			l++;
			r--;
		}
		else if(now > 0){
			a[l] -= a[r];
			r--;
		}
		else{
			a[r] -= a[l];
			l++;
		}
	}
	ans -= abs(now);
	cout << ans;
}

int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int T = 1;//cin >> T;
	while(T--)
		Solve();
	return 0;
}

