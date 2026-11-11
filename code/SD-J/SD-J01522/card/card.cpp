#include<bits/stdc++.h>
#define ll long long
#define N 500100
#define M 300100

using namespace std;
ll read(){
	ll x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
	return x*f;
}
ll n,m,l,P,len,a[N],s[N],ans[M],pos[M],tag[N<<2];bool vis[M];
struct node{int l,r;};vector<node>lst[M];vector<int>pre[M];
struct Seg{int x,id;}tr[N<<2],res;//区间最右不为 0 的值 
int ls(int p){return p<<1;}
int rs(int p){return p<<1|1;}
Seg merge(Seg ls,Seg rs){
	if(ls.x!=-1&&rs.x==-1)return ls;
	if(ls.x==-1&&rs.x!=-1)return rs;
	return rs;
}
void build(int p,int pl,int pr){
	if(pl==pr){tr[p]={-1,pl};return;}
	int mid=(pl+pr)>>1;
	build(ls(p),pl,mid);
	build(rs(p),mid+1,pr);
	tr[p]=merge(tr[ls(p)],tr[rs(p)]); 
}
void add_tag(int p,int d){tr[p].x=d,tag[p]|=d;}
void push_down(int p){if(tag[p])add_tag(ls(p),tag[p]),add_tag(rs(p),tag[p]);tag[p]=0;}
void update(int p,int pl,int pr,int L,int R,int d){
	if(L>R)return ;
	if(L<=pl&&R>=pr){add_tag(p,d);return ;}
	int mid=(pl+pr)>>1;push_down(p);
	if(L<=mid)update(ls(p),pl,mid,L,R,d);
	if(R>=mid+1)update(rs(p),mid+1,pr,L,R,d);
	tr[p]=merge(tr[ls(p)],tr[rs(p)]);
}
Seg query(int p,int pl,int pr,int L,int R){
	if(L>R)return {-1,0};
	if(L<=pl&&R>=pr)return tr[p];push_down(p);
	int mid=(pl+pr)>>1;Seg res={-1,0};
	if(L<=mid)res=merge(res,query(ls(p),pl,mid,L,R));
	if(R>=mid+1)res=merge(res,query(rs(p),mid+1,pr,L,R));
	return res;
}

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;++i)a[i]=read(),pos[i]=0;
	for(int i=1;i<=m;++i)pre[i].push_back(0); 
	for(int i=1;i<=n;++i)pre[a[i]].push_back(i);
	for(int i=2;i<=n+1;++i){
		if(a[i]==a[i-1])++l;
		else lst[a[i-1]].push_back({i-l-1,i-1}),l=0;
	}
	build(1,1,n);
	for(int j=n;j>=1;--j){
		if(vis[a[j]])continue;len=pre[a[j]].size();if(len==1)continue;
		for(int i=1;i<len;++i){
			res=query(1,1,n,pre[a[j]][i-1]+1,pre[a[j]][i]-1);
			ans[a[j]]+=res.x==-1?pre[a[j]][i]-pre[a[j]][i-1]:pre[a[j]][i]-res.id;
		}
		for(auto g:lst[a[j]])update(1,1,n,g.l,g.r,1),vis[a[j]]=true;
	}
	for(int i=1;i<=m;++i)cout<<ans[i]<<" ";cout<<"\n";
	return 0;
}
/*
10 3
3 1 2 1 3 2 3 1 2 1
 */
