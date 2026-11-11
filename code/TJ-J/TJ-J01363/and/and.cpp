#include<bits/stdc++.h>
using namespace std;
int a[200005],dp[200005];
int n,m,msx=-1;
void dfs(int x,int d,int h){
	if(d==m){
		msx=max(msx,h);
		return;
	}
	if(x==n+1){
		return ;
	}
	if(d==0){
		dfs(x+1,1,a[x]);
		dfs(x+1,0,0);
	}else{
		dfs(x+1,d+1,(h&a[x]));
		dfs(x+1,d,h);
	}
}
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
	}
	if(m==1){
		for(int i=1;i<=n;i++){
			msx=max(msx,a[i]);
		}
		cout<<msx;
	}else if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==j){
					continue;
				}
				msx=max(msx,(a[i]&a[j]));
			}
		}
		cout<<msx;
	}else{
		dfs(0,0,0);
		cout<<msx;
	}
	return 0;
}
