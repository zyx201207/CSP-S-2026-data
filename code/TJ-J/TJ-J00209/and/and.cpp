#include<iostream>
#include<stdio.h>
using namespace std;
#define int long long
const int N=2e5+5;
int a[N];
int n,m;
int ans;
void dfs(int num,int cnt,int idx){//cnt表示当前按位与结果，num选数数量 
	if(num==m){
		ans=max(ans,cnt);
		return;
	}
	for(int i=idx+1;i<=n;i++){
		dfs(num+1,(cnt&a[i]),i);
	}
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	dfs(0,1024*1024*1024-1,0);
	cout<<ans;
	return 0;
}
