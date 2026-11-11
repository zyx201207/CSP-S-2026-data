#include<bits/stdc++.h>

using namespace std;

ifstream fin("hub.in");
ofstream fout("hub.out");
#define cin fin
#define cout fout
#define endl '\n'

const int N=1e6+9;
const int inf=1e9;

int fi[N],ne[N<<1],to[N<<1],adj=1;
inline void AddEdge(int x,int y){
	ne[++adj]=fi[x];
	fi[x]=adj;
	to[adj]=y;
}

int f[N],fa[N],p[N],h[N],res[N<<1],n,k,t;
inline void DFS(int x,int o){
	f[x]=1;
	p[x]=x;
	h[x]=0;
	vector<int> v;
	for(int i=fi[x];i;i=ne[i]){
		int y=to[i];
		if(y==fa[x]) continue ;
		fa[y]=x;
		DFS(y,i);
		v.push_back(y);
		if(h[y]>=t) f[x]+=f[y];
		h[x]=max(h[x],h[y]+1);
	}
	if(h[x]<=t) res[o]=1;
	else{
		int mx=-1;
		sort(v.begin(),v.end(),[](int a,int b){return h[a]>h[b];});
		for(int i=1;i<v.size();i++) mx=max(mx,h[v[i]]);

		p[x]=p[v[0]];
		while(p[x]!=x&&h[x]-h[p[x]]+mx+1>t) p[x]=fa[p[x]];
		res[o]=f[p[x]];
	}
}

inline void Solve(){
	cin>>n>>k;
	for(int i=1,u,v;i<n;i++){
		cin>>u>>v;
		AddEdge(u,v);
		AddEdge(v,u);
	}

	int l=-1,r=n+1;
	while(l+1<r){
		t=l+r>>1;
		
		int ans=inf;
		for(int i=1;i<=n;i++){
			fa[i]=0;
			DFS(i,1);
			ans=min(ans,res[1]);
		}
		for(int i=2;i<=adj;i+=2) ans=min(ans,res[i]+res[i^1]);

		if(ans<=k) r=t;
		else l=t;
	}

	cout<<r<<endl;

	adj=1;
	for(int i=1;i<=n;i++) fi[i]=0;
}

signed main(){
	int c,T;
	cin>>c>>T;
	while(T--) Solve();

	return 0;
}