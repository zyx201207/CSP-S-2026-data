#include<bits/stdc++.h>
using namespace std;
const int N=1e6+9,M=2e6+9;
int h[N],e[M],ne[M],idx=1;
void add(int a,int b){
	e[idx]=b;
	ne[idx]=h[a];
	h[a]=idx++;
}
int n,k;
int ans[N];
int st[N],f[N];
void dfs2(int u,int p){
	st[u]=1;
	for(int i=h[u];i;i=ne[i]){
		int j=e[i];
		if(j==p) continue;
		if(!f[j]) continue;
		dfs2(j,u);
	}
}
int get(){
	memset(st,0,sizeof st);
	int cnt=0;
	for(int i=1;i<=n;i++){
		if(f[i]&&!st[i]){
			dfs2(i,0);
			cnt++;
		}
	}
	return cnt;
}
struct obj{
	int u,s;
}; 
int bfs(int u){
	queue<obj> q;
	q.push({u,0});
	while(q.size()){
		obj t=q.front();
		q.pop();
		for(int i=h[t.u];i;i=ne[i]){
			int j=e[i];
			int ns=t.s+1;
			if(f[j]) return ns;
			q.push({j,ns});
		}
	}
}
int mi=0x3f3f3f3f;
void dfs1(int ceng,int x){
	if(ceng>k){
		memset(f,0,sizeof f);
		for(int i=1;i<=k;i++) f[ans[i]]=1;
		if(get()>2) return;
		int ma=0;
		for(int i=1;i<=n;i++){
			if(!f[i]){
				ma=max(ma,bfs(i));
			}
		}
		mi=min(mi,ma);
		return;
	}
	for(int i=x;i<=n;i++){
		ans[ceng]=i;
		dfs1(ceng+1,i+1);
	}
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int c,T;
	cin>>c>>T;
	while(T--){
		mi=0x3f3f3f3f;
		memset(h,0,sizeof h);
		idx=1;
		cin>>n>>k;
		for(int i=1;i<=n-1;i++){
			int u,v;
			cin>>u>>v;
			add(u,v);
			add(v,u);
		}
		dfs1(1,1);
		cout<<mi<<endl;
	}
	return 0;
}
