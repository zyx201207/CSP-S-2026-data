#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e5 + 5;
ll n,ans,cnt,ac;
unsigned long long m;
ll a[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	sort(a + 1,a + n + 1);

	ll cha = a[2] - a[1];
	bool isd = 1;
	for(int i = 2;i < n;i++){
		if((a[i + 1] - a[i]) != cha){
			isd = 0;
		}
	}
	if(isd){
		ll ljh = 1,wqr = 1;
		while(m > 0 && m >= (wqr * cha)){
			m -= wqr * cha;
			wqr++;
			ljh++;
		}
		cout << ljh;
		return 0;
	}

	for(int i = 1;i <= n - ans;i++){
		ac = m;
		cnt = 1;
		for(int j = 1;j <= n;j++){
			// jshr
			ll sum = (a[j + 1] - a[j]) * (j - i + 1);
			if(sum <= m){
				cnt++;
				m -= sum;
			}else break;
		}
		m = ac;
		ans = max(ans,cnt);
	}
	cout << ans;
	return 0;
}