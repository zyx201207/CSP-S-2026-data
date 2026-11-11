#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,ans,a[500010],s[500010];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++) cin >> a[i];
	sort(a + 1,a + n + 1);
	for(int i = 1,j = 0;i <= n;i++){
		s[i] = s[i - 1] + a[i];
		while((i - j) * a[i] - s[i] + s[j] > m) j++;
		ans = max(ans,i - j);
	}
	cout << ans;
	return 0;
}
