#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define endl '\n'
const int N=2e6+10;
int a[N],c,t,top[N],fat[N],dep[N],son[N],siz[N],fa[N],n,k,in[N];
vector<int>e[N];
vector<pair<int,int> >rd;
vector<int>dow;
int find(int x){
	if (fa[x]==x)return x;
	return fa[x]=find(fa[x]);
}
void dfs1(int x,int fa){
	dep[x]=dep[fa]+1;fat[x]=fa;
	siz[x]=1;
	son[x]=0;
	for (int it:e[x]){
		if (it==fa) continue;
		dfs1(it,x);
		siz[x]+=siz[it];
		if (siz[son[x]]<siz[it])son[x]=it;
	}
}
void dfs2(int x,int fa,int tp){
	top[x]=tp;
	for (int it:e[x]){
		if (it==fa||it==son[x])continue;
		dfs2(it,x,it);
	}
	if (son[x]!=0) dfs2(son[x],x,tp);
}
int lca(int x,int y){
	while(top[x]!=top[y]){
		if (dep[top[x]]<dep[top[y]]) swap(x,y);
		x=fat[top[x]];
	}
	if (dep[x]>dep[y])swap(x,y);
	return x;
}
int dist(int x,int y){
	int anc=lca(x,y);
	return dep[x]+dep[y]-2*dep[anc];
}
int work(){
	for (auto it:rd){
		if (in[it.first]==1&&in[it.second]==1){
			int u=find(it.first),v=find(it.second);
			fa[u]=v;
		}
	}
	int cnt=0;
//	cout<<endl;
	for (int it:dow){
//		cout<<it<<"×æ×ÚÊÇ"<<find(it)<<endl;
		if (find(it)==it)cnt++;
	}
//	cout<<endl<<"pg:"<<cnt<<endl;
	if (cnt>2) return INT_MAX;
	int ans=0;
	for (int i=1;i<=n;i++){
		int res=INT_MAX;
		if (in[i]==1)continue;
		for (int j:dow){	
//			cout<<i<<"~"<<j<<"="<<dist(i,j)<<endl; 
			res=min(res,dist(i,j));
		}
		ans=max(ans,res);
	}
	return ans;
}
void cle(){
	rd.clear();
	for (int i=1;i<=n;i++)e[i].clear(),in[i]=0,top[i]=0,son[i]=0,fat[i]=0,dep[i]=0,siz[i]=0;
	
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for (int i=1;i<n;i++){
			int u,v;cin>>u>>v;
			e[u].push_back(v);
			e[v].push_back(u);
			rd.push_back({u,v});
		}
		dfs1(1,0);
		dfs2(1,0,1);
//		cout<<"adsfzdsfa------------"<<dist(1,5)<<endl;
		int res=INT_MAX;
		for (int i=1;i<(1<<n);i++){
			if (__builtin_popcount(i)==k){
				for (int i=1;i<=n;i++)fa[i]=i;
				for (int j=1;j<=n;j++){
					if ((i>>(j-1))&1){
						in[j]=1;
						dow.push_back(j);
					}
				}
//				cout<<"----";
//				for (int it:dow){
//					cout<<it<<" ";
//				}
				res=min(res,work());
//				cout<<"::::"<<res<<endl;				
				for (int it:dow)in[it]=0;
				dow.clear();
			}
		}
		cout<<res<<endl;
		cle();
	}	
	return 0;
}
