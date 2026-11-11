#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,m,a[200005];
int ans=-0x3f3f3f3f;
void dfs(int x,int temp,int idx){
	if(x==0||idx==n){
		ans=max(ans,temp);
		return;
	}
	dfs(x-1,temp&a[idx],idx+1);
	dfs(x,temp,idx+1);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		dfs(m,a[i],i);
	}
	cout<<ans;
	return 0;
}
