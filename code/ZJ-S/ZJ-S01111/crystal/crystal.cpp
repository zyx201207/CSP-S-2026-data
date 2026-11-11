#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 500010;
int n,m,ans = 1;
int a[N];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	sort(a + 1,a + n + 1);
	for(int l = 1,r = 2,k = a[1];r <= n;r++){
		int len = r - l + 1;
		if(a[r] == k){
			ans = max(ans,len);
			continue;
		}
		if((a[r] - k) * (len - 1) <= m){
			m -= (a[r] - k) * (len - 1);
			k = a[r];
			ans = max(ans,len);
		}else{
			while((a[r] - k) * (len - 1) > m && l <= r){
				m += k - a[l];
				l++;
				len--;
			}
			ans = max(ans,len);
		}
	}
	cout << ans;
	return 0;
}