#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200010];
int nums[200010];
int ans=0;
void dfs(int u,int v){
	if(v==n){
		if(u==m){
			int sum=a[nums[1]];
			for(int i=2;i<=u;i++){
				sum=sum&a[nums[i]];
			}
			ans=max(ans,sum);
		}
		return ;
	}
	nums[u+1]=v+1;
	dfs(u+1,v+1);
	
	dfs(u,v+1);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		for(int i=1;i<=n;i++){
			ans=max(ans,a[i]);
		}
	}
	else if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				int sum=a[i]&a[j];
				ans=max(ans,sum);
			}
		}
	}
	else if(m==n){
		int ans=a[1];
		for(int i=2;i<=n;i++){
			ans&=a[i];
		}
	}
	else{
		dfs(0,0);
	}
	cout<<ans;
	return 0;
}
