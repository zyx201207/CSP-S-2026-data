#include<bits/stdc++.h>
using namespace std;
int n,m,a[200020],mx=-1;
void dfs(int x,int k,int sum){
	if(k==m){
		mx=max(mx,sum);
	}
	if(x>n){
		return ;
	}
	if(k==0){
		dfs(x+1,k+1,a[x]);
	}
	else{
		dfs(x+1,k+1,(sum&a[x]));
	}
	dfs(x+1,k,sum);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n>20000){
		sort(a+1,a+n+1);
		cout<<a[n+1-m];
		return 0;
	}
	dfs(1,0,0);
	cout<<mx;
}

