#include<bits/stdc++.h>
using namespace std;
int n,m;
long long ans=INT_MIN;
int a[200010],vis[200010];
void dfs(int nums,long long cnt,int f){
	if(nums==m+1){
		ans=max(cnt,ans);
		return ;
	}
	for(int i=f+1;i<=(n-(m-nums));i++){
		if(vis[i]==0){
			vis[i]=1;
			if(nums==1){
				cnt=a[i];
			}
			dfs(nums+1,cnt&a[i],i);
			vis[i]=0;
		}
	}
	return ;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(1,0,0);
	cout<<ans;
	return 0;
}
