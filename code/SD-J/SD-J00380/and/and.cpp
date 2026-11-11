#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,Max;
int a[200005];
void dfs(int x,int t,int p){
	if(t==m){
		Max=max(Max,p); 
		return ;
	}
	if(x>n){
		return ;
	}
	if(t==0){
		dfs(x+1,t+1,a[x]);
		dfs(x+1,t,0);
	}
	else{
		dfs(x+1,t+1,p&a[x]);
		dfs(x+1,t,p);
	}
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==n){
		int ans=a[1];
		for(int i=2;i<=n;i++){
			ans&=a[i];
		}
		cout<<ans;
		return 0;
	}
	dfs(1,0,0);
	cout<<Max;
	return 0;
}

