#include<bits/stdc++.h>
using namespace std;
int n,m;
const int N=2e5+10;
int a[N];
int ans=0;
void dfs(int u,int num,int sum){
	if(num==m){
		
		ans=max(ans,sum);
		return;
	}
	if(u==n){
		return;
	}
	
	for(int i=u+1;i<=n;i++){
		dfs(i,num+1,sum&a[i]);
	}
}
void solve1(){
	for(int i=1;i<=n-m+1;i++){
		dfs(i,1,a[i]);
	}
	cout<<ans;
}
void solve2(){
	ans=a[1];
	for(int i=2;i<=n;i++){
		ans&=a[i];
	}
	cout<<ans;
}
void solve3(){
	ans=a[1];
	for(int i=2;i<=n;i++){
		ans=max(a[i],ans);
	}
	cout<<ans;
}
void solve4(){
	ans=0;
	
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			ans=max(ans,a[i]&a[j]);
		}
	}
	cout<<ans;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(n<=20){
		solve1();
	}
	else if(m==n){
		solve2();
	}
	else if(m==1){
		solve3();
	}
	else if(m==2){
		solve4();
	}
}