#include<bits/stdc++.h>
#define IO ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define int long long
using namespace std;
const int N=2e5+5;
int n,m,a[N],ans;
inline void dfs(int x,int pre,int s){
	if(x==m+1){
		ans=max(ans,s);
		return;
	}
	if(s<=ans) return;
	for(int i=pre+1;i<=n;i++){
		dfs(x+1,i,(s&a[i]));
	}
	return;
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	IO;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(1,0,(1ll<<32)-1);
	cout<<ans<<'\n';

	return 0;
}

