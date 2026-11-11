#include<stdio.h>
#include<string.h>
#include<queue>
#include<algorithm>
unsigned c,t,n;
unsigned long long d;
long long x[1<<21];
std::vector<unsigned>adj[1<<21];
unsigned vis[1<<21];
unsigned cnt[1<<21];
void work(){
	scanf("%u%llu",&n,&d);
	for(unsigned l=0,r=0;r<n;++r){
		scanf("%lld",x+r);
		adj[r].clear();
		while(x[r]-x[l]>d)
			++l;
		for(unsigned i=l;i<r;++i)
			adj[i].push_back(r);
	}
	for(unsigned i=0;i<n;++i)
		std::reverse(adj[i].begin(),adj[i].end());
	unsigned long long ans=0;
	for(unsigned i=0;i<n;++i){
		memset(cnt,0,sizeof(cnt));
		memset(vis,0,sizeof(vis));
		cnt[i]=1;
		std::vector<unsigned>p1,p2;
		while(p1.size()){
			for(unsigned j:p1){
				vis[j]=true;
				if(cnt[j]==2)++ans;
				for(unsigned k:adj[j])if(!vis[k]){
					p2.push_back(k);
					cnt[k]+=cnt[j];
				}
			}
		}
		p1=p2;
		p2.clear();
	}
	printf("%llu\n",ans);
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%u%u",&c,&t);
	while(t--)work();
	return 0;
}
