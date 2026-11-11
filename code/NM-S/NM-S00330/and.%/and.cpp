#include <bits/stdc++.h>
using namespace std;
long long n,m,a[200010],ans;
void dfs(long long c,long long z,long long s){
	if(s>=m){
		ans=max(ans,z);
		return ;
	}
	if(c>n){
		return ;
	}
	if(s==0){
		dfs(c+1,a[c],s+1);
	}
	else{
		dfs(c+1,(z&a[c]),s+1);
	}
	dfs(c+1,z,s);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<=27){
		dfs(1,0,0);
		cout<<ans;
	}
	else if(m==1){
		for(int i=1;i<=n;i++){
			ans=max(ans,a[i]);
		}
		cout<<ans;
	}
	else if(m==n){
		ans=a[1];
		for(int i=2;i<=n;i++){
			ans=(ans&a[i]);
		}
		cout<<ans;
	}
	return 0;
}
