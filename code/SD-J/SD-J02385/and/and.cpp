#include<bits/stdc++.h>
using namespace std;
int n,m,a[1000005],ans;
void dfs(int d,int s,int l){
	if(s==0) return ;
	if(l>n&&(s<=ans||d<=m)) return ;
	if(d==m+1){
	    ans=max(ans,s);return ;
	}
	if(d==1)dfs(d,a[l+1],l+1);
	else dfs(d,s,l+1);
	dfs(d+1,s&a[l],l+1);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	dfs(1,a[1],1);cout<<ans;
	return 0;
}
