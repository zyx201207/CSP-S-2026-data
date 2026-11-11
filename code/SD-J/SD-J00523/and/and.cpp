#include<bits/stdc++.h>
using namespace std;
int a[200050],b[200005][30],ans=0,m,n;
void dfs(int sum,int num,int cnt){
	if(num==m){
		ans=max(ans,sum);
		return ;
	}dfs(sum,num,cnt+1);
	dfs(sum&a[cnt],num+1,cnt+1);
	return ;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(m==n){
		for(int i=2;i<=m;i++)a[1]=a[1]&a[i];
		cout<<a[1];
		return 0;
	}if(m==1){
		for(int i=1;i<=n;i++)ans=max(ans,a[i]);
		cout<<ans;
		return 0;
	}if(n<=20){
		for(int i=1;i<=n;i++)dfs(a[i],1,i);
		cout<<ans;
		return 0;
	}
	return 0;
}
