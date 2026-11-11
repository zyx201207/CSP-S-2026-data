#include<bits/stdc++.h>
#define N 1000009
using namespace std;
int cll,T;
int read(){
	char ch=getchar();
	int wz=0;
	while(!isdigit(ch))ch=getchar();
	while(isdigit(ch)){
		wz=wz*10+(ch-48);
		ch=getchar();
	}
	return wz;
}
int h[N],to[2*N],nxt[2*N],cnt=0;
void add(int u,int v){
	cnt++;
	to[cnt]=v,nxt[cnt]=h[u];
	h[u]=cnt;
}
int n,k;
int tot=0;
int dfn[N],siz[N],hev[N],sm[N];
int top[N],dep[N],fa[N],hei[N];
bool imp[N],cont[N];
void dfs1(int x,int p){
	siz[x]=1,hei[x]=0;
	fa[x]=p;
	int mink=-1,mx=0;
	for(int i=h[x];i;i=nxt[i]){
		if(to[i]!=p){
			cout<<"edge"<<x<<' '<<to[i]<<'\n';
			dep[to[i]]=dep[x]+1;
			dfs1(to[i],x);
			hei[x]=max(hei[x],hei[to[i]]+1);
			siz[x]+=siz[to[i]];
			if(siz[to[i]]>mx)mx=siz[to[i]],mink=to[i];
		}
	}
	hev[x]=mink;
	return;
}
void dfs2(int x,int p){
	dfn[x]=++tot;
	if(hev[x]!=-1){
		top[hev[x]]=top[x];
		dfs2(hev[x],x);
	}
	for(int i=h[x];i;i=nxt[i]){
		if(to[i]!=p&&to[i]!=hev[x]){
			top[to[i]]=to[i];
			dfs2(to[i],x);
		}
	}
	return ;
}
int lca(int x,int y){
	while(top[x]!=top[y]){
		if(dep[top[x]]>dep[top[y]]){
			x=fa[top[x]];
		}
		else {
			y=fa[top[y]];
		}
	}
	if(dep[x]>dep[y])return y;
	else return x;
}
int dis(int x,int y){
	return dep[x]+dep[y]-2*dep[lca(x,y)]+1;
}
void dfs3(int x,int p,int mt){
	sm[x]=0,imp[x]=cont[x]=0;
	if(hei[x]==mt){
		imp[x]=1,cont[x]=1;
		return;
	}
	for(int i=h[x];i;i=nxt[i]){
		if(to[i]!=p){
			dfs3(to[i],x,mt);
			sm[x]+=cont[to[i]];
			if(cont[to[i]])cont[x]=1;
		}
	}
	if(sm[x]>=2)imp[x]=1;
	return;
}
int col[N],pks[N];
void bfs(int x,int c){
	queue<int>q;
	q.push(x);
	while(!q.empty()){
		cout<<"col"<<c<<' '<<x<<'\n';
		int u=q.front();
		q.pop();
		col[x]=c,pks[c]++;
		for(int i=h[u];i;i=nxt[i]){
			if(!col[to[i]]&&!imp[to[i]]&&cont[i]){
				q.push(to[i]);
				col[to[i]]=c;
			}
		}
	}
	return;
}

void init(){
	for(int i=1;i<=n;i++){
		siz[i]=fa[i]=0;
		imp[i]=cont[i]=0;
		col[i]=pks[i]=0;
	}
}
bool chk(int x){
	cout<<"chk"<<x<<'\n';
	init();
	dfs1(1,0);
	dfs3(1,0,x);
	int mink=0,mn=0x3f3f3f3f;
	for(int i=1;i<=n;i++){
		if(imp[i]&&dep[i]<=mn){
			mink=i,mn=dep[i];
		}
	}
	int rt=mink;
	cout<<rt<<'\n';
	init();
	dep[rt]=0;
	dfs1(rt,0);
	//dfs2(rt,0);
	dfs3(rt,0,x);
	for(int i=1;i<=n;i++){
		cout<<i<<':'<<siz[i]<<' '<<dep[i]<<' '<<hei[i]<<' '<<imp[i]<<' '<<cont[i]<<' '<<sm[i]<<'\n';
	}
	int cur=0,tmp=0,ctot=0;
	for(int i=1;i<=n;i++)cur+=cont[i];
	cout<<"cur"<<cur<<'\n';
	mink=0,mn=0;
	bool fg=1;
	for(int i=1;i<=n;i++){
		if(imp[i]&&dep[i]<=mn){
			mink=i,mn=dep[i];
		}
	}
	for(int i=h[rt];i;i=nxt[i]){
		if(!cont[to[i]]&&hei[to[i]]+mn+1>x)fg=0;
	}
	for(int i=1;i<=n;i++){
		cout<<i<<' '<<cont[i]<<' '<<imp[i]<<' '<<col[i]<<'\n';
		if((i!=rt&&!imp[i]&&cont[i]&&!col[i])){
			//assert(i!=3);
			bfs(i,++ctot);
			tmp=max(tmp,min(2*k-1,pks[ctot]));
		}
	}
	if(fg&&sm[rt]<=2){
			//assert(i!=3);
			bfs(rt,++ctot);
			tmp=max(tmp,min(2*k-1,pks[ctot]));
		}
	int fnl=cur-tmp;
	cout<<"fnl"<<fnl<<'\n';
	if(fnl>k)return 0;
	else return 1;
}
void init3(){
	for(int i=1;i<=n;i++)h[i]=0;
	for(int i=1;i<=cnt;i++)to[i]=nxt[i]=0;
	cnt=0;
}
void work(){
	cin>>n>>k;
	init3();
	for(int i=1;i<n;i++){
		int u,v;
		u=read(),v=read();
		add(u,v);add(v,u);
	}
	top[1]=1,dep[1]=0;
	dfs1(1,0);
	//dfs2(1,0);
	int l=0,r=n-1,ans=n-1;
	while(l<=r){
		int mi=(l+r)>>1;
		bool ttp=chk(mi);
		if(chk(mi))ans=mi,r=mi-1;
		else l=mi+1;
		cout<<"res"<<mi<<' '<<ttp<<'\n';
	}
	cout<<"ans"<<ans<<'\n';
}
int main(){
	freopen("hub1.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>cll>>T;
	while(T--)work();
	return 0;
}
