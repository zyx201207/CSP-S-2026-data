#include<bits/stdc++.h>
const int N=2e5+10,inf=0x3f3f3f3f;
typedef long long ll;
using namespace std;
int a[N];
int n,m;
bool vis[N];
int maxx=0;
void dfs(int ss,int ans,int u){
	if(u>=ss){
		maxx=max(maxx,ans);
//		cout<<ans<<endl;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]==true) continue;
		vis[i]=true;
		dfs(ss,a[i]&ans,u+1);
		vis[i]=false;
	}
}
void solve(){

	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		int maxx=0;
		for(int i=1;i<=n;i++){
			maxx=max(maxx,a[i]);
		}
		cout<<maxx;
	}else if(m==2){
		int maxx=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				maxx=max(maxx,a[i] & a[j]);
			}
		}
		cout<<maxx;
	}else if(m==n){
		int ans=a[1];
		for(int i=2;i<=n;i++){
			ans&=a[i];
		}
		cout<<ans;
		
	}else if(m==n-1){
		int ans=a[1];
		for(int i=2;i<=m-1;i++){
			ans &= a[i];
		}
		int ans2=a[2];
		for(int i=3;i<=m;i++){
			ans2&=a[i];
		}
		cout<<max(ans,ans2);
	}else if(n<=2000){
		vis[1]=true;
		dfs(m,a[1],1);
		cout<<maxx;
	}else{
		cout<<0;
	}
	return ;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int _=1;
//	cin>>_;
	while(_--) solve();
	return 0;
}
