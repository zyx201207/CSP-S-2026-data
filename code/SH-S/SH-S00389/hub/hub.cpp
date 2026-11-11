#include<bits/stdc++.h>//“…À∆∂¡¥ÌÃ‚ 
using namespace std;
int c,T,n,k,dep[1100000],fa[1100000],top[1100000],sz[1100000],wc[1100000],ans=INT_MAX,dsu[1100000];
bool flg[1100000],bkt[1100000];
vector<int>sons[1100000];
void dfs1(int pos,int lst){
	fa[pos]=lst,sz[pos]=1,dep[pos]=dep[lst]+1;
	for(int son:sons[pos]){
		if(son==lst)continue;
		dfs1(son,pos);
		sz[pos]+=sz[son];
		if(sz[son]>=sz[wc[pos]])wc[pos]=son;
	}
	return;
}
void dfs2(int pos,int topnow){
	top[pos]=topnow;
	if(wc[pos])dfs2(wc[pos],topnow);
	for(int son:sons[pos]){
		if(son==fa[pos]||son==wc[pos])continue;
		dfs2(son,son);
	}
	return;
}
int lca(int a,int b){
	while(top[a]!=top[b]){
		if(dep[top[a]]<dep[top[b]])swap(a,b);
		a=fa[top[a]];
	}
	if(dep[a]>dep[b])swap(a,b);
	return a;
}
int dis(int a,int b){
	return dep[a]+dep[b]-2*dep[lca(a,b)];
}
void init(){
	for(int i=1;i<=n;i++)dsu[i]=i;
	return;
}
int find(int x){
	if(dsu[x]==x)return x;
	dsu[x]=find(dsu[x]);
	return dsu[x];
}
void merge(int x,int y){
	x=find(x),y=find(y);
	if(x==y)return;
	dsu[x]=y;
	return;
}
void dfs3(int pos,int dcnt){
	if(dcnt==k){
		int tmpcnt=0;
		memset(bkt,0,sizeof bkt);
		init();
		for(int i=1;i<=n;i++){
			if(!flg[i])continue;
			for(int son:sons[i]){
				if(!flg[son])continue;
				if(find(i)==find(son))continue;
				merge(i,son);
				//cout<<"mer "<<i<<" "<<son<<"\n";
			}
		}
		for(int i=1;i<=n;i++){
			if(!flg[i])continue;
			if(!bkt[find(i)])tmpcnt++,bkt[find(i)]=1;
		}
		if(tmpcnt>2)return;
		//cout<<"aaa "<<pos<<" "<<" "<<dcnt<<"\n";
		//for(int i=1;i<=n;i++)if(flg[i])cout<<i<<" ";
		//cout<<"\n";
		int tans=0;
		for(int i=1;i<=n;i++)if(!flg[i])for(int j=1;j<=n;j++)tans=max(tans,dis(i,j));
		//cout<<tans<<"\n";
		//for(int i=1;i<=n;i++)if(!flg[i])for(int j=1;j<=n;j++)//cout<<i<<" "<<j<<"\n";
		ans=min(ans,tans);
		return;
	}
	if(pos==n+1)return;
	flg[pos]=1;
	dfs3(pos+1,dcnt+1);
	flg[pos]=0;
	dfs3(pos+1,dcnt);
	return;
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>T;
	while(T--){
		cin>>n>>k;
		for(int i=1;i<=n;i++)sons[i].clear();
		ans=INT_MAX,memset(flg,0,sizeof flg),memset(dep,0,sizeof dep),memset(sz,0,sizeof sz),memset(fa,0,sizeof fa),memset(wc,0,sizeof wc),memset(top,0,sizeof top);
		for(int i=1,a,b;i<n;i++){
			cin>>a>>b;
			sons[a].push_back(b);
			sons[b].push_back(a);
		}
		dfs1(1,0);
		dfs2(1,1);
		//for(int i=1;i<=n;i++)cout<<dep[i]<<" "<<fa[i]<<" "<<sz[i]<<" "<<top[i]<<" "<<wc[i]<<"\n";
		//for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)cout<<i<<" "<<j<<" "<<lca(i,j)<<" "<<dis(i,j)<<"\n";
		dfs3(1,0);
		cout<<ans/3<<"\n";
	}
	return 0;
}
