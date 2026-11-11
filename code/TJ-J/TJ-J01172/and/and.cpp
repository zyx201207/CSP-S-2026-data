#include<bits/stdc++.h>
using namespace std;

long long n,m,a[200001],ans,vis[200001];
void dfs(long long sum,int cnt){
	if(cnt>m){
		ans=max(ans,sum);
		return;
	}
	for(long long i=1;i<=n;i++) if(vis[i]==0){
		vis[i]=1;
		dfs(sum&a[i],cnt+1);
		vis[i]=0;
	}
	return;
} 
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	cin>>n>>m;
	for(long long i=1;i<=n;i++) cin>>a[i];
	for(long long i=1;i<=n;i++) dfs(a[i],1);
	cout<<ans;
	
	fclose(stdin);
	fclose(stdout);

	return 0;
}

