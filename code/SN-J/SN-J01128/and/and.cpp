//SN-J00594 张源朔 西安市高新第二初级中学 621123201306230018

#include <bits/stdc++.h>

using namespace std;
int n,m;
long long a[200010]={};
long long maxn=0;	
void dfs(int x,long long y){
	if(x==m){
		maxn=max(y,maxn);
		return;
	}
	for(int i=1;i<=n;i++){
		if(x==0){
			dfs(x+1,a[i]);
		}
		else{
			dfs(x+1,a[i]&y);
		}
	}
}	
	
int main() {
//	freopen("and.in","r",stdin);
//	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(0,0);
	cout<<maxn; 
	return 0 ;
}
