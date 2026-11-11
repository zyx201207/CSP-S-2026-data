#include<bits/stdc++.h>
using namespace std;

const int N=2e5+5;
int n,m,a[N],dp[N],vis[N],ans=0x3f3f3f3f,maxx; 

void dfs(int x){
	if(x>m){
		maxx=max(maxx,ans);
		return ;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			int t=ans;
			ans&=a[i];
			dfs(x+1);
			vis[i]=0;
			ans=t;
		}
	}
}
int main(){
	
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>m;
	if(m==1){
		for(int i=1;i<=n;i++){
			cin>>a[i];
			maxx=max(maxx,a[i]);
		}
		cout<<maxx;
		return 0;
	}
	else if(m==n){
		for(int i=1;i<=n;i++){
			cin>>a[i];
			ans&=a[i];
		}
		cout<<ans;
	}
	else if(m==2){
		for(int i=1;i<=n;i++) cin>>a[i];
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				maxx=max(maxx,a[i]&a[j]);
			}
		}
		cout<<maxx;
	}
	else if(n<=20){
		for(int i=1;i<=n;i++) cin>>a[i];
		dfs(1);
		cout<<maxx;
	}
	
	return 0;
}
