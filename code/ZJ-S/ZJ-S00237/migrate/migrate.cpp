#include<bits/stdc++.h>
using namespace std;
#define int long long
#define FIO ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
const int N=2e6+100;
int c,t;
int n,d;
int a[N],dis[N],vis[N];
void dfs(int x,int cnt){
	if(cnt<dis[x]) dis[x]=cnt,vis[x]=0;
	if(cnt==dis[x]) vis[x]++;
	if(x>=n) return ;
	for(int i=x+1;i<=n;i++) {
		if(a[i]-a[x]<=d) dfs(i,cnt+1);
		else break;
	}
}
void solve(){
	cin>>n>>d;
	for(int i=1;i<=n;i++) cin>>a[i];
	int ans=0;
	for(int i=1;i<=n;i++){
		memset(vis,0,sizeof(vis));
		memset(dis,0x3f,sizeof(dis));
		dfs(i,0);
		for(int j=i+1;j<=n;j++)
			if(vis[j]==2)
				ans++;
	}
	cout<<ans<<'\n';
}
signed main(){
	FIO
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--) solve();
	return 0;
}