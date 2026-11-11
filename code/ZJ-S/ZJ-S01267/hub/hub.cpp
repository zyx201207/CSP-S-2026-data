#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1000010;
const ll INF=2e16;
int c,t,n,k;
vector<int>ed[N];
void init(){
	for(int i=1;i<=n;i++)ed[i].clear();
}
bool base[N];
bool dfs(int u,int num,int lian,int fa,int dis,const int& Mdis,int dfn){
	//减枝
	if(lian>2)return 0;
	if(num>k)return 0;
	//作为基地
	base[u]=1;
	for(auto v:ed[u])
		if(v!=fa){
			if(dfs(v,num+1,base[fa]?lian:lian+1,u,1,Mdis,dfn+1)){
				base[u]=0;
				return 1;
			}
		}
	base[u]=0;
	//不作为基地
	if(dis>Mdis)return 0;
	for(auto v:ed[u])
		if(v!=fa)
			if(dfs(v,num,lian,u,dis+1,Mdis,dfn+1))return 1;
	return dfn==n;
}
bool check(int x){
	if(dfs(1,0,0,0,1,x,1))return 1;
	return 0;
}
int main(){
	 freopen("hub.in","r",stdin);
	 freopen("hub.out","w",stdout);
	scanf("%d%d",&c,&t);
	while(t--){
		init();
		scanf("%d%d",&n,&k);
		for(int i=1;i<n;i++){
			int u,v;
			scanf("%d%d",&u,&v);
			ed[u].push_back(v),ed[v].push_back(u);
		}
		int l=1,r=n;
		while(l<=r){
			int mid=(l+r)>>1;
			if(check(mid))r=mid-1;
			else l=mid+1;
		}
		printf("%d\n",l);
	}
} 