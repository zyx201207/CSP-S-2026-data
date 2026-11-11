#include <bits/stdc++.h>
#define ll long long
using namespace std;
int n;
ll m;
ll a[500005];
ll ans[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	if(n <= 5000){
		for(int i = 1;i <= n;i++){
			for(int j = 1;j <= n;j++){
				ans[i] += a[i]-a[j];
			}
		}
		ll num = 0;
		ll maxn = -1e9;
		for(int i = 1;i <= n;i++){
			if(ans[i] <= m){
				if(ans[i] >= maxn){
					maxn = ans[i];
					num = i;
				}
			}
		}
		cout << num;
		return 0;
	}else{
		int c = a[2]-a[1];
		for(int i = 1;i <= n;i++){
			ans[i] = (i-1)*i*c/2;
		}
		int i = 2;
		ll cnt = 1;
		while(m >= 0){
			m -= ans[i];
			cnt++;
			i++;
		}
		if(m < 0) cnt--;
		cout << cnt;
		return 0;
	}
	return 0;
}
