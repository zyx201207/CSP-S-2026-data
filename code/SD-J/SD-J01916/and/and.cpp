#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[200010];
long long ans=-1;
bool vis[200010];
void dfs(long long cnt,int num){
	if(cnt<=ans)return ;
	if(num==m){
		ans=max(ans,cnt);
		return ;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]==1)continue;
		vis[i]=1;
		dfs(cnt&a[i],num+1);
		vis[i]=0;
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		memset(vis,false,sizeof vis);
		vis[i]=1;
		dfs(a[i],1);
	}
	cout<<ans;
	return 0;
} 
