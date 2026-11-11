#include <bits/stdc++.h>
using namespace std;
int c,T,n,k;
vector<int> ee[500005];
int banu,banv;//被拆掉的边
bool B(int u,int v){
	return (banu==u&&banv==v||banu==v&&banv==u);
}
/*
找直径->找中点->测dep->环状更新 
*/ 
int dep[500005];
int ft[500005];
//dfs1:测dep 
int maxdep=0;
void dfs1(int u,int fa){
	ft[u]=fa;
	dep[u]=dep[fa]+1;
	if(dep[u]>dep[maxdep]) maxdep=u;
	for(int v:ee[u]){
		if(v==fa||B(u,v)) continue;
		dfs1(v,u);
	}
}
int st[500005]; int cnt=0;
//dfs2:测直径中点 
bool dfs2(int u,int fa,int tt){
	st[++cnt]=u;
	if(tt==u) return true;
	for(int v:ee[u]){
		if(v==fa||B(u,v)) continue;
		if(dfs2(v,u,tt)) return true;
	}
	cnt--;
	return false;
}
int fardep[500005];//子树内距离子树根节点的最远距离 
void dfs3(int u,int fa){
	fardep[u]=0;
	for(int v:ee[u]){
		if(v==fa||B(u,v)) continue;
		dfs3(v,u);
		fardep[u]=max(fardep[u],fardep[v]+1);
	}
}
int getroot(int q){
	dep[0]=-1;
	maxdep=0;
	dfs1(q,0);
	int u=maxdep;
	maxdep=0;
	dfs1(u,0);
	int v=maxdep;
	cnt=0;
	dfs2(u,0,v);
	dfs1(st[(cnt+1)/2],0);
	return st[(cnt+1)/2];
}
priority_queue<pair<int,int> > q;
bool inq[500005];
//first:fardep second:点 
int cal(int ru,int rv){
	dfs3(ru,0);
	dfs3(rv,0);
//	cout<<"now:"<<ru<<","<<rv<<"\n";
//	for(int i=1;i<=n;i++) cout<<fardep[i]<<" "; cout<<"\n";
	memset(inq,false,sizeof(inq));
	inq[ru]=inq[rv]=true;
	for(int v:ee[ru]){
		if(B(ru,v)) continue;
		inq[v]=true;
		q.push(make_pair(fardep[v],v));
	} 
	for(int v:ee[rv]){
		if(B(rv,v)) continue;
		inq[v]=true;
		q.push(make_pair(fardep[v],v));
	} 
	int cnt=2;
	for(int d=n;d>=0;d--){
//		if(!q.empty()) cout<<"d="<<d<<":"<<q.top().first<<"\n";
		while(!q.empty()&&q.top().first>=d){
			int u=q.top().second;
			q.pop();
			cnt++;
			for(int v:ee[u]){
				if(B(u,v)||inq[v]) continue;
				inq[v]=true;
				q.push(make_pair(fardep[v],v));
			}
		}
//		cout<<d<<":"<<cnt<<"\n";
		if(cnt>k){
			while(!q.empty()) q.pop();
			return d+1; 
		}
	}
	while(!q.empty()) q.pop();
	return 0;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin>>c>>T;
	while(T--){
		cin>>n>>k;
		for(int i=1;i<=n;i++) ee[i].clear();
		for(int i=1;i<=n-1;i++){
			int u,v;
			cin>>u>>v;
			ee[u].push_back(v);
			ee[v].push_back(u);
		} 
		dep[0]=-1;
		int ans=n;
		for(int u=1;u<=n;u++){
			for(int v:ee[u]){
				if(u>v) continue;
//				cout<<"ban:"<<u<<"~"<<v<<"\n"; 
				banu=u,banv=v;
				int ru=getroot(u);
				int rv=getroot(v);
				ans=min(ans,cal(ru,rv));
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
