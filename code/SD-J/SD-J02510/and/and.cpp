#include<cstdio>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<string>
#include<stack>
#include<queue>
#include<map>
using namespace std;
typedef long long ll;
ll a[200005],n,m;
ll ans;
bool vis[200005];
void dfs(ll x,ll stp,ll res){
	vis[x]=1;
	if (stp==m){
		ans=max(ans,res);
//		if (res==ans) cout<<x<<endl;
        vis[x]=0;
		return;
	}
	for(int i=1;i<=n;i++){
		if (vis[i]==0) dfs(i,stp+1,a[i]&res);
	}
	vis[x]=0;
	return;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
    for(int i=1;i<=n;i++){
    	dfs(i,1,a[i]);
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
