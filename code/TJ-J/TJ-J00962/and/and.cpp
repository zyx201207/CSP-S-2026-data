#include<bits/stdc++.h>
#define int long long
using namespace std;
int ans=0;
void dfs(int n,int m,vector<int> &v,int result=2147483647,int c=0,int deep=0){
	if(deep==m){
		ans=max(result,ans);
		return;
	}
	for(int i=c;i<n-m+deep+1;i++){
		dfs(n,m,v,result&v[i],i+1,deep+1);
	}
	return;
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
 	int n,m;
 	cin>>n>>m;
 	vector<int> v(n);
 	for(int i=0;i<n;i++){
 		cin>>v[i];
	}
	dfs(n,m,v);
	cout<<ans;
	return 0;
} 
