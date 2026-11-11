#include<bits/stdc++.h>
using namespace std;
long long int n,m,ans=0;
long long int a[200005]; 

void dfs(int x,int i,long long int cnt){
	if(x>=m){
		ans=max(cnt,ans);
		return;
	}
	if(i>n) return;
	for(int j=i+1;j<=n;j++){
		if(x==0) dfs(x+1,j,a[j]);
		else dfs(x+1,j,cnt&a[j]);
	}
	return;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	dfs(0,0,0);
	cout<<ans;
	
	return 0;
}
