#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int N=2e5+10;
int n,m;
int a[N];
int ans=-1;
int vis[N];
void dfs(int x,int cnt,int lasti){
	if(x>m){
		ans=max(cnt,ans);
		return;
	}
	for(int i=lasti+1;i<=n;i++){
		if(vis[i]==0){
			vis[i]=1;
			dfs(x+1,(cnt&a[i]),i);
			vis[i]=0;
		}
	}
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	dfs(1,INT_MAX,0);
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
