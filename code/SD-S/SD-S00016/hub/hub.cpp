#include<bits/stdc++.h>
using namespace std;
int c,T,n,k,u,v,dep[1000005],lf[1000005],zhi;
vector<int>G[1000005];
void dfs(int x,int f){
//	for(int i=1;i<=20;i++)	fa[x][i]=fa[fa[x][i-1]][i-1];
	dep[x]=dep[f]+1;
	int mx=0,mx2=0;
	for(int w:G[x])
		if(w!=f){
			dfs(w,x);
			lf[x]=max(lf[x],lf[w]+1);
			if(lf[w]+1>mx)	mx2=max(mx2,mx),mx=lf[w]+1;
			else	mx2=max(mx2,lf[w]+1);
		}
	zhi=max(zhi,mx+mx2);
}
//int lca(int x,int y){
//	if(dep[x]<dep[y])	swap(x,y);
//	int d=dep[x]-dep[y];
//	for(int i=0;i<=20;i++)	if((d>>i)&1)	x=fa[x][i];
//	if(x==y)	return x;
//	for(int i=20;i>=0;i--)	if(fa[x][i]!=fa[y][i])	x=fa[x][i],y=fa[y][i];
//	return fa[x][0];
//}
//int dis(int x,int y){
//	return dep[x]+dep[y]-2*dep[lca(x,y)];
//}
//int query(int x,int y){
//	priority_queue<pair<int,int>>q; 
//	for(int i=1;i<=n;i++)
//		q.push(make_pair(min(dis(x,i),dis(y,i)),i));
//	int p=k-2;
//	while(p){
//		if(fa)
//	}
//	return q.top().first;
//}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>T;
	while(T--){
		cin>>n>>k;
		if(n<=k){
			cout<<"0\n";
			continue;
		}
		if(n<=5){
			cout<<1<<'\n';
			continue;
		}
		for(int i=1;i<=n;i++)	G[i].clear();
		for(int i=1;i<n;i++){
			cin>>u>>v;
			G[u].push_back(v);
			G[v].push_back(u);
		}
		zhi=0;
		dfs(1,0);
//		int ans=0;
//		
//		for(int i=1;i<=n;i++){
//			for(int j=i+1;j<=n;j++)	ans=min(ans,query(i,j));
//		}
		cout<<(zhi+2)/3<<'\n';
	}
	return 0;
}

