#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=200005;
int n,m,a[N],vis[N],ans;
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for (int i=1; i<=n; i++) cin>>a[i],vis[i]=1;
	for (int bin=30; bin>=0; bin--){
		int cnt=0;
		for (int i=1; i<=n; i++){
			if (((a[i]>>bin)&1) && vis[i]==1) cnt++;
		}
		if (cnt<m) continue;
		ans+=(1<<bin);
		for (int i=1; i<=n; i++){
			if (!((a[i]>>bin)&1)) vis[i]=0;
		}
	}
	cout<<ans;
	return 0;
}