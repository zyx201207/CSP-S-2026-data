#include <bits/stdc++.h>
using namespace std;
const int N=2e3+10;
int n,k,f[N][N],vis[N],ans;
int idx=1,e[N],ne[N],h[N],a[N];
void add(int a,int b){
	e[idx]=b;
	ne[idx]=h[a];
	h[a]=idx++;
}
void dfs(int x,int cnt){
	if(x==k){
		int mmax=0;
		for(int i=1;i<=n;i++){
			if(vis[i]) continue;
			int sum=0x3f3f3f3f;
			for(int j=1;j<=x;j++)
				sum=min(sum,f[i][a[j]]);
			mmax=max(mmax,sum);
		}
//		if(mmax<ans){
//			for(int i=1;i<=n;i++)
//				if(vis[i]) cout<<i<<' ';
//		}
		ans=min(ans,mmax);
	}
	for(int i=1;i<=n;i++){
		if(vis[i]) continue;
		bool b=0;
		for(int j=h[i];j;j=ne[j]){
			int v=e[j];
			if(vis[v]){
				b=1;
				break;
			}
		}
		if(!b&&cnt==2) continue;
		vis[i]=1;
		a[x+1]=i;
		if(b) dfs(x+1,cnt);
		else dfs(x+1,cnt+1);
		vis[i]=0;
	}
}
void solve(){
	cin>>n>>k;
	memset(f,0x3f,sizeof f);
	memset(ne,0,sizeof ne);
	memset(h,0,sizeof h);
	memset(e,0,sizeof e);
	idx=1;
	ans=0x3f3f3f3f;
	for(int i=1;i<n;i++){
		int u,v;
		cin>>u>>v;
		f[u][v]=f[v][u]=1;
		add(u,v);
		add(v,u);
	}
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++){
				if(i==j) continue;
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
			}
	dfs(0,0);
	cout<<ans<<'\n';
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int c,T;
	cin>>c>>T;
	while(T--)
		solve();
	return 0;
}