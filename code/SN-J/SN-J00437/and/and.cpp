#include<bits/stdc++.h>
using namespace std;
int n,m,maxx;
int a[200100];
void dfs(int o,int c,int ans){
	if(c==m){
		maxx=max(maxx,ans);
		return;
	}
	for(int i=o+1;i<=n-m+1+c;i++){
		dfs(i,c+1,ans&a[i]);
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];	
	if(m==1){
		for(int i=1;i<=n;i++)maxx=max(maxx,a[i]);
		cout<<maxx<<'\n';
	}else if(m==n){
		maxx=a[1];
		for(int i=2;i<=n;i++)maxx&=a[i];
		cout<<maxx;
	}else{
		for(int i=1;i<=n-m+1;i++)dfs(i,1,a[i]);
		cout<<maxx;
	}
	return 0;
}
