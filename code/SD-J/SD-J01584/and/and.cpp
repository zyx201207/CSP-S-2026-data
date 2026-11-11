#include<bits/stdc++.h>
typedef long long ll;
const int maxn = 2e5+7;
const int maxx = 1e7+4;
using namespace std;
int n,m;
ll a[maxn],ans;
bool f[maxx],vis[maxn];
void dfs(int x,ll cnt){
	if(x>=m){
		ans=max(ans,cnt);
		return ;
	}
	if(cnt<maxx){
		if(f[cnt]) return ;
		else f[cnt]=1;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			dfs(x+1,(cnt&a[i]));
			vis[i]=0;
		}
	}
	return ;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		vis[i]=1;
		dfs(1,a[i]);
		vis[i]=0;
	}
	cout<<ans<<'\n';
	return 0;
} 
/*
4 2
3 15 12 12
*/
