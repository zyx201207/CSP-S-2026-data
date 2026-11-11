#include<bits/stdc++.h>
using namespace std;
int a[200010],n,m;
long long dfs(int i,int k,int ans){
	if(k==m)return ans;
	if(i==n+1)return 0;
	return max(dfs(i+1,k,ans),dfs(i+1,k+1,ans&a[i]));
}
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	cout<<max(dfs(1,0,-1),dfs(1,1,a[1]));
	return 0;
} 
