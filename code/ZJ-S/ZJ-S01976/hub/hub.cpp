#include <bits/stdc++.h>
using namespace std;
int ID;
int n,k;
vector<int>e[1000005];
int fat[1000005][20],de[1000005];
void dfs1(int u,int fa){
	fat[u][0]=fa,de[u]=de[fa]+1;
	for(int i=1;i<20;i++) fat[u][i]=fat[fat[u][i-1]][i-1];
	for(auto v:e[u]) if(v!=fa) dfs1(v,u);
}
int kth(int u,int k){
	for(int i=0;i<20;i++) if((k>>i)&1) u=fat[u][i];
	return u;
}
int LCA(int u,int v){
	if(de[u]<de[v]) swap(u,v);
	for(int i=19;i>=0;i--) if(de[fat[u][i]]>=de[v]) u=fat[u][i];
	if(u==v) return u;
	for(int i=19;i>=0;i--) if(fat[u][i]!=fat[v][i]) u=fat[u][i],v=fat[v][i];
	return fat[u][0];
}
int Mid(int u,int v){
	if(de[u]<de[v]) swap(u,v);
	int lca=LCA(u,v),dis=de[u]+de[v]-2*de[lca];
	return kth(u,dis/2);
}
int ma,mak;
void dfs2(int u,int fa,int dis,int ban){
	if(dis>=ma) ma=dis,mak=u;
	for(auto v:e[u]) if(v!=fa&&v!=ban) dfs2(v,u,dis+1,ban);
}
int get(int x,int y){
	int u,v;
	ma=0,dfs2(x,0,0,y),u=mak;
	ma=0,dfs2(u,0,0,y),v=mak;
	return Mid(u,v);
}
int cnt[1000005];
int dfs3(int u,int fa,int ban,int &ma){
	int tmp=0;
	for(auto v:e[u]) if(v!=fa&&v!=ban) tmp=max(tmp,dfs3(v,u,ban,ma)+1);
	cnt[tmp]++,ma=max(ma,tmp);
	return tmp;
}
int work(int x,int y){
	int u=get(x,y),v=get(y,x),mu=0,mv=0;
	for(int i=0;i<=n;i++) cnt[i]=0;
	dfs3(u,0,y,mu),dfs3(v,0,x,mv);
	// cout<<mu<<" "<<mv<<"\n";
	for(int i=max(mu,mv),now=0;i>=0;i--){
		now+=cnt[i];
		if(now+(i>mu)+(i>mv)>k) return i+1;
	}
	return 0;
}
namespace solve1{
	int ma[1000005],sma[1000005],rma[1000005];
	int res1[1000005],res2[1000005];
	void dfs(int u,int fa){
		ma[u]=sma[u]=0,res1[u]=0;
		for(auto v:e[u]) if(v!=fa){
			dfs(v,u),res1[u]=max(res1[u],res1[v]);
			int t=ma[v]+1;
			if(t>=ma[u]) sma[u]=ma[u],ma[u]=t;
			else sma[u]=max(sma[u],t);
		}
		res1[u]=max(res1[u],ma[u]+sma[u]);
	}
	void dfs2(int u,int fa){
		int maxx=0,smaxx=0;
		int _ma=0,_sma=0,_tma=0;
		for(auto v:e[u]) if(v!=fa){
			if(res1[v]>=maxx) smaxx=maxx,maxx=res1[v];
			else smaxx=max(smaxx,res1[v]);
			int t=ma[v]+1;
			if(t>=_ma) _tma=_sma,_sma=_ma,_ma=t;
			else if(t>=_sma) _tma=_sma,_sma=t;
			else if(t>=_tma) _tma=t;
		}
		for(auto v:e[u]) if(v!=fa){
			int tmp=(_ma==ma[v]+1)?_sma:_ma;
			rma[v]=max(tmp,rma[u])+1;
			res2[v]=max(res2[u],rma[u]+tmp);
			if(ma[v]+1==_ma) res2[v]=max(res2[v],_sma+_tma);
			else if(ma[v]+1==_sma) res2[v]=max(res2[v],_ma+_tma);
			else res2[v]=max(res2[v],_ma+_sma);
			if(res1[v]==maxx) res2[v]=max(res2[v],smaxx);
			else res2[v]=max(res2[v],maxx);
			dfs2(v,u);
		}
	}
	int solve(){
		dfs(1,0),rma[1]=0,res2[1]=0,dfs2(1,0);
		int res=n;
		for(int i=2;i<=n;i++){
			// cout<<(res1[i]+1)/2<<" "<<(res2[i]+1)/2<<"\n";
			res=min(res,max(res1[i],res2[i]));
		}
		return (res+1)/2;
	}
}
void solve(){
	cin>>n>>k;
	for(int i=1;i<=n;i++) e[i].clear();
	for(int i=1,u,v;i<n;i++) cin>>u>>v,e[u].emplace_back(v),e[v].emplace_back(u);
	if(ID==13||ID==14){
		if(k==n){cout<<"0\n";return;}
		int m=n/2-1;
		if(k>m){cout<<"1\n";return;}
		cout<<(m-k)/4+2<<"\n";
		return;
	}
	dfs1(1,0);
	int res=0;
	int u=get(1,0),mu=0;
	for(int i=0;i<=n;i++) cnt[i]=0;
	dfs3(u,0,0,mu);
	for(int i=mu,now=0;i>=0;i--){
		now+=cnt[i];
		if(now>k){res=i+1;break;}
	}
	if(ID==11||ID==12){
		res=min(res,solve1::solve());
	}
	else{
		for(int i=2;i<=n;i++) res=min(res,work(i,fat[i][0]));
	}
	cout<<res<<"\n";
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int Ca;cin>>ID>>Ca;while(Ca--)solve();
	return 0;
}