#include <bits/stdc++.h>
using namespace std;
#define int unsigned long long
const int N=2e5+5;
int a[N],res=0;
int n,m;
void dfs(int l,int ans,int j){
	if(l==m){
		res=max(res,ans);
		return;
	}
	for(int i=j+1;i<=n;i++){
		if(l==0) ans=a[i];
		dfs(l+1,ans&a[i],i);
	}
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	dfs(0,0,0);
	cout<<res<<endl;
	return 0;
}
