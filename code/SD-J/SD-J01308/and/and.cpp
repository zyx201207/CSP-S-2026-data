#include<bits/stdc++.h>
using namespace std;
long long a[200005];
long long ans=-1;
int n,m;
void dfs(int idx,int yx,long long sum){
	if(yx==m){
		ans=max(ans,sum);
		return ;
	}else if(idx>n){
		return ;
	}
	if(sum==0){
		dfs(idx+1,yx+1,a[idx]);
	}else{
		dfs(idx+1,yx+1,sum&a[idx]);
	}
	dfs(idx+1,yx,sum);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==m){
		ans=a[1]&a[2];
		for(int i=3;i<=n;i++){
			ans=ans&a[i];
		}
		cout<<ans;
		return 0;
	}
	if(m==1){
		ans=-1;
		for(int i=1;i<=n;i++){
			ans=max(ans,a[i]); 
		}
		cout<<ans;
		return 0;
	}
	dfs(1,0,0);
	cout<<ans;
	return 0;
}
