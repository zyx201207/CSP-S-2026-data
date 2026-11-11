#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int M=2e5+5;
const int N=500;
ll c,n,m,d,q,w[M],k[N],a[N][N],t[N][N];
//struct node{
//	ll xian,shu,id;
//}ls[N],rs[N];
//ll vis[N],ans,cnt;
//void dfs(ll u,ll e,ll xian,ll wh){
//	if(u==e){
//		ans=min(ans,cnt);
//		return ;
//	}
//	if(wh==0) cnt+=ls[u].shu;
//	if(wh==1) cnt+=rs[u].shu;
//	if(a[ls[u].xian][ls[u].id+1]!=0){
//		cnt+=
//		dfs(a[ls[u].xian][ls[u].id+1],e,ls[u].xian,0);
//	}
//	
//	if(a[rs[u].xian][rs[u].id+1]!=0) dfs(a[rs[u].xian][rs[u].id+1],e,rs[u].xian,0);
//}
struct node{
	ll nxt,to;
}g[N];
ll head[N],tot,ans,cnt,vis[N];
void add(ll u,ll v){
	g[++tot].to=v;
	g[tot].nxt=head[u];
	head[u]=tot;
}
void dfs(ll l,ll r){
	ll u=l;
	if(l==r){
		ans=min(ans,cnt);
		return ;
	}
	for(int i=head[u];i;i=g[i].nxt){
		ll v=g[i].to;
		if(vis[v]) continue;
		cnt++;
		
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++) scanf("%lld",w+i);
//	if((c>=7&&c<=11)||(c==22||c==23)){
//		for(int i=1;i<=n;i++){
//			scanf("%lld",k+i);
//			for(int j=1;j<=k[i];j++){
//				scanf("%lld%lld",&a[i][j],&t[i][j]);
//				if(ls[a[i][j]].xian==0){
//					ls[a[i][j]].xian=i;
//					ls[a[i][j]].shu=t[i][j];
//					ls[a[i][j]].id=j;
//				}
//				else{
//					rs[a[i][j]].xian=i;
//					rs[a[i][j]].shu=t[i][j];
//					rs[a[i][j]].id=j;
//				}
//			}
//		}
//		while(q--){
//			ll l,r;
//			scanf("%lld%lld",&l,&r);
//			vis[l]=1;
//			dfs(l,r,ls[l].xian,0);
//			if(rs[l].xian) dfs(l,r,rs[l].xian,1);
//			ans+=w[l];
//			ans+=w[r];
//			printf("%lld",ans);
//		}
//	}
	if(c>=12&&c<=15){
		for(int i=1;i<=n;i++){
			scanf("%lld",k+i);
			for(int j=1;j<=k[i];j++){
				scanf("%lld%lld",&a[i][j],&t[i][j]);
				if(j!=1) add(a[i][j-1],a[i][j]);
			}
		}
		ll T=t[1][1];
		while(q--){
			ll l,r;
			scanf("%lld%lld",&l,&r);
			dfs(l,r);
			ans+=w[l];
			ans+=w[r];
			printf("%lld",ans);
		}
	}
	return 0;
}
