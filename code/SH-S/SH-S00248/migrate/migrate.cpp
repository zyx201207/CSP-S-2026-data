#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=20;
int c,t;
int n,d,a[N],mindis=1e9,ans;
bool vis[N];
vector<int>g[N];
void dfs(int u,int ed,int dis){
	if(u==ed){
		if(dis<mindis){
			mindis=dis;
			ans=1;
		}
		else if(dis==mindis)ans++;
		return;
	}
	for(auto v:g[u]){
		if(!vis[v]){
			vis[v]=1;
			dfs(v,ed,dis+1);
			vis[v]=0;
		}
	}
}
void solve(){
	cin>>n>>d;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)g[i].clear();
	int cnt=0;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(a[j]-a[i]<=d){
				g[i].push_back(j);
				g[j].push_back(i);
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			mindis=1e9;
			ans=0;
			memset(vis,0,sizeof vis);
			vis[i]=1;
			dfs(i,j,0);
			if(ans==2)cnt++;
		}
	}
	cout<<cnt<<endl;
}
void solve2(){
	cin>>n>>d;
	for(int i=1;i<=n;i++)cin>>a[i];
	int tmp=a[2]-a[1],cnt=0;
	while(tmp<d){
		tmp+=a[2]-a[1];
		cnt++;
	}
	int ans=n-2*cnt+1;
	if(2*cnt-2!=cnt)ans+=n-2*cnt+2;
	cout<<ans<<endl;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		if(c<=2)solve();
		else if(c==11||c==12)solve2();
	}
	return 0;
}
