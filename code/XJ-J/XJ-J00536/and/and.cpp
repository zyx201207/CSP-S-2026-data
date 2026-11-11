#include <bits/stdc++.h>
using namespace std;
int n,m,maxx=-999;
int a[200010];
void dfs(int c,int sum,int nxt) {
	if(c==0) {
		maxx=max(sum,maxx);
		return;
	} 
	for(int i=nxt;i<n-c+1;i++) {
		if(sum==0) dfs(c-1,a[i],i+1);
		else dfs(c-1,sum&a[i],i+1);
	}
}
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++) cin>>a[i];
	dfs(m,0,0);
	cout<<maxx;
	return 0;
}