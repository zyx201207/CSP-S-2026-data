#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5 + 5;
int n,m,a[N],s[N],ans;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin.tie(0) -> sync_with_stdio(0);
	cin >> n >> m;
	for(int i = 1;i <= n;i++)cin >> a[i];
	sort(a + 1,a + n + 1);
	for(int i = 1;i <= n;i++)s[i] = s[i - 1] + a[i];
	for(int i = 1;i <= n;i++){
		int l = i,r = n;
		while(l < r){
			int mid = ceil((l + r)/2.0);
			if(s[mid] - s[i - 1] + m >= a[mid]*(mid - i + 1))l = mid;
			else r = mid - 1;
		}
		ans = max(ans,l - i + 1);
	}
	cout << ans << endl;
	return 0;
}
