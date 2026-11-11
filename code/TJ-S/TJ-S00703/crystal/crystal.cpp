#include<bits/stdc++.h>
using namespace std;
const int N = 5e5+9;
typedef long long ll;
ll n, m;
ll a[N];
int main(){
	//记得开freopen！！！！！！！！！！！！！！ 
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); 
	cout.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	sort(a+1, a+n+1);
	ll last = -1e18; 
	bool ok = true;
	for(int i = 2; i <= n; i++){
		if(last == -1e18)last = a[i]-a[i-1];
		else {
			if(last != a[i]-a[i-1]){
				ok = false;
				break;
			}
		}
	} 
	if(ok == true){
		ll maxn = 1;
		ll sum = 0;
		for(int i = 1; i < n; i++){
			ll d = a[i+1]-a[i];
			ll dist = d*i*1LL;
			sum += dist;
			if(sum > m)break;
			maxn++;
		}
		cout << maxn << '\n';
		return 0;
	}
	ll maxn = 1; 
	for(int pos = 1; pos < n; pos++){
		ll sum = 0;
		ll ans = 1;
		for(int i = 1; i < n-pos+1; i++){
			int tmp = i+pos-1;
			ll d = a[tmp+1]-a[tmp];
			ll dist = d*i*1LL;//前面所有加上现在到下一个的距离 
			sum += dist;
			if(sum > m)break;
			ans++;
		}
		maxn = max(maxn, ans); 
	} 
	cout << maxn << '\n';
	return 0;//考虑优化重复的东西 
} 
