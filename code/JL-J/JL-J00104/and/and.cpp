#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+10;
int n,m,a[N],maxn;
void dfs(int u,int ans,int cnt){
	if(cnt==m+1){
		maxn=max(ans,maxn);
		return;
	}
	if(u==n+1){
		return;
	}
	for(int i=u+1;i<=n;i++){
		dfs(i,ans&a[i],cnt+1);
	}
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	// sort(a+1,a+1+n,cmp);
	// dfs(1,a[1],2);
	for(int i=1;i<=n;i++){
		dfs(i,a[i],2);
	}
	cout<<maxn<<endl;
}