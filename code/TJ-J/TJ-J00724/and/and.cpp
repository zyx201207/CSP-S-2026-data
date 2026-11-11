#include <bits/stdc++.h>
using namespace std;

int n,m,a[100005]={},he=0,f=0;

void dfs(int ne, int h){
	if(ne>n){
		he=max(he,h);
		return;
	}
	if(n==m==1){
		he=a[n];
		return;
	}
	for(int j=1;j<m;j++){
		if(ne==1)coutinue;
		else{
			f=a[ne]&a[ne-1];
			dfs(ne+1,h+f);
			dfs(ne+1,h);
		}
	}
}

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(1,0);
	cout<<he;
	return 0;
}
