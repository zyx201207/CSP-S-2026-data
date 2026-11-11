#include<bits/stdc++.h>
using namespace std;
int n,m;
bool vis[200010];
long long a[200010];
long long ans=-1;
void check(){
	long long cnt=0;
	for(int i=1;i<=n;i++){
		if(vis[i]==1){
			cnt=a[i];
			break;
		}	
	}
	for(int i=1;i<=n;i++){
		if(vis[i]==1){
//			cout<<cnt<<"  ";
			cnt=(cnt & a[i]);
		}
	}
//	cout<<cnt<<"----";
	ans=max(ans,cnt);
	return ;
}
void dfs(int x,int t){
	if(t==m+1){
		check();
		return ;
	}
	if(x==n+1){
		return ;
	}
	vis[x]=1;
	dfs(x+1,t+1);
	vis[x]=0;
	dfs(x+1,t);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)	cin>>a[i];
	dfs(1,1);
	cout<<ans;
	return 0;
}

