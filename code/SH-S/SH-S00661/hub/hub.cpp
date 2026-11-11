#include<bits/stdc++.h>
#define N 1000005
using namespace std;
int n,k,D,U[N],V[N],deg[N],d[N],p[N],vst[N],dl[N],ds[N],dh[N],f[N],g[N],ans;
vector<int>to[N];
void dfs(int u,int pp){
	d[u]=d[p[u]=pp]+1,dl[u]=0,vst[u]=1;
	for(int i=0,v;i<(int)to[u].size();i++){
		v=to[u][i];
		if(!v||v==pp)continue;
		dfs(v,u);
		dl[u]=max(dl[u],dl[v]+1);
	}
}
int ssolve(int u){
	if(!deg[u])return 1;
	p[u]=0;
	dfs(u,0);
	int a=u;
	for(int i=1;i<=n;i++){
		if(vst[i]&&d[i]>d[a])a=i;
	}
	p[a]=0;
	dfs(a,0);
	int b=u;
	for(int i=1;i<=n;i++){
		if(vst[i]&&d[i]>d[b])b=i;
	}
	int rt=b;
	for(int i=1;i<=d[b]/2;i++){
		rt=p[rt];
	}
	dfs(rt,0);
	int cnt=0;
	for(int i=1;i<=n;i++){
		if(vst[i]&&(i==rt||dl[i]>=D))++cnt;
	} 
//	clog<<rt<<' '<<cnt<<'\n';
//	for(int i=1;i<=n;i++)clog<<vst[i];
//	clog<<'\n';
//	for(int i=1;i<=n;i++)clog<<dl[i];
//	clog<<'\n';
	for(int i=1;i<=n;i++)vst[i]=0;
	return cnt;
}
bool OK(int mid){
	D=mid;
	int mn=ssolve(1);
//	clog<<D<<' '<<mn<<'\n';
	for(int del=1;del<n;del++){
		int u=U[del],v=V[del];
		for(int i=0;i<(int)to[u].size();i++){
			if(to[u][i]==v)to[u][i]=0;
		}
		for(int i=0;i<(int)to[v].size();i++){
			if(to[v][i]==u)to[v][i]=0;
		}
		--deg[u],--deg[v];
		int su=ssolve(u),sv=ssolve(v);
//		clog<<u<<' '<<su<<"   "<<v<<' '<<sv<<'\n';
//		for(int i=1;i<=n;i++){
//			clog<<dl[i]<<' ';
//		}
//		clog<<'\n';
		mn=min(mn,su+sv);
		++deg[u],++deg[v];
		for(int i=0;i<(int)to[u].size();i++){
			if(to[u][i]==0)to[u][i]=v;
		}
		for(int i=0;i<(int)to[v].size();i++){
			if(to[v][i]==0)to[v][i]=u;
		}
	}
	return mn<=k;
}
void solve(){
	cin>>n>>k;
	for(int i=1,u,v;i<n;i++){
		cin>>u>>v,U[i]=u,V[i]=v;
		to[u].push_back(v);
		to[v].push_back(u);
		++deg[u],++deg[v]; 
	}
	if(k==n)cout<<0<<'\n';
	else{
		int l=1,r=n-1,ans=n;
		while(l<=r){
			int mid=(l+r)/2;
			if(OK(mid))r=mid-1,ans=mid;
			else l=mid+1;
		}
		cout<<ans<<'\n';
	} 
	for(int i=1;i<=n;i++){
		to[i].clear();
		U[i]=V[i]=0,deg[i]=dl[i]=vst[i]=d[i]=p[i]=0;
	}
}
void dfsk2(int u,int pp){
	p[u]=pp,dl[u]=0,ds[u]=0,f[u]=0;
	for(int i=0,v;i<(int)to[u].size();i++){
		v=to[u][i];
		if(v==pp)continue;
		dfsk2(v,u);
		ds[u]=max(dl[v]+1,ds[u]);
		if(ds[u]>dl[u])swap(dl[u],ds[u]);
		f[u]=max(f[u],f[v]);
	}
	f[u]=max(f[u],dl[u]+ds[u]);
}
void sfdk2(int u){
	for(int i=0,v;i<(int)to[u].size();i++){
		v=to[u][i];
		if(v==p[u])continue;
		if(dl[u]==dl[v]+1){
			dh[v]=max(dh[u]+1,ds[u]+1);
			g[v]=max(g[u],max(dh[u]+ds[u],dl[u]+ds[u]));
		}
		else{
			dh[v]=max(dh[u]+1,dl[u]+1);
			g[v]=max(g[u],max(dh[u]+dl[u],dl[u]+ds[u]));
		}
		sfdk2(v);
	}
	ans=min(ans,max((f[u]+1)/2,(g[u]+1)/2));
}
void solvek2(){
	cin>>n>>k;
	for(int i=1,u,v;i<n;i++){
		cin>>u>>v;
		to[u].push_back(v);
		to[v].push_back(u);
	}
	if(k==n)cout<<0<<'\n';
	else{
		ans=n;
		p[1]=0;
		dfs(1,0);
		int a=1;
		for(int i=1;i<=n;i++){
			if(vst[i]&&d[i]>d[a])a=i;
		}
		p[a]=0;
		dfs(a,0);
		int b=1;
		for(int i=1;i<=n;i++){
			if(vst[i]&&d[i]>d[b])b=i;
		}
		int rt=b;
		for(int i=1;i<=d[b]/2;i++){
			rt=p[rt];
		}
		dfsk2(rt,0);
		g[rt]=dh[rt]=0;
		sfdk2(rt);
//		clog<<rt<<'\n';
//		for(int i=1;i<=n;i++){
//			clog<<dl[i]<<' '<<ds[i]<<' '<<f[i]<<' '<<dh[i]<<' '<<g[i]<<' '<<(f[i]+1)/2<<' '<<(g[i]+1)/2<<'\n';
//		}
		cout<<ans<<'\n';
	} 
	for(int i=1;i<=n;i++){
		to[i].clear(),p[i]=dl[i]=ds[i]=dh[i]=f[i]=g[i]=0;
	}
}
bool OKA(int D){
	int m=(n-1)/2,mn=m+2-D*2;
	for(int i=1;i<=m;i++){
		mn=min(mn,max(1,i+2-D*2)+max(1,m-i+2-D*2));
	}
	return mn<=k;
}
void solveA(){
	cin>>n>>k;
	for(int i=1,u,v;i<n;i++){
		cin>>u>>v;
	}
	if(k==n)cout<<0<<'\n';
	else{
		int l=1,r=n-1,ans=n;
		while(l<=r){
			int mid=(l+r)/2;
			if(OKA(mid))r=mid-1,ans=mid;
			else l=mid+1;
		}
		cout<<ans<<'\n';
	}
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	int C,T=1;
	cin>>C>>T;
	while(T--){
		if(C<=10)solve();
		else if(C<=12)solvek2();
		else solveA();
	}
	return 0;
}

