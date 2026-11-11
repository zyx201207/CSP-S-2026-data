#include<bits/stdc++.h>
using namespace std;

const int N=2000010;
int n,k;
int ex[N],ey[N],dep[N];
vector<int>g[N];
void dfs1(int u,int fa){
	dep[u]=dep[fa]+1;
	for(auto v:g[u]){
		if(v==fa)continue;
		dfs1(v,u);
	}
}
int stk[N],top,tmp[N],len,qwq,res,lim;
void dfs2(int u,int fa,int t){
	stk[++top]=u;
	if(u==t)qwq=stk[(top+1)/2];
	for(auto v:g[u]){
		if(v==fa)continue;
		dfs2(v,u,t);
	}
	top--;
}
void dfs3(int u,int fa){
	dep[u]=0;
	for(auto v:g[u]){
		if(v==fa)continue;
		dfs3(v,u);
		dep[u]=max(dep[u],dep[v]+1);
	}
	if(dep[u]>=lim)res++;
}
int solve(int rt,int mid){
	lim=mid;
	dfs1(rt,0);
	int mx=0,x=0,y=0;
	for(int i=1;i<=n;i++){
		if(dep[i]>mx){
			mx=dep[i];
			x=i;
		}
		dep[i]=0;
	}
	dfs1(x,0);
	mx=0;
	for(int i=1;i<=n;i++){
		if(dep[i]>mx){
			mx=dep[i];
			y=i;
		}
		dep[i]=0;
	}
	dfs2(x,0,y);
	res=0;
	dfs3(qwq,0);
	for(int i=1;i<=n;i++)dep[i]=0;
	return res;
}
bool check(int mid){
	for(int i=1;i<n;i++){
		for(int j=1;j<n;j++){
			if(i!=j){
				g[ex[j]].push_back(ey[j]);
				g[ey[j]].push_back(ex[j]);
			}
		}
		int x=solve(ex[i],mid);
		int y=solve(ey[i],mid);
		for(int j=1;j<=n;j++)g[j].clear();
		if(x+y<=k)return 1;
	}
	return 0;
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int c,T;
	cin>>c>>T;
	while(T--){
		cin>>n>>k;
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			ex[i]=u;ey[i]=v;
		}
		int l=0,r=n,best=n;
		while(l<=r){
			int mid=(l+r)>>1;
			if(check(mid)){
				best=mid;
				r=mid-1;
			}else l=mid+1;
		}
		cout<<best<<'\n';
	}
	return 0;
}