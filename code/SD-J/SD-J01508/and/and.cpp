#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[20005];
int maxn,mnn,mn;//mnn:m=n-1,mn:m=n
int maxv=0;
void dfs(int i,bool f,int ans,int mm){
	if(ans==m){
		maxv=max(maxv,mm);
		return ;
	}
	if(f){
		if(ans==0)mm=a[i];
		else mm=mm&a[i];
		ans++;
		dfs(i+1,1,ans,mm);
		dfs(i+1,0,ans,mm);
	}else{
		dfs(i+1,1,ans,mm);
		dfs(i+1,0,ans,mm);
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxn=max(maxn,a[i]);
	}
	if(m==1){
		cout<<maxn;
		return 0;
	}
	if(m==n){
		mn=a[1];
		for(int i=2;i<=n;i++){
			mn=mn&a[i];
		}
		cout<<mn;
		return 0;
	}
	if(m==2){	
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				maxv=max(maxv,a[i]&a[j]);
			}
		} 
		cout<<maxv;
		return 0;
	}
	dfs(1,1,0,0);
	dfs(1,0,0,0);
	cout<<maxv;
	return 0;
} 
