#include<cstdio>
#include<algorithm>
#include<cmath>
#include<iostream>
#include<cstring>
using namespace std;
int c,t,n,k,u,v,fa[4010],son[4010],dep[4010],dis[4010][4010],tq_dis[4010];
int ans=1e9;
bool cho[4010];
int find(int x){
	if(fa[x]==x)
	    return x;
	else
	    return fa[x]=find(x);
}
int find_anc(int x,int y){
	if(fa[x]==fa[y])
	    return fa[x];
	if(fa[y]==y)
	    return find_anc(fa[x],y);
	else
	    return find_anc(x,fa[y]);
}
void merge(int x,int y){
	if(find(x)==find(y))
	    return;
	if(dep[x]>=dep[y]){//xÎª¸¸Ç× 
		dep[y]=dep[x]+1;
		fa[y]=x;
		son[x]=y;
	}else{
		dep[x]=dep[y]+1;
		fa[x]=y;
		son[y]=x;
	}
}
int dist(int x){
	if(cho[x])
	    return x;
	else {
		int p=1e9,q=1e9;
		if(fa[x]!=x)
		    p=dist(fa[x])+1;
		if(son[x]!=x)
		    q=dist(son[x])+1;
		return min(p,q);
	}
}
int check(){
	int ret=0;
	for(int i=1;i<=n;i++){
		if(cho[i])
		    continue;
		else{
			int p=dist(i);
			ret=max(ret,p);
		}
	}
	return ret;
}
void dfs(int chosen){
	if(chosen==3){
		ans=min(ans,check());
		return;
	}
	for(int i=1;i<=n;i++){
		if(!cho[i]){
			cho[i]=true;
			dfs(chosen+1);
			cho[i]=false;
		}
	}
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>t;
	while(t--){
		ans=1e9;
		cin>>n>>k;
		for(int i=1;i<=n;i++){
			dep[i]=1;
			fa[i]=i;
			son[i]=i;
		}
		for(int i=1;i<=n-1;i++){
			cin>>u>>v;
			merge(u,v);
		}
		dfs(0);
		cout<<ans<<"\n"; 
	}
	return 0;
} 
