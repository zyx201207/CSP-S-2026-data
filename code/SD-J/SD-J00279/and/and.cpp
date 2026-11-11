#include<bits/stdc++.h>
using namespace std;
int n,m,ans;
vector<int>a;
int dfs(int x,int y,int z){
	if(x==n)return 0;
	if(y==m)return z;
	int p=0;
	for(int i=x+1;i<n;i++)
		p=max(p,dfs(i,y+1,z&a[i]));
	return p;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout); 
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	a.resize(n);
	for(int i=0;i<n;i++)cin>>a[i];
	for(int i=0;i<n;i++){
		ans=max(ans,dfs(i,1,a[i]));
	}
	cout<<ans;
	return 0;
}
