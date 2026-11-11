#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
const ll N=5e5+5;

int n, m;
// t[i] 表示补齐 i 前面所有数所需的能量 
ll a[N], t[N];

void solve1(int n, int m) {
	for(int i=1; i<=n; i++) {
		t[i]=t[i-1]+(a[i]-a[i-1])*(i-1);
	}
	int ans=0;
	for(int i=1; i<=n; i++) {
		for(int j=0; j<i; j++) {
			ll need=t[i]-t[j]-(a[i]-a[j])*j;
			if(need<=m) {
				ans=max(ans, i-j);
			}
		}
	} cout<<ans<<endl;
}

void solve2(int n, int m) {
	ll ta=a[2]-a[1], ts=0;
	int ans=0;
	for(int i=1; i<=n; i++) {
		ts+=ta*i;
		if(ts>m) {
			break;
		} ans=i;
	} cout<<ans<<endl;
}

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	int n, m;
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
	}
	sort(a+1, a+n+1);
	if(n<=5000) {
		solve1(n, m);
	} else if(a[3]-a[2]==a[2]-a[1]) {
		solve2(n, m);
	} else {
		solve1(n, m);
	}
	
	return 0;
}
