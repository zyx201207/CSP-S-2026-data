#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int n,m,a[N],pre[N],ans,cnt,sum;
signed main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;ans=1;int l=1;
	for(int i=1;i<=n;i++) cin >> a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) pre[i]=pre[i-1]+a[i];
	for(int i=1;i<=n;i++){
		cnt=(i-l+1)*a[i]-(pre[i]-pre[l-1]);
		while(cnt>m) l++,cnt=(i-l+1)*a[i]-(pre[i]-pre[l-1]);
		ans=max(ans,i-l+1);
	}
	cout << ans;
	return 0;
}
