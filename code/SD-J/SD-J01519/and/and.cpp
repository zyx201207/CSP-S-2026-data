#include<bits/stdc++.h>
using namespace std;
const int N=2e5+1;
#define int long long
int n,m,a[N],ans;
void dfs(int p,int cnt,int sum,bool choose){
	if(cnt==m){
		ans=max(ans,sum);
		return ;
	}
	if(p+(m-cnt)>n) return ;
	if(choose){
		for(int i=p+1;i<=n;i++){
			dfs(i,cnt+1,sum&a[i],1);
			dfs(i,cnt,sum&a[i],0);
		}
	}
	else{
		for(int i=p+1;i<=n;i++){
			dfs(i,cnt,sum,1);
			dfs(i,cnt,sum,0);
		}
	}
	return ;
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(n==m){
		ans=a[1];
		for(int i=2;i<=n;i++) ans&=a[i];
		cout<<ans<<'\n';
		return 0;
	}
	for(int i=1;i<=n-m+1;i++) dfs(i,1,a[i],1);
	dfs(1,0,1,0);
	cout<<ans<<'\n';
	return 0;
}

