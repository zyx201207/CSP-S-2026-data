#include<bits/stdc++.h>
using namespace std;
int n,m,ma;
int a[200005];
void dfs(int cnt,int ans,int f){
	if(cnt==m){
		ma=max(ans,ma);
		return ;
	}
	if(f==n+1) return;
	if(cnt==0) dfs(cnt+1,a[f],f+1);
	else dfs(cnt+1,ans&a[f],f+1);
	dfs(cnt,ans,f+1);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(0,0,1);
	cout<<ma;
	return 0;
}
