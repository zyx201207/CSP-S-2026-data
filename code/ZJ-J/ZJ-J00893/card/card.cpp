#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=500005;
int n,m,a[N],lst[N],islst[N],cnt[N],ans[N];
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for (int i=1; i<=n; i++){
		cin>>a[i];
		islst[lst[a[i]]]=0;
		islst[i]=1;
		lst[a[i]]=i;
		cnt[a[i]]++;
	}
	for (int i=1; i<=n; i++){
		if (!islst[i]) continue;
		ans[a[i]]+=cnt[a[i]];
		ans[a[i+1]]+=ans[a[i]];
	}
	for (int i=1; i<=m; i++) cout<<ans[i]<<' ';
	return 0;
}