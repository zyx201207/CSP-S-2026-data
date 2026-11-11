#include<bits/stdc++.h>
using namespace std;
int a[200005];
int n,m,ans;
void dfs(int val,int x,int pos){
	if(x==m){
		ans=max(ans,val);
		return;
	}
	for(int i=pos+1;i<=n-m+x+1;i++){
		dfs(val&a[i],x+1,i);
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n-m+1;i++)
		dfs(a[i],1,i);
	cout<<ans;
	return 0;
}
