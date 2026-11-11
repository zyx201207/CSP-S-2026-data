/*
 * 在这亭台回眸
 * 千年后忆起你是谁
 * 只消月色隐约
 * 便足以勾勒这是非
 * 待这回忆涌起
 * 恍惚之间已下泪
 * 枫红十里长街
 * 红帘后谁人蹙着眉
 * 遥梦桑竹桃园
 * 轮回中曾道别的地点
 * 愿今生 再相见
 * 消融你眉间悲戚霜雪
 */

#include<bits/stdc++.h>
using namespace std;
#define N 1000004
int tid;
int n,k,fa[N],len[N],sec_len[N];
vector<int> v[N];
void dfs1(int p,int f){
	fa[p]=f;
	for(int i:v[p])if(i!=f){
		dfs1(i,p);
	}
}
int R;
int q[N],ql,qr,dis[N],pre[N];
struct info{int x,y,d,m;};
info find_diameter(int p,int f){
	ql=1,qr=0;
	q[++qr]=p,pre[p]=f,dis[p]=0;
	int mx=-1,x=0;
	while(ql<=qr){
		int t=q[ql++];
		if(dis[t]>mx)mx=dis[t],x=t;
		for(int i:v[t])if(i!=pre[t])q[++qr]=i,pre[i]=t,dis[i]=dis[t]+1;
	}
	ql=1,qr=0;
	q[++qr]=x,pre[x]=0,dis[x]=0;
	mx=-1;int y=0;
	while(ql<=qr){
		int t=q[ql++];
		if(dis[t]>mx)mx=dis[t],y=t;
		for(int i:v[t])if(i!=pre[t]&&i!=f)q[++qr]=i,pre[i]=t,dis[i]=dis[t]+1;
	}
	int d=mx;
	int pt=y;
	for(int i=1;i<=d/2;++i)pt=pre[pt];
	return {x,y,mx,pt};
}
int subtree_cnt;
void dfs2(int p,int f,int o){
	len[p]=0;
	for(int i:v[p])if(i!=f&&i!=o)dfs2(i,p,o),len[p]=max(len[p],len[i]+1);
	if(len[p]>=R)++subtree_cnt;
}
int subtree(int p,int f){
	info D=find_diameter(p,f);
	//cerr<<p<<" "<<f<<" Diameter:"<<D.x<<"~"<<D.y<<",mid="<<D.m<<",len="<<D.d<<endl;
	if(D.d<=2*R)return 1;
	subtree_cnt=0;
	dfs2(D.m,0,f);
	return subtree_cnt;
}
bool chk(){
	for(int i=1;i<=n;++i)if(fa[i]){
		if(subtree(i,fa[i])+subtree(fa[i],i)<=k)return true;
	}
	return false;
}
void MoLing_qwq(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;++i)v[i].clear();
	for(int i=1,x,y;i<n;++i){
		scanf("%d%d",&x,&y);
		v[x].push_back(y);
		v[y].push_back(x);
	}
	if(k==n){puts("0");return;}
	dfs1(1,0);
	int l=0,r=n,mid;
	while(l<r){
		mid=(l+r)>>1;
		R=mid;//cerr<<"R="<<R<<endl;
		if(chk())r=mid;
		else l=mid+1;
	}
	printf("%d\n",l);
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int T;
	scanf("%d%d",&tid,&T);
	while(T--)MoLing_qwq();
	return 0;
}
