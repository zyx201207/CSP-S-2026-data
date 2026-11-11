#include<bits/stdc++.h>
#define lint long long
using namespace std;
lint n,m,ans,l,a[500005],s[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin >> n >> m;
	for(int i = 1;i <= n;i++) cin >> a[i];
	sort(a + 1,a + n + 1);
	for(int i = 1;i <= n;i++) s[i] = s[i - 1] + a[i];
	l = 1;
	for(int i = 1;i <= n;i++){
		while(a[i] * (i - l + 1) - (s[i] - s[l - 1]) > m && l <= i) l++;
		ans = max(ans,i - l + 1);
	}
	cout << ans;
	return 0;
}
