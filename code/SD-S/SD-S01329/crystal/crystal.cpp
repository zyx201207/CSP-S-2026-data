#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500009],s[500009],ans;
int main(){
	cin.tie(0)->ios::sync_with_stdio(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	sort(a + 1,a + n + 1);
	for(int i = 1;i <= n;i++){
		s[i] = s[i - 1] + a[i];
		int l = 1,r = i;
		while(l < r){
			long long mid = ((l + r) >> 1);
			if(a[i] * (i - mid + 1) - (s[i] - s[mid - 1]) <= m){
				r = mid;
			}
			else{
				l = mid + 1;
			}
		}
//		cout << i << ' ' << l << '\n';
		ans = max(ans,i - l + 1LL);
	}
	cout << ans;
	return 0;
}
