#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],ans;
void dfs(int x,int id,int c){
	if(c==m){
		ans=max(ans,x);
		return ;
	}
	if(id>n)
		return ;
	dfs(x&a[id],id+1,c+1);
	dfs(x,id+1,c);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	n=unique(a+1,a+n+1)-a-1;
	for(int i=1;i<=n-m+1;i++)
		dfs(a[i],i+1,1);
	cout<<ans;
	return 0;
} 
