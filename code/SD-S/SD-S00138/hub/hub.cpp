#include <bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int fst[N],nxt[N*2],to[N*2],cnt;
int dep[N];
bool vis[N];
bool us[N];
void add_edge(int u,int v){
	cnt++;
	nxt[cnt]=fst[u];
	fst[u]=cnt;
	to[cnt]=v;
	return;
}
int st[N][21];
void dfs(int u,int last,int cur){
	st[u][0]=last,dep[u]=cur;
	int tmp=20;
	while(tmp!=0&&(1<<tmp)>dep[u])tmp--;
	for(int i=1;i<=tmp;i++){
		st[u][i]=st[st[u][i-1]][i-1];
	}
	for(int i=fst[u];i;i=nxt[i]){
		int v=to[i];
		if(v==last)continue;
		dfs(v,u,cur+1);
	}
	return;
}
int lcm(int u,int v){
	if(dep[u]<dep[v])swap(u,v);
	int tmp=20;
	int res=0;
	while(st[u][tmp]==0) tmp--;
	while(dep[u]!=dep[v]){
		while(dep[u]-(1<<tmp)<dep[v])tmp--;
		u=st[u][tmp],res+=(1<<tmp);
	}
	tmp=20;
	while(u!=v){
//		cout<<u<<' '<<v<<'\n';
		while(tmp!=0&&(st[u][tmp]==st[v][tmp]||st[u][tmp]==0||st[v][tmp]==0))tmp--;
		u=st[u][tmp],v=st[v][tmp];
		res+=(1<<tmp)*2;
	}
	return res;
}
void find(int u,int last){
	for(int i=fst[u];i;i=nxt[i])
	{
		int v=to[i];
		if(v==last)continue;
		if(vis[v]==0)continue;
		if(us[v]==1)continue;
		us[v]=1;
		find(v,u);
	}
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,T;
	cin>>c>>T;
	while(T--){
		memset(fst,0,sizeof(fst));
		memset(nxt,0,sizeof(nxt));
		memset(to,0,sizeof(to));
		memset(st,0,sizeof(st));
		cnt=0;
		int n,k;
		cin>>n>>k;
		
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			add_edge(u,v);
			add_edge(v,u);
		}
		dfs(1,1,1);
		int fin=2e9;
		for(int i=0;i<(1<<n);i++){
			int cnt=0;
			for(int j=0;j<n;j++){
				us[j+1]=0;
				if(i&(1<<j)) cnt++,vis[j+1]=1;
				else vis[j+1]=0;
			}
//			cout<<i<<" "<<cnt<<'\n';
			if(cnt!=k)continue;
			int ans=0;
			for(int j=1;j<=n;j++){
				if(us[j]==0&&vis[j]==1){
					us[j]=1;
					find(j,0);
					ans++;
				} 
			}
			if(ans>2)continue;
			int tmp=0;
			for(int j=1;j<=n;j++){
				int ttmp=2e9;
				if(vis[j])continue;
				for(int k=1;k<=n;k++){
					if(k==j)continue;
					if(vis[k]==1) ttmp=min(ttmp,lcm(j,k));
				}
				tmp=max(tmp,ttmp);
			}
			fin=min(fin,tmp);
		}
		cout<<fin<<'\n';
	}

	return 0;
}


