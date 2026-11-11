#include<bits/stdc++.h>
using namespace std;
int n,k;
int ans;
int a[10000001];
void dfs(int s,int p,int val){
	if(s==k){
		ans=max(ans,val);
		return ;
	}else{
		for(int i=p+1;i<n;i++){
			dfs(s+1,i,val&a[i]);
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(k==n){
		ans=a[0];
		for(int i=1;i<n;i++){
			ans&=a[i];
		}
	}
	else for(int i=0;i<=n-k;i++){
		dfs(1,i,a[i]);
	}
	cout<<ans;
	return 0;
} 
