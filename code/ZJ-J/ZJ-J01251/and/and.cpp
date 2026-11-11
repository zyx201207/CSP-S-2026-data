#include<bits/stdc++.h>
using namespace std;
const int N=2*1e5+5;
int n,m,a[N],ans;
void dfs(int x,int y,int z){
	if(x>m){
		ans=max(ans,y);
		return;
	}
	if(z>n) return;
	for(int i=z;i<=n-m+x;i++) dfs(x+1,y&a[i],i+1);
	return;
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n-m+1;i++) dfs(i+1,a[i],i+1);
	cout<<ans;
	return 0;
} 
