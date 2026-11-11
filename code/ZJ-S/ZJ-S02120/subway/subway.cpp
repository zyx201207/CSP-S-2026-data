#include<bits/stdc++.h>
using namespace std;
const int N=6e5+9,M=6e5+9,D=25;
const long long MX=2e18;
int n,m,q,d,c,cnt;
int rk[N+M],fa[N+M];
int dad[N+M],sz[N+M],top[N+M],dep[N+M];
long long w[M],hson[N+M],qp[N+M];
int vis[N+M];
int find(int pos){
	return fa[pos]==pos?pos:fa[pos]=find(fa[pos]);
}
void add(int x,int y){
	x=find(x);
	y=find(y);
	if(x==y)return ;
	if(rk[x]>rk[y])fa[y]=x;
	else {
		fa[x]=y;
		if(rk[x]==rk[y])rk[y]++;
	}
	return ;
}
struct edge1{
	int ed,start;
	long long nm;
}qe[N+M];
bool cmp(edge1 a,edge1 b){
	return a.nm <b.nm ;
}
struct edge2{
	int ed;
	long long nm;
};
vector <edge2>mp[N];
void dfs1(int pos,int fat,long long dp){
	dad[pos]=fat;
	dep[pos]=dep[fat]+1;
	qp[pos]=dp;
	sz[pos]=1;
	for(int i=0;i<mp[pos].size();i++){
		int son=mp[pos][i].ed;
		if(son!=fat){
			dfs1(son,pos,dp+mp[pos][i].nm);
			sz[pos]+=sz[son];
			if(sz[son]>sz[hson[pos]])hson[pos]=son;
		}
	}
	return ;
}
void dfs2(int pos,int tp){
	top[pos]=tp;
	if(hson[pos])dfs2(hson[pos],tp);
	for(int i=0;i<mp[pos].size();i++){
		int son=mp[pos][i].ed;
		if(son!=hson[pos]&&son!=dad[pos]){
			dfs2(son,son);
		}
	}
	return ;
}
int lca(int x,int y){
	while(top[x]!=top[y]){
		if(dep[top[x]]<dep[top[y]])swap(x,y);
	//	cout<<x;
		x=dad[top[x]];
	}
	return dep[x]>dep[y]?y:x;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d %d %d %d %d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++){
		scanf("%lld",&w[i]);
	}//cout<<1;
	for(int i=1;i<=n+m;i++)fa[i]=i;
	for(int i=1;i<=n;i++){
		int k;
		scanf("%d",&k);
		for(int j=1;j<=k;j++){
			int x,y;
			scanf("%d %d",&x,&y);
		    qe[++cnt]={i+m,x,y};
			}
		}//cout<<2;
	sort(qe+1,qe+1+cnt,cmp);
	int kkk=0;//cout<<3;
	for(int i=1;i<=cnt;i++){
		int st=find(qe[i].start) ,ed=find(qe[i].ed) ;
		if(st!=ed){
			add(st,ed);
			mp[qe[i].start ].push_back({qe[i].ed,qe[i].nm } );
			mp[qe[i].ed ].push_back({qe[i].start,qe[i].nm} );
			if(++kkk==cnt-1)break;
		}
	}
	dfs1(1,0,0);//cout<<4;
	dfs2(1,1);//cout<<5;
	while(q--){
		int x,y;
		scanf("%d %d",&x,&y);//cout<<6;
		int dzn=lca(x,y);
		printf("%lld\n",w[x]+w[y]+qp[x]+qp[y]-2ll*qp[dzn]);
	}
	return 0;
}