#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 5*1e5 + 5;
ll n,m;
ll a[MAXN];
ll cnt = 0;
ll ans = 1;
ll last = 0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> n >> m;
	for (int i = 0;i < n;i++){
		cin >> a[i];
	}
	sort(a,a+n);
	last = a[0];
	for (int i = 1;i < n;i++){
//		cout << "A";
		cnt += ans*(a[i] - last);
		ans++;
		if (cnt > m){
//			printf("AAA");
			cnt -= ans*(a[i] - last);
			--ans;
			break;
		}
		last = a[i];
	}
	cout << ans;
	return 0;
}