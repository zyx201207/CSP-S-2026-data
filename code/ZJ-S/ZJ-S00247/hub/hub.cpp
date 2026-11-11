#include<bits/stdc++.h>
using namespace std;
#define pb push_back
int C,T,n,k,U[15],V[15],c[15],fa[15],f[15],dep[15],ans;
vector <int> e[15];
int find(int x){
	if(fa[x]==x)return x;
	return fa[x]=find(fa[x]);
}
int dis(int x,int y){
	int ret=0;
	if(dep[x]<dep[y])swap(x,y);
	while(dep[x]!=dep[y]){
		x=f[x];
		ret++;
	}
	if(x==y)return ret;
	while(x!=y){
		x=f[x],y=f[y];
		ret+=2;
	}
	return ret;
}
void dg(int x){
	if(x==n+1){
		for(int i=1;i<=n;i++)fa[i]=i;
		int num=0;
		for(int i=1;i<=n;i++)if(c[i])num++;
		if(num!=k)return ;
		for(int i=1;i<n;i++){
			if(!c[U[i]]||!c[V[i]])continue;
			int A=find(U[i]),B=find(V[i]);
			if(A!=B)fa[A]=B;
		}
		num=0;
		for(int i=1;i<=n;i++){
			if(!c[i])continue;
			find(i);
			if(fa[i]==i)num++;
		}
		if(num>2)return ;
		int sum=0;
		for(int i=1;i<=n;i++){
			if(c[i])continue;
			for(int j=1;j<=n;j++){
				if(!c[j])continue;
				sum=max(sum,dis(i,j));
			}
		}
		ans=min(ans,sum);
		return ;
	}
	for(c[x]=0;c[x]<=1;c[x]++)dg(x+1);
}
void dfs(int u,int faa){
	for(auto v:e[u]){
		if(v==faa)continue;
		dep[v]=dep[u]+1;
		f[v]=u;
		dfs(v,u);
	}
}
void work(){
	ans=1000000000;
	memset(dep,0,sizeof(dep));
	memset(f,0,sizeof(f));
	memset(c,0,sizeof(c));
	for(int i=1;i<=10;i++)e[i].clear();
	cin>>n>>k;
	for(int i=1;i<n;i++){
		cin>>U[i]>>V[i];
		e[U[i]].pb(V[i]);
		e[V[i]].pb(U[i]);
	}
	f[1]=1;
	dfs(1,1);
	dg(1);
	cout<<ans<<'\n';
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>C>>T;
	while(T--)work();
	return 0;
}
/*
1 1
3 3
1 2
3 1
*/