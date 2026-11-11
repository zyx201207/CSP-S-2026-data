#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll N = 5e5 + 5;
ll nzh, me;
ll a[N];

signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> nzh >> me;
	for(ll i = 1;i <= nzh;i ++) cin >> a[i];
	//cout << (me == 0) << endl;
	if(me == 0){
		ll num = 1;
		ll ans = 0;
		for(ll i = 2;i <= nzh;i ++){
			if(a[i] != a[i - 1]){
				ans = max(ans, num);
				num = 1;
			}
			else num += 1;
		}
		ans = max(ans, num);
		cout << ans;
		return 0;
	}
	ll numa = 1;
	ll anss = -1;
	ll suma = me;
	sort(a + 1,a + 1 + nzh);
	for(ll i = 2;i <= nzh;i ++){
		if(a[i] != a[i - 1]){
			anss = max(anss, numa);
			numa = 1;
		}
		else numa += 1;
	}
	anss = max(anss, numa);
	//for(ll i = 1;i <= nzh;i ++) cout << a[i] << " ";
	//cout << endl;
	numa = 1;
	suma = me;
	bool flag = true;
	for(ll i = 2;i <= nzh;i ++){
		ll d = a[i] - a[i - 1];
		if(suma - d * numa >= 0){
			suma -= d * numa;
			numa += 1;
			flag = true;
		} 
		else{
			anss = max(anss, numa);
			suma = me;
			numa = 1;
			i -= 1;
			if(!flag) break;
			flag = false;
		}
		//cout << "i" << i <<endl;
		//cout << "d:" << d <<endl;
		//cout << "sum:" << suma << endl;
		//cout << "num:" << numa << endl;
	}
	anss = max(anss, numa);
	cout << anss;
	return 0;
} 
