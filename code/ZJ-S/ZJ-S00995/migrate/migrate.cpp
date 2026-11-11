#include<bits/stdc++.h>
using namespace std;
#define int long long
constexpr int N=2000100,inf=0x3f3f3f3f3f3f3f3f;
int n,d,x[N],pre[N];
int dp[N][6];
int dfs(int l,int mid,int flg,int r,int op){
	if(l>r) return 0;
	int *tmp=&dp[r+1][op];
	if(*tmp!=inf) return *tmp;
	if(l==r){
		if(l==mid) return *tmp=dfs(pre[l],l-1,l-1,l-1,0);
		if(l-1==mid){
			if(l==flg) return  *tmp=l-pre[l]+dfs(pre[l],pre[l]-1,l-1,l-1,1);
			if(l-1==flg) return  *tmp=0;
		}
	}
	if(l+1==r){
		if(l+1==mid) return  *tmp=l-pre[l+1]+dfs(pre[l],pre[l+1]-1,l-1,l-1,2);
		if(l==mid) return  *tmp=dfs(pre[l],pre[l+1]-1,pre[l+1]-1,l-1,3);
		if(l-1==mid){
			if(l<=flg) return *tmp=pre[l+1]-pre[l]+dfs(pre[l],pre[l]-1,pre[l+1]-1,l-1,4);
			if(l-1==flg) return *tmp=0;
		}
	}
	if(l+1<=mid) return  *tmp=pre[l+2]-pre[l+1]+dfs(pre[l],pre[l+1]-1,pre[l+2]-1,l-1,5);
	if(l==mid){
		return  *tmp=dfs(pre[l],pre[l+1]-1,pre[l+1]-1,l-1,3);
	}
	if(l-1==mid){
		if(l<=flg) return  *tmp=pre[l+1]-pre[l]+dfs(pre[l],pre[l]-1,pre[l+1]-1,l-1,4);
		if(l-1==flg) return  *tmp=0;
	}
	return 0;
}
void solve(){
	cin>>n>>d;
	for(int i=1;i<=n;i++){
		cin>>x[i];
		pre[i]=pre[i-1];
		while(x[pre[i]]<x[i]-d) pre[i]++;
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		ans+=dfs(pre[i],i-1,i-1,i-1,0);
	}
	cout<<ans<<'\n';
	for(int i=1;i<=n;i++){
		x[i]=pre[i]=0;
		for(int j=0;j<6;j++) dp[i][j]=inf;
	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int C,T;
	cin>>C>>T;
	x[0]=-inf;
	memset(dp,0x3f,sizeof(dp));
	while(T--) solve();
	return 0;
}