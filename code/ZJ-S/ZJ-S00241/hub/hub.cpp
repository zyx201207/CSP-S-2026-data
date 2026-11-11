#include<bits/stdc++.h>
using namespace std;
const int N=15;

struct edge{
	int v,nxt;
}e[N<<3];
int head[N],esize;
void put(int u,int v){
	e[++esize]={v,head[u]};
	head[u]=esize;
}

int n,K;

bool vis[N];
void dfs(int x,int s){
	if(vis[x])return ;
	vis[x]=true;
	for(int i=head[x],v;i;i=e[i].nxt){
		v=e[i].v;
		if(vis[v]||!(s&(1<<(v-1))))continue;
		dfs(v,s);
	}
}
int getw(int x){
	int rt=0;
	while(x)rt+=x&1,x>>=1;
	return rt;
}
int len[N][N];

void solve(){
	memset(len,0x3f,sizeof len);
	cin>>n>>K;
	for(int i=1;i<=n;i++)head[i]=0;
	esize=0;
	for(int i=1,u,v;i<n;i++){
		cin>>u>>v;
		put(u,v);put(v,u);
		len[u][v]=len[v][u]=1;
	}
	for(int i=1;i<=n;i++)len[i][i]=0;
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				len[i][j]=min(len[i][j],len[i][k]+len[k][j]);
			}
		}
	}
	int rt=2e9;
	for(int i=0;i<(1<<n);i++){
		int ans=0;
		if(getw(i)!=K)continue;
		memset(vis,0,sizeof vis);
		int cnt=0;
		for(int j=0;j<n;j++){
			if(!(i&(1<<j)))continue;
			if(!vis[j+1]){
				cnt++;
				dfs(j+1,i);
			}
		}
		
		if(cnt>2)continue;
		for(int j=1;j<=n;j++){
			if(!(i&(1<<(j-1)))){
				int g=2e9;
				for(int k=1;k<=n;k++){
					if((i&(1<<(k-1)))){
						g=min(g,len[j][k]);
//						if(len[j][k]==1&&n==10)cout<<j<<','<<k<<'\n';
					}
				}
				ans=max(g,ans);
			}	
		}
		rt=min(rt,ans);
	}
	cout<<rt<<'\n';
}

signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;cin>>c>>t;
	while(t--){
		solve();
	}
	return 0;
}
