#include<bits/stdc++.h>
#define ll long long
using namespace std;
int maxx,n,m;
int a[200005];
void dfs(int xxx,int cnt,int ans){
	if(ans==0){
		return ;
	}
	if(cnt==m){
		maxx=max(maxx,ans);
		return ;
	}
	for(int i=xxx;i<=n;i++){

			dfs(i+1,cnt+1,ans&a[i]);
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);


	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(1,0,2147483647);
	cout<<maxx;
}
