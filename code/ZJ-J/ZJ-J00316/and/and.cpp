#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int a[N];
int n;
int m,ans=-1;
int vis[N];
void dfs(int i,int step,int dat){
	if(step==m){
		ans=max(ans,dat);
		return;
	}
	vis[i]=1;
	for(int j=1;j<=n;j++){
		if(!vis[j]){
			dfs(j,step+1,dat&a[j]);
		}
	}
	vis[i]=0;
}
bool A(){
	for(int i=1;i<=n;i++){
		if(log2((a[i]+1)*1.0)!=int(log2((a[i]+1)*1.0)))return 0;
	}
	return 1;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<=20){
		for(int i=1;i<=n;i++)dfs(i,1,a[i]);
		cout<<ans<<'\n';
		return 0;
	}
	if(m==1){
		for(int i=1;i<=n;i++)ans=max(ans,a[i]);
		cout<<ans<<'\n';
		return 0;
	}
	if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=1;j!=i&&j<=n;j++){
				ans=max(ans,a[i]&a[j]);
			}
		}
		cout<<ans<<'\n';
		return 0;
	}
	if(n==m){
		int sum=a[1];
		for(int i=2;i<=n;i++)sum&=a[i];
		cout<<sum<<'\n';
		return 0;
	}
	if(A()){
		sort(a+1,a+1+n,greater<int>());
		int sum=a[1];
		for(int i=2;i<=m;i++)sum&=a[i];
		cout<<sum<<'\n';
		return 0;
	}
		for(int i=1;i<=n;i++)dfs(i,1,a[i]);
		cout<<ans<<'\n';
		return 0;
	return 0;
}
