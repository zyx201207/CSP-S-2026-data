#include <bits/stdc++.h>
using namespace std;
int a[200005],b[200005];
int maxn = -1e6;
int n,m;
void dfs(int step,int last,int x){
	if(step>m){
		maxn = max(maxn,x);
		return ;
	}
	for(int i = last+1;i<=n;i++){
		b[step] = a[i];
		dfs(step+1,i,x&a[i]); 
	}
}
int main(){
	freopen("add.in","r",stdin);
	freopen("add.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i<=n;i++) scanf("%d",&a[i]);
	dfs(1,0,0x7ffffff);
	cout<<maxn;
	return 0;
}
