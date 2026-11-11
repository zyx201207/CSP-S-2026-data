#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int ans;
int a[200010];
void dfs(int x,int st,int cnt){
	if(st==m){
		ans=max(ans,cnt);
		return;
	}
	if(x>n)return;
	if(cnt<ans)return;
	dfs(x+1,st,cnt);
	dfs(x+1,st+1,cnt&a[x]);
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(n<=2000){
		dfs(1,0,2147483647);
		cout<<ans;
	}
	else{
		int mx=-1;
		for(int i=1;i<=n;i++)mx=max(mx,a[i]);
		cout<<mx;
	}
	return 0;
}
