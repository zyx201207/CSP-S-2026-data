#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=2e5+5;
ll n,m,ans,a[MAXN];
bool vis[MAXN];
void dfs(int dep,ll num){
	if(dep>m){
		ans=max(ans,num);
		return;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]==0){
			vis[i]=1;
			if(dep==1)dfs(2,a[i]);
			else dfs(dep+1,(num&a[i]));
			vis[i]=0;
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(1,0);
	cout<<ans;
	return 0;
}
