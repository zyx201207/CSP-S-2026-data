#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
using u64 = unsigned long long;
#define N 500005
int n,m,cnt[N];
i64 a[N],b[N],sum[N];
template<typename T>
T chkmax(T x,T y){
	if(x < y)return y;
	return x;
}
template<typename T>
T chkmin(T x,T y){
	if(x > y)return y;
	return x;
}
void solve(){
	memset(sum,0,sizeof(sum));
	memset(cnt,0,sizeof(cnt));
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		b[i] = a[i];
	}
	sort(a + 1,a + n + 1);
	sort(b + 1,b + n + 1);
	int len = unique(b + 1,b + n + 1) - b - 1;
	for(int i = 1; i <= n; i++){
		a[i] = lower_bound(b + 1,b + len + 1,a[i]) - b;
		++cnt[a[i]];
		sum[i] = sum[i - 1] + b[a[i]];
	}
	int ans = 0;
	for(int i = 1; i <= n; i++){
		ans = chkmax(ans,cnt[a[i]]);
		int l = 1,r = i - 1,x = i;
		while(l <= r){
			int mid = (l + r) >> 1;
			if(sum[i - 1] - sum[mid - 1] + m >= (i - mid) * b[a[i]]){
				x = mid;
				r = mid - 1;
			}else{
				l = mid + 1;
			}
		}
		ans = chkmax(ans,cnt[a[i]] + i - x);
		--cnt[a[i]];
	}
	cout << ans << endl;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int T = 1;
	//cin >> T;
	while(T--)solve();
	return 0;
}
