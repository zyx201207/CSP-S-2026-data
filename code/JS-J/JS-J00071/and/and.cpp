#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200010];
int maxx=-1;
int ans;
int vis[200010];
void dfs(int step,int ans,int b){
	if(step==m){
		maxx=max(maxx,ans);
		return;
	}
	if(b>n)return;
	if(ans==0)
	{
		dfs(step+1,a[b],b+1);
		dfs(step,0,b+1);
	}
	else{
		dfs(step+1,a[b]&ans,b+1);
		dfs(step,ans,b+1);
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxx=max(maxx,a[i]);
	}
	if(m==1){
		cout<<maxx;return 0;
	}
	else maxx=-1;
	if(m==n){
		ans=a[1];
		for(int i=2;i<=n;i++){
			ans=ans&a[i];
		}
		cout<<ans;return 0;
	}
	dfs(0,0,1);
	cout<<maxx;
	return 0;
}
