#include<bits/stdc++.h>
using namespace std;
#define int long long
inline int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch>'9'||ch<'0'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar(); 
	}
	return x*f;
}
const int maxn=10010;
int fa[maxn];
bool vvis[maxn],viss[maxn];
int ffa[maxn],dep[maxn];
int find(int x){
	return x==fa[x]?x:fa[x]=find(fa[x]);
}
void merge(int x,int y){
	int u=find(x),v=find(y);
	if(u==v)return; 
	fa[u]=v;
}
map<pair<int,int>,bool> vis;
vector<int> ed[maxn];
void dfs(int x,int f){
	ffa[x]=f;
	dep[x]=dep[f]+1;
	for(auto v:ed[x]){
		if(v==f)continue;
//	cerr<<x<<endl;
		dfs(v,x);
	}
	return;
}
int get(int u,int v){
	int cnt=0;
	if(dep[u]>dep[v]){
		swap(u,v);
	}
	while(dep[v]>dep[u]){
		v=ffa[v];
		cnt++;
	}
	while(u!=v){
		u=ffa[u];v=ffa[v];
		cnt+=2;
	}
	return cnt;
}
void solve(){
	int n,k;
	n=read();k=read();
	for(int i=1;i<=n;i++){
		ed[i].clear();
	}
	for(int i=1;i<n;i++){
		int u,v;
		u=read();v=read();
//		cout<<u<<' '<<v<<endl;
		ed[u].push_back(v);
		ed[v].push_back(u);
		vis[{u,v}]=vis[{v,u}]=1;
	}
	ffa[1]=0;
	dep[0]=0;
	dfs(1,0);
	int aans=10000010000;
	for(int i=1;i<(1<<n);i++){
		for(int j=1;j<=n;j++){
			vvis[j]=0;
			viss[j]=0;fa[j]=j;
		}
		vector<int> s;
		for(int j=1;j<=n;j++){
			if(i&(1<<j-1)){
				s.push_back(j);
				vvis[j]=1;
			}
		} 
		if(s.size()!=k)continue;
		for(auto v:s){
			for(auto u:s){
				if(vis[{u,v}])merge(u,v);
			}
		}
		int cnt=0;
		for(auto u:s){
			if(!viss[find(u)]){
				cnt++;
				viss[find(u)]=1;
			}
		}
		if(cnt>2)continue;
		int ans=0;
		for(int j=1;j<=n;j++){
			int minn=100000000000;
			if(vvis[j]){
				continue;
			}else{
				for(auto k:s){
//					if(get(j,k)<minn){
//						cout<<get(j,k)<<' '<<j<<' '<<k<<endl;
//					}
					minn=min(minn,get(j,k));
				}
			}
			ans=max(ans,minn);
		}
		aans=min(ans,aans);
	}
	cout<<aans<<'\n';
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c=read(),t=read();
	while(t--){
		solve();
	}
	return 0;
}
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
