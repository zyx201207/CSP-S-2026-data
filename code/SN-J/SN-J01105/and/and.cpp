#include<bits/stdc++.h>
#define lint long long
using namespace std;
int n,m,ans,a[200002];
bool ok[200002];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin >> n >> m;
	for(int i = 1;i <= n;i++) cin >> a[i];
	for(int i = 1;i <= n;i++) ok[i] = true;
	for(int lg = 30;lg >= 0;lg--){
		int cnt = 0;
		for(int i = 1;i <= n;i++) if(ok[i] && (a[i] >> lg & 1)) cnt++;
		if(cnt < m) continue;
		ans += 1 << lg;
		for(int i = 1;i <= n;i++) if(!(a[i] >> lg & 1)) ok[i] = false;
	}
	cout << ans;
	return 0;
} 
