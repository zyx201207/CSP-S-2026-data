#include<stdio.h>
#include<string.h>
#include<queue>
unsigned c,t,n,k,u,v;
unsigned fa[1<<20],depth[1<<20]={-1};
std::vector<unsigned>adj[1<<20];
unsigned maxd,rt;
unsigned dfs(unsigned nd){
	return depth[i]||nd==1?depth[i]:depth[i]=dfs(fa[i])+1;
}
unsigned cho[1<<20];
unsigned dfs2(unsigned f,unsigned nd){
	fa[nd]=f;
	depth[nd]=depth[f]+1;
	unsigned cnt=1,max=0;
	cho[nd]=0;
	for(const unsigned&i:adj[nd])
		if(f!=i){
			unsigned res=dfs2(nd,i);
			cnt+=res;
			if(max<res){
				max=res;
				cho[nd]=i;
			}
		}
	return cnt;
}
unsigned anc[1<<20];
void dfs3(unsigned f,unsigned nd,unsigned an){
	anc[nd]=an;
	if(cho[nd])
		dfs3(nd,cho[nd],an);
	for(const unsigned &i:adj[nd])
		if(f!=i&&cho[nd]!=i)
			dfs3(nd,i,i);
}
unsigned lca(unsigned p,unsigned q){
	for(;;){
		if(anc[p]==anc[q])
			return depth[p]<depth[q]?q:p;
		if(depth[anc[p]]>depth[anc[q]])
			p=fa[anc[p]];
		else
			q=fa[anc[q]];
	}
}
std::vector<unsigned>vec;
void work(){
	scanf("%u%u",&n,&k);
	for(unsigned i=1;i<=n;++i)
		adj[i].clear();
	for(unsigned i=1;i<n;++i){
		scanf("%u%u",&u,&v);
		adj[u].push_back(v);
		adj[v].push_back(u);
		if(u>v)
			u^=v^=u^=v;
		fa[v]=u;
	}
	maxd=0;
	rt=1;
	memset(depth,0,sizeof(depth));
	for(unsigned i=2;i<=n;++i)
		if(maxd<dfs(i)){
			maxd=depth[i];
			rt=i;
		}
	dfs2(0,rt);
	dfs3(0,rt,rt);
	maxd=0;
	unsigned ed=rt;
	for(unsigned i=1;i<=n;++i)
		if(depth[i]>maxd){
			maxd=depth[i];
			ed=i;
		}
	while(ed){
		vec.push_back(ed);
		ed=fa[ed];
	}
	unsigned p=vec.size()>>2;
	unsigned q=vec.size()-1-p;
	std::priority_queue<std::pair<unsigned,unsigned>>pq;
	for(unsigned i=1;i<=n;++i)
}
