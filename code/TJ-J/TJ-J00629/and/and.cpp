#include<bits/stdc++.h>
using namespace std;
int n,m;int a[200005];int dp[200005];
int maxans=0;
void dfs(int nowx,int ans,int yi){
	if(yi==m){
		if(ans!=(2<<22)-1)
		maxans=max(maxans,ans);
		return;
	}
	else if(nowx==n){
		return;
	}
	dfs(nowx+1,ans&a[nowx+1],yi+1);
	dfs(nowx+1,ans,yi);
	
}
bool cmp(int x,int y){
	return x>y;
}
int main(){
	
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<=2000){
		dfs(0,(2<<22)-1,0);
	}
	else {
		sort(a+1,a+n+1,cmp);
		cout<<a[m];
	}
	cout<<maxans;
	return 0;
}
