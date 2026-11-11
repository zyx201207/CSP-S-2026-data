#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int N = 5e5+1;
int n,m,a[N],lsh[N],tmp[N],pre[N],len = 0;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin >> n >> m;
	for(int i = 1;i<=n;++i){
		cin >> a[i];
		lsh[++len] = a[i];
	}
	sort(lsh+1,lsh+len+1);
	len = unique(lsh+1,lsh+len+1)-lsh-1;
	int ans = 0;
	for(int i = 1;i<=n;++i){
		a[i] = lower_bound(lsh+1,lsh+len+1,a[i])-lsh;
		++tmp[a[i]];
		ans = max(ans,tmp[a[i]]);
	}
	sort(a+1,a+n+1);
	for(int i = 1;i<=n;++i){
		pre[i] = pre[i-1]+lsh[a[i]];
	}
	for(int i = 1;i<=n;++i){
		int l = 1,r = i;
		while(l<r){
			int mid = (l+r)>>1;
			if((i-mid+1)*lsh[a[i]]-pre[i]+pre[mid-1]<=m){
				r = mid;
			}else{
				l = mid+1;
			}
		}
		ans = max(ans,i-l+1);
	}
	cout << ans;
	return 0;
}
