#include<bits/stdc++.h>
using namespace std;
int n,m;
int b[200005];
int ans;

void dfs(int i,int l,int s){
	if(s<ans)return;
	if(l==m){
		ans=max(s,ans);
		return;
	}
	for(int j=i+1;j<n;j++){
		dfs(j,l+1,(s&b[j]));
	}
}

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie();
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>b[i];
	}
	for(int j=0;j<n;j++){
		dfs(j,1,b[j]);
	}      
	cout<<ans;
	return 0;
}
/*
*/