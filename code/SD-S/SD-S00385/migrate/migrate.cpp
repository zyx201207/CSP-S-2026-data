#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e6+5;
int n,idx=0;
ll d,a[N];
int pos[N];
#define lc (u<<1)
#define rc (u<<1|1)
#define mid (l+r>>1)
int h[N],dis[N],pre[N],vis[N];
//void build(int u,int l,int r){
//	if(l==r){
//		pos[l]=u;
//		return ;
//	}
//	add(u,lc,0); add(u,rc,0);
//	build(lc,l,mid);
//	build(rc,mid+1,r);
//}
//void upd(int u,int l,int r,int x,int y,int k){
//	if(x<=l && r<=y){
//		add(k,u,1);
//		return ;
//	}
//	if(x<=mid) upd(lc,l,mid,x,y,k);
//	if(y>mid)  upd(rc,mid+1,r,x,y,k);
//}
//int Dij(int x){
//	list<int> q;
//	for(int i=1;i<=4*n;++i) dis[i]=1e9,pre[i]=vis[i]=0;
//	q.push_front(pos[x]);
//	dis[pos[x]]=0; pre[pos[x]]=1;
//	while(!q.empty()){
//		int x=q.front();
//		q.pop_front();
//		if(vis[x]) continue;
//		vis[x]=1;
//		for(int i=h[x];i;i=e[i].ne){
//			int y=e[i].to,c=e[i].w;
//			if(dis[y]>dis[x]+c){
//				dis[y]=dis[x]+c;
//				pre[y]=pre[x];
//				if(c) q.push_back(y);
//				else q.push_front(y);
//			}
//			else if(dis[y]==dis[x]+c){
//				pre[y]+=pre[x];
//			}
//		}
//	}
//	int tmp=0;
//	for(int i=x+1;i<=n;++i) printf("%d %d %d %d\n",x,i,dis[pos[i]],pre[pos[i]]);
//	for(int i=x+1;i<=n;++i) if(pre[pos[i]]==2) ++tmp;
//	return tmp;
//}
int L[N],R[N];
int fd(int x){
	for(int i=x+1;i<=n;++i) dis[i]=1e9,pre[i]=0;
	dis[x]=0,pre[x]=1;
	int ans=0;
	for(int i=x;i<=n;++i){
		if(dis[i]<1e9 && pre[i]==2) ++ans;
		for(int j=i+1;j<=R[i];++j){
			if(dis[j]>dis[i]+1){
				dis[j]=dis[i]+1;
				pre[j]=pre[i];
			}
			else if(dis[j]==dis[i]+1){
				pre[j]+=pre[i];
			}
		}
	}
	return ans;
}
int c,T;
void solve(){
	if(n==1||n==2){
		printf("0\n"); return ;
	}
	ll len=d/(a[2]-a[1]),ans=0;
	if(len>=n || len<2){
		printf("0\n"); return ;
	}
	for(int i=1;i<=n;++i){
		if(i+len+len-1 <= n) ++ans;
	}
	printf("%lld\n",ans);
}
void sol(){
	scanf("%d%lld",&n,&d);
	for(int i=1;i<=n;++i) scanf("%lld",&a[i]);
	if(c>=11){
		solve();
		return ;
	}
//	build(1,1,n);
	for(int i=1;i<=n;++i){
		int l=lower_bound(a+1,a+n+1,a[i]-d)-a;
		int r=upper_bound(a+1,a+n+1,a[i]+d)-a-1;
		R[i]=r,L[i]=l;
//		upd(1,1,n,l,r,pos[i]);
	}
	int ans=0;
	for(int i=1;i<=n;++i) ans+=fd(i);
	printf("%d\n",ans);
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&T);
	while(T--) sol();
	return 0;
}
/*

I couldn't go to WC. haha
In my 17 years,my last CSP is losing badly.
Thanks T3.You kill me.Maybe I couldn't forget you forever. 

*/
