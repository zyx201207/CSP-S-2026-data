#include<bits/stdc++.h>
using namespace std;
struct node{
	int v,t;
}s[501][501];
int c,n,m,d,t,a[501],cnt[501];
long long ans=0;
inline void dfs(int idx,int jdx,ans,int r){
	if(s[idx][idj].v==r){
		cout<<ans<<'\n';
		return ;
	}
	for(int i=idx;i<=n;i++){
		for(int j=1;j<=cnt[i];j++){
			if(cnt[i]==1)dfs(i+1,1,ans,r);
			else dfs(s[i][j].v),dfs(i,j+1,ans+s[i][j+1].t,r);
		}
	}
}
inline void solve(){
	int l,r;
	cin>>l>>r;
	ans+=a[l]+a[r];
	dfs(1,ans,r);
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>t;
	for(int i=1;i<=m;i++){
		cin>>a[i];
	}for(int i=1;i<=n;i++){
		cin>>cnt[i];
		for(int j=1;j<=cnt[i];j++){
			cin>>s[i][j].v>>s[i][j].t;
		}
	}while(t--){
		solve();
	}
	return 0;
