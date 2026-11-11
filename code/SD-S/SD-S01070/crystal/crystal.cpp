#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e5 + 10;
ll n,m;
ll a[N];
bool chk(ll X){
	ll pre = 0,suf = 0;
	ll p2 = X,cnt1 = 0,cnt2 = 0;
	ll pos = X;
	for(int i = 1;i < X;i ++){
		pre += a[i],cnt1 ++;
	}
	ll tmp = (X - 1) * a[pos] - pre;
	if(tmp <= m){
		return true;
	}
	for(int i = 2;i <= n;i ++){
		pre -= a[i - 1],pre += a[pos];
		pos ++;
		if(pos > n)break;
		tmp = (X - 1) * a[pos] - pre;
		if(tmp <= m){
			return true;
		}
	}
	return false;
}
bool cmp(ll A,ll B){
	return A < B;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	
	cin >> n >> m;
	for(int i = 1;i <= n;i ++){
		cin >> a[i];
	}
	sort(a + 1,a + 1 + n,cmp);
	ll l = 1 - 1,r = n + 1;
	while(l + 1 < r){
		ll mid = l + r >> 1;
		if(chk(mid))l = mid;
		else r = mid;
	}
	
	cout << l << "\n";
	
	
	
	
	
	
	return 0;
} 
