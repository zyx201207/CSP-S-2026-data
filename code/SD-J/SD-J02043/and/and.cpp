#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[10000001],dp[10000001],m,ans;
string s1,s2,s3,s4;
void dfs(int v,int di,int ind) {
	//cout<<v<<" "<<di<<" "<<ind<<endl;
	if(di==m) {
		ans=max(ans,v);
		return;
	}
	for(int i=ind+1; i<=n; i++) {

		dfs((v&a[i]),di+1,i);

	}
	return;
}
signed main() {
	//cout<<(31&15);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
	}
	for(int i=1; i<=n; i++) {
		//vis[i]=1;
		dfs(a[i],1,i);
		//vis[i]=0;
	}
	cout<<ans<<endl;
	return 0;
}/*5 3
31 3 1 15 7*/
