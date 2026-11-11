#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int N = 5e5+5;

int n; ll m;
ll a[N];

bool check(int k){
	ll sum = 0;
	for(int i = 1; i <= k-1; i++)
		sum += a[i];
	for(int i = k; i <= n; i++){
		ll maxx = a[i];
		sum += a[i]; sum -= a[i-k];
		ll dis = 1LL*k*maxx-sum;
		if(dis <= m) return true;
	}
	
	return false;
}

int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
		
	sort(a+1, a+1+n);
	
	int l = 1, r = n;
	while(l < r){
		int mid = (l+r+1)>>1;
		if(check(mid)) l = mid;
		else r = mid-1;
	}
	
	cout << l << '\n';
	
	return 0;
}
