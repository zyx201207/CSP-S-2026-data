#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m,ans,k,s[500010],num,nw,cnt;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio();
	cin.tie(0);
	cin >> n >> m;
	for(int a = 1;a <= n;a++) cin >> s[a];
	sort(s+1,s+n+1);
	for(int a = 1;a <= n;a++){
		while(nw + cnt * (s[a] - s[a - 1]) > m){
			nw -= (s[a - 1] - s[a - cnt]);
			cnt--;
		}
		nw += cnt * (s[a] - s[a - 1]);
		cnt++;
		ans = max(ans,cnt);
	}
	cout << ans;
	return(0);
}
