#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200050];
int lans=-1;
int us[25];
void dfs(int step,int r){
	if(r==0){
		int ans=us[1];
		for(int i=2;i<=m;i++){
			ans&=us[i];
		}
		lans=max(ans,lans);
		return;	
	}
	if(step==n){
		return;
	}
	dfs(step+1,r);
	us[r]=a[step+1];
	dfs(step+1,r-1);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==m){
		int ans;
		ans=a[1];
		for(int i=2;i<=n;i++){
			ans&=a[i];
		}
		cout<<ans;
	}
	else if(m==1){
		int ans=-1;
		for(int i=1;i<=n;i++){
			ans=max(ans,a[i]);
		}
		cout<<ans;
	}
	else if(n<=20){
		dfs(0,m);
		cout<<lans;
	}
	else if(m==2){
		int ans=-1;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				ans=max(ans,a[i]&a[j]);
			}
		}
		cout<<ans;
	}
	else{
		sort(a+1,a+1+n);
		cout<<a[n-m+1];
	}
	return 0;
}