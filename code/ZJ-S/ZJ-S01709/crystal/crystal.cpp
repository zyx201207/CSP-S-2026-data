#include<iostream>
#include<cstdio>
#include <algorithm>
using namespace std;
using ll = long long;
const int N = 5e5 +3;
ll a[N];
ll n,m;
ll c[N];
ll qzhc[N];
void fopen(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
}
bool check(ll x){
	if(qzhc[x]<=m){
		return 1;
	}
	return 0;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	fopen();
	cin >>n>>m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	sort(a+1,a+1+n);

	for(int i=1;i<=n;i++){
		qzhc[i] = qzhc[i-1]+1ll*(a[i]-a[i-1])*(i-1);
	}

	int l = 1,r = n;
	ll ans=0;
	while(l < r){// <= or <
		int mid = (l+r)/2;
		if (check(mid)){
			ans = mid;
			l = mid+1;
		}
		else{
			r = mid-1;
		}
	}

	cout << ans;
	return 0;
}