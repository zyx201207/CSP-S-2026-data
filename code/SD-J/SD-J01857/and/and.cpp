#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
long long n,m,a[N],dp[N],ans=-1e9,vis[N];
void dfs(long long c,long long cnt,long long l){
	if(c==0){
		ans=max(ans,cnt);
		return ;
	}
	for(int i=1;i<=n;i++){
		if(i+c-1>n){
			break;
		}
		if(vis[i]==0){
			vis[i]=1;
			dfs(c-1,cnt&a[i],i);
			vis[i]=0;
		}
	}
	return ;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(m,-1,1);
	cout<<ans;
	return 0;
}

