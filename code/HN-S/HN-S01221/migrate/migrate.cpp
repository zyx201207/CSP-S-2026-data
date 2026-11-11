#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6+10;
int n,x[N],d,to[N],tp[N];
int c,T;
vector<int> t[N];
int f[N],g[N],ans;
bool vis[N];

int calc(int l,int r){
	int ur=upper_bound(x+1,x+1+n,r)-x-1;
	int ul=lower_bound(x+1,x+1+n,l)-x;
	return max(0ll,ur-ul+1);
}

void dfs(int u){
	vis[u]=1;
	int cnt0=0,cnt1=0;
	for(int v:t[u]){
		dfs(v);
		cnt0+=f[v];
		cnt1+=g[v];
	}
	if(u>=3){
		ans+=cnt0*calc(max(x[u]+1,x[u-2]+d+1),d+x[u-1]);
		ans+=cnt1*calc(max(x[u-1]+d+1,x[u]+1),d+x[u]);
	}else if(u==2){
		ans+=cnt0*calc(x[u]+1,d+x[u-1]);
		ans+=cnt1*calc(max(x[u-1]+d+1,x[u]+1),d+x[u]);
	}else if(u==1)ans+=cnt1*calc(x[u]+1,d+x[u]);
//	cout<<u<<' '<<ans<<' '<<cnt0<<' '<<cnt1<<endl;
	if(tp[u]==0)f[u]=cnt0+1,g[u]=cnt1;
	if(tp[u]==1)f[u]=0,g[u]=cnt0;
	if(tp[u]==2)f[u]=0,g[u]=0;
}

signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--){
		cin>>n>>d;
		ans=0;
		for(int i=1;i<=n;i++)t[i].clear();
		for(int i=1;i<=n;i++)to[i]=tp[i]=f[i]=g[i]=vis[i]=0;
		for(int i=1;i<=n;i++)cin>>x[i];
		for(int i=1;i<=n-1;i++){
			to[i]=upper_bound(x+1,x+1+n,x[i]+d)-x-1;
			if(to[i]!=i)t[to[i]].push_back(i);
		}
		for(int i=1;i<=n-1;i++){
			if(i-2>=1&&x[to[i]]-x[i-2]<=d)tp[i]=2;
			else if(i-1>=1&&x[to[i]]-x[i-1]<=d)tp[i]=1;
		}
		//for(int i=1;i<=n;i++)cout<<tp[i]<<' '; 
		for(int i=n;i>=1;i--){
			if(vis[i])continue;
			dfs(i);
		}
		cout<<ans<<'\n';
	}
	return 0;
}
