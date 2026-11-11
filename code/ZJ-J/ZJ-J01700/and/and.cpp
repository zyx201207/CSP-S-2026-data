#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200008],vis[200008],ma;
void dfs(long long x,long long s){
	if(x==m+1){
		if(s>ma) ma=s;
		return;
	}
	for(int i=n;i>=1;i--){
		if(vis[i]==1 || s&a[i]<ma) continue;
    	vis[i]=1;
    	dfs(x+1,s&a[i]);
    	vis[i]=0;
	}
}
int main(){
	freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
    for(int i=n;i>=m;i--){
    	vis[i]=1;
    	dfs(2,a[i]);
	}
	cout<<ma;
	return 0;
} 