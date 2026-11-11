#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = -1e18;
int n,m,ans,cnt,maxn,a[500005];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for (int i = 1;i <= n;i++){cin >> a[i];cnt+=a[i];}
	cnt+=m;cnt/=n;
	for (int i = 1;i <= n;i++){if (a[i]>cnt) a[i] = N;}
	sort(a+1,a+n+1);
	maxn = a[n];
	for (int i = n;i >= 1;i--){
		if (a[i] == N) break;
		if (maxn-a[i] <= m){ans++;m-=(maxn-a[i]);}
	}
	cout << ans;
	return 0;
}
