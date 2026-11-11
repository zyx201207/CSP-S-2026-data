/*
4 2
3 15 12 12
*/
#include<bits/stdc++.h>
using namespace std;
long long a[200010];
int n,m,ans=INT_MIN;
void dfs(int k,int c,int z){
	if(c<=0){
		ans=max(ans,z);
		return;
	}
	//cout<<k<<" "<<c<<" "<<z<<" "<<ans<<"\n";
	for(int i=1;i=n;i++){
		for(int j=i;j<=n;j++)
		dfs(k+1,c-1,a[j]&a[i]);
	}
	dfs(k,c,z);
	return;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(1,m,0);
	cout<<ans;
	return 0;
}
