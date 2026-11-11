#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[200005],maxx=-1;
void dfs(int x,int nm,long long sm){
	if(x>n) return;
	if(nm==m){
		maxx=max(maxx,sm);
		return;
	}
	if(sm==-1){
		dfs(x+1,nm+1,a[x]);
		dfs(x+1,nm,sm);
		return;
	}
	dfs(x+1,nm+1,(sm&a[x]));
	dfs(x+1,nm,sm);
	return;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(1,0,-1);
	cout<<maxx;
	return 0;
}

