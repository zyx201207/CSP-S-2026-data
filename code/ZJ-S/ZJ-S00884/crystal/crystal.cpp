#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
const ll N = 500010;
ll n,m,a[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for(ll i = 1 ; i <= n ; i++) cin >> a[i];
	sort(a+1,a+1+n);
	ll l = 1,cnt = 1,sum = 0,ans = 1;
	for(ll i = 2 ; i <= n ; i++){
		sum += cnt*(a[i]-a[i-1]);
		cnt++;
		while(sum > m){
			sum -= a[i]-a[l];
			cnt--;
			l++;
		}
		ans = max(ans,cnt);
	}
	cout << ans << endl;
	return 0;
}
/*
csp rp++
我能拿下第一个csps 1=吗
ccf大样例不要太水好吗
*/