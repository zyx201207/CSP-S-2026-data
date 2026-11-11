#include<bits/stdc++.h>
using namespace std;
int n,m,mmax=INT_MIN;
int a[200001];
void dfs(int x,int cnt,int ans){
	if(cnt==m){
		mmax=max(mmax,ans);
		return;
	}
	if(x>n){
		return;
	}
	dfs(x+1,cnt,ans);
	if(ans==0) {
		dfs(x+1,cnt+1,a[x]);
	}
	else
		dfs(x+1,cnt+1,a[x]&ans);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==m){
		int ans=a[1];
		for(int i=2;i<=n;i++){
			ans=ans&a[i];
		}
		cout<<ans;
		return 0;
	}
	if(n-1==m){
		int ans;
		for(int i=1;i<=n;i++){
			if(i!=1) ans=a[1];
			else ans=a[2];
			for(int j=1;j<=n;j++){
				if(j!=i) ans=ans&a[j];
			}
		}
		cout<<ans;
		return 0;
	}
	dfs(1,0,0);
	cout<<mmax;
	return 0; 
}
