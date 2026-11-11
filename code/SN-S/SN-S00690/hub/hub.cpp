#include<bits/stdc++.h>
using namespace std;
constexpr int N=2e6+10,L=11,L0=1010,inf=1e9;
int c,T,n,k,u,v,fa[N],cnt,dep[N],res[N],all,mx,l,r,mid,f1[N],f2[N];
vector<int> g[N];
int findf(int x){
	if(x!=fa[x])fa[x]=findf(fa[x]);
	return fa[x];
}
void dfs(int f,int p){
	res[p]=min(res[p],dep[p]);
    for(int i=0;i<g[p].size();i++){
    	if(g[p][i]!=f)dep[g[p][i]]=dep[p]+1,dfs(p,g[p][i]);
	}
	return;
}
void solve1(){
	all=inf;
	for(int S=0;S<(1<<n);S++){
		cnt=__builtin_popcount(S);
		if(cnt!=k)continue;
		for(int i=0;i<n;i++)fa[i]=i;
		for(int i=0;i<n;i++){
			if((S>>i)&1){
				for(int j=0;j<g[i].size();j++){
					if((S>>g[i][j])&1){
						if(findf(i)!=findf(g[i][j]))cnt--;
						fa[findf(i)]=findf(g[i][j]);
					}
				}
			}
		}
		if(cnt>2)continue;
		for(int i=0;i<n;i++)res[i]=inf;
		for(int i=0;i<n;i++){
			if((S>>i)&1)dep[i]=0,dfs(i,i);
		}
		mx=0;
		for(int i=0;i<n;i++)mx=max(mx,res[i]);
		all=min(all,mx);
	}
	printf("%d\n",all);
	return;
}
void solve(){
	scanf("%d%d",&n,&k);
	for(int i=0;i<n;i++)vector<int>().swap(g[i]);
	for(int i=0;i<n-1;i++){
		scanf("%d%d",&u,&v),u--,v--;
		g[u].emplace_back(v),g[v].emplace_back(u);
	}
	if(n<L&&k<L){
		solve1();
		return;
	}
	puts("0");
	return;
}
int main(){
	freopen("hub.in","r",stdin),freopen("hub.out","w",stdout);
	scanf("%d%d",&c,&T);
	while(T--)solve();
	return 0;
}
//黄绿蓝紫。100+100+48+15=263 。在 sn 这里别想去 wc。
//放弃了。还有 sub 7,13,14 是 dyn-dynamite ，但是忘了怎么写了。 
