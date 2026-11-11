#include <bits/stdc++.h>
using namespace std;
int OP,t;
int n,m;
vector<int> g[1000005];
int X,Y,Len;
int dep[1000005];
int dia[1000005];
int fa0[1000005];
void dfs1(int v,int fa){
	fa0[v]=fa;
	dep[v]=dep[fa]+1;
	if(dep[v]>dep[X]) X=v;
	for(auto to:g[v])if(to!=fa) dfs1(to,v);
}
int D;
int sz[1000005];
struct Tree{
	int rt;
	int fa[1000005],dep[1000005],md[1000005],smd[1000005],son[1000005];
	void dfs1(int v){
		md[v]=smd[v]=0;
		for(auto to:g[v])if(to!=fa[v]){
			fa[to]=v;
			dep[to]=dep[v]+1;
			dfs1(to);
			if(md[to]+1>md[v]){
				smd[v]=md[v];
				md[v]=md[to]+1;
				son[v]=to;
			}else smd[v]=max(smd[v],md[to]+1);
		}
	}
	int dif[1000005];
	int q[1000005],qt[1000005],head,tail;
	int ps[1000005];
	void pushq(int v,int t){
		// cerr<<"    pushq "<<v<<" "<<t<<"\n";
		while(head<=tail&&qt[tail]>=t) --tail;
		++tail;
		q[tail]=v;qt[tail]=t;
	}
	void dfs2(int v){
		while(head+1<=tail&&qt[head+1]<=dep[v]) ++head;
		int cur=0;
		if(smd[v]>=D) cur=v;
		else if(md[v]<D) cur=0;
		else{
			if(head<=tail&&qt[head]<=dep[v]) cur=q[head];
		}
		// cerr<<"  "<<v<<"->"<<cur<<"\n";
		++dif[cur];
		int dv=dep[v]+max(1,D-md[v]);
		if(son[fa[v]]==v) ps[v]=ps[fa[v]];
		else ps[v]=tail+1;
		while(ps[v]<=tail&&qt[ps[v]]<dv) ++ps[v];
		for(auto to:g[v])if(to!=fa[v]&&to!=son[v]){
			int rhead=head,rtail=tail;
			vector<pair<int,int> > vc;
			for(int i=0;i<=min(md[to]+1,tail-ps[v]);++i) vc.push_back(make_pair(q[i+ps[v]],qt[i+ps[v]]));
			tail=ps[v];
			q[ps[v]]=v;qt[ps[v]]=dv;
			dfs2(to);
			head=rhead;tail=rtail;
			for(int i=0;i<=min(md[to]+1,tail-ps[v]);++i) tie(q[i+ps[v]],qt[i+ps[v]])=vc[i];
		}
		pushq(v,dep[v]+max(1,D-smd[v]));
		if(son[v]) dfs2(son[v]);
	}
	void dfs3(int v){
		for(auto to:g[v])if(to!=fa[v]){
			dfs3(to);
			dif[v]+=dif[to];
		}
	}
	void init(){
		dfs1(rt);
	}
	void solve(){
		// cerr<<"solve "<<rt<<":\n";
		head=1;tail=0;
		for(int i=1;i<=n;++i) dif[i]=0;
		dfs2(rt);
		dfs3(rt);
	}
	// void dfs4(int v){
	// 	for(auto to:g[v])if(to!=fa[v]){
	// 		cerr<<"---- "<<v<<" "<<to<<"\n";
	// 		dfs4(to);
	// 	}
	// }
	bool solve2(){
		// dfs4(57);
		for(int A=1;A<=n;++A)if(A!=rt&&son[fa[A]]!=A&&son[A]){
			vector<int> vc;
			for(int v=A;v;v=son[v]) vc.push_back(v);
			head=1;tail=0;
			// cerr<<"Chain "<<A<<"\n";
			// for(auto x:vc) cerr<<x<<" ";cerr<<"\n";
			for(int i=(int)vc.size()-1,j=i-1;i;--i){
				while(head<=tail&&q[head]==i) ++head;
				while(j>=0&&(head>tail||dep[vc[j]]>qt[head])){
					// cerr<<"? j="<<vc[j]<<" dep="<<dep[vc[j]]<<"\n";
					--j;
					if(j==-1){
						break;
					}
					int curt=dep[vc[j]]-max(0,D-smd[vc[j]]);
					while(head<=tail&&qt[tail]<=curt) --tail;
					++tail;
					q[tail]=j;
					qt[tail]=curt;
					// cerr<<"push "<<curt<<"\n";
				}
				int add=-sz[vc[j+1]];
				// cerr<<"subtree "<<vc[i]<<": start="<<vc[j+1]<<"\n";
				// cerr<<"subtree "<<vc[i]<<": -"<<-add<<"+"<<max(1,dif[vc[i]])<<"\n";
				add+=max(1,dif[vc[i]]);
				if(add+sz[X]<=m) return 1;
			}
			if(sz[X]-sz[A]+max(1,dif[A])<=m) return 1;
		}
		return 0;
	}
	void clear(){
		for(int i=0;i<=n+1;++i) fa[i]=dep[i]=md[i]=smd[i]=son[i]=0;
	}
}tree1,tree2;
void dfs2(int v,int fa){
	for(auto to:g[v])if(to!=fa){
		dfs2(to,v);
		sz[v]+=sz[to];
	}
}
bool check(int DD){
	D=DD;
	// cerr<<"check D="<<D<<"\n";
	tree1.solve();
	tree2.solve();
	for(int i=0;i<Len;++i){
		int u=dia[i],v=dia[i+1];
		int x=max(1,tree2.dif[u]),y=max(1,tree1.dif[v]);
		// cerr<<"? "<<u<<" "<<v<<" "<<x<<" "<<y<<"\n";
		if(x+y<=m) return 1;
	}
	for(int i=1;i<=n;++i){
		if(tree1.md[i]>=D&&tree2.md[i]>=D) sz[i]=1;
		else sz[i]=0;
	}
	dfs2(X,0);
	// cerr<<"sz="<<sz[X]<<"\n";
	bool res=tree1.solve2();
	// cerr<<"return "<<res<<"\n";
	return res;
}
void clear(){
	tree1.clear();tree2.clear();
	for(int i=0;i<=n+1;++i) dep[i]=dia[i]=fa0[i]=sz[i]=0,g[i].clear();
	X=Y=Len=0;
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	scanf("%d%d",&OP,&t);
	while(t--){
		scanf("%d%d",&n,&m);
		for(int i=1,x,y;i<n;++i){
			scanf("%d%d",&x,&y);
			g[x].push_back(y);
			g[y].push_back(x);
		}
		if(m==n){
			printf("0\n");
			clear();
			continue;
		}
		dfs1(1,0);
		Y=X;X=0;
		dfs1(Y,0);
		Len=dep[X]-1;
		swap(X,Y);
		for(int i=Len,v=Y;v;v=fa0[v],--i) dia[i]=v;
		tree1.rt=X;tree2.rt=Y;
		tree1.init();tree2.init();
		int l=1,r=Len/2;
		while(l<r){
			int mid=(l+r)>>1;
			if(check(mid)) r=mid;
			else l=mid+1;
		}
		printf("%d\n",l);
		clear();
	}
	return 0;
}