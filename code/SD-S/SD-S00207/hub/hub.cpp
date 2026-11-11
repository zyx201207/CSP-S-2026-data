#include<bits/stdc++.h>
#define ll long long
using namespace std;
/*====================*/
const int N = 1e6+10;
const int MOD =998244353;
const int INF = 0x3F3F3F3F;
/*====================*/
int siz[N],son[N],tp[N],dep[N],fa[N];
int n,k,ans;
vector<int>g[N];
vector<int>ch;
void DFS(int u,int f){
	siz[u]=1,son[u]=0,fa[u]=f,dep[u]=dep[f]+1;
	for(int v:g[u]){
		if(v==f)continue;
		DFS(v,u);
		siz[u]+=siz[v];
		if(siz[son[u]]<siz[v])son[u]=v;
	}
}
void De(int u,int t){
	tp[u]=t;
	for(int v:g[u]){
		if(v==fa[u])continue;
		if(v==son[u])De(v,t);
		else De(v,v);
	}
}
int LCA(int u,int v){
	while(tp[u]!=tp[v]){
		if(dep[u]<dep[v])swap(u,v);
		u=fa[tp[u]];
	}
	return dep[u]<dep[v]?u:v;
}
int Dist(int u,int v){
	return dep[u]+dep[v]-2*dep[LCA(u,v)];
}
int dvis[N],vis[N];
void Dfs(int u){
	for(int v:g[u]){
		if(!dvis[v]&&vis[v]){
			dvis[v]=1;
			Dfs(v);
		}
	}
}
int dr[N];
void Check(int lst){
	if(ch.size()==k){
		memset(dvis,0,sizeof(dvis));
		memset(vis,0,sizeof(vis));
		memset(dr,INF,sizeof(dr));
		int cnt=0;
		for(int i:ch)vis[i]=1;
		for(int i:ch){
			if(!dvis[i]){
				++cnt;
				if(cnt>2)return;
				dvis[i]=1;
				Dfs(i);
			}
		}int res=0;
//		cout<<'\n';
//		for(int i:ch)cout<<i<<' ';
//		cout<<'\n';
		for(int i=1;i<=n;i++){
			for(int j:ch){
				dr[i]=min(dr[i],Dist(i,j));
			}res=max(res,dr[i]);
			//cout<<dr[i]<<' ';
		}ans=min(ans,res);
		//cout<<'\n';
		return;
	}
	for(int i=lst+1;i<=n;i++){
		ch.push_back(i);
		Check(i);
		ch.pop_back();
	}
}
void Init(){
	ch.clear();
	for(int i=1;i<=n;i++)g[i].clear();
	memset(siz,0,sizeof siz);
	memset(son,0,sizeof son);
	memset(dep,0,sizeof dep);
	memset(fa,0,sizeof fa);
	memset(tp,0,sizeof tp);
	memset(dr,0,sizeof dr);
	memset(dvis,0,sizeof dvis);
	memset(vis,0,sizeof vis);
}
/*====================*/
void Solve(void){
	cin>>n>>k;ans=INF;
	for(int i=1;i<n;i++){
		int u,v;cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}DFS(1,0);De(1,1);
	Check(0);
	cout<<ans<<'\n';
	Init();
}
/*====================*/
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int c,T=1;cin>>c>>T;
	while(T--)Solve();
	return 0;
}
//哦不不不我要AFO了，拿不了S1=多少得上个迷惑行为吧 
//赞美伟大的Protect_EMmm 
/*
0 2
5 2
1 2
2 3
3 4
4 5
10 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10
*/
