#include <bits/stdc++.h>
#define ll long long
#define vec vector
#define sca scanf
#define pri printf
#define pll pair<long long,long long>
#define to second
#define val first
using namespace std;
const int N=5e2+10;
const int M=5e5+100;
ll c,n,m,d,q,st,ed,ans;
ll w[M];
pll tem[M];
vec<pll>G[N];//l to l
vec<pll>ptol[M];//p to l
int psuml[M];//each p`s sum line
ll dis[N][N];//each line `s dis
priority_queue<pll,vec<pll >,greater<pll > >pq;
bool vis[M];
void dijk(int s){
	pq.push({0,s});
	dis[s][s]=0;
	memset(vis,false,sizeof(vis));
//	pri("dijk %d:\n",s);
	while(!pq.empty()){
		pll hd=pq.top();
		pq.pop();
//		pri(" get{to=%lld,val=%lld}\n",hd.to,hd.val);
		if(!vis[hd.to]){
			dis[s][hd.to]=hd.val;
			vis[hd.to]=true;
		}else continue;
		for(auto nex:G[hd.to]){
			pq.push({dis[s][hd.to]+nex.val,nex.to});
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	sca("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++)sca("%lld",&w[i]);
	ll kz,az,tz;
	for(int i=1;i<=n;i++){//build p to l
		sca("%lld",&kz);
		for(int j=1;j<=kz;j++){
			sca("%lld%lld",&az,&tz);
			ptol[az].push_back({tz,i});
//			pri("ptol[%lld] add{%lld,%lld}\n",az,tz,i);
			psuml[az]++;
		}
	}
	for(int p=1;p<=m;p++){//build l to l from each p
		for(auto l1:ptol[p]){
			for(auto l2:ptol[p]){
				if(l1==l2)continue;
//				pri("build line[%d]-line[%d]\n",l1.to,l2.to);
				G[l1.to].push_back({l1.val+l2.val,l2.to});
			}
		}
	}
//	for(int i=1;i<=n;i++){
//		for(auto p:G[i]){
//			pri("%lld,%lld ",p.to,p.val);
//		}
//		pri("\n");
//	}
	//1e8!!!!!!
	for(int i=1;i<=n;i++){
		dijk(i);
	}
//	for(int i=1;i<=m;i++){
//		for(int j=1;j<=m;j++){
//			pri("%lld ",dis[i][j]);
//		}
//		pri("\n");
//	}
	while(q--){
		ans=LONG_LONG_MAX;
		sca("%lld%lld",&st,&ed);
		if(st>ed)swap(st,ed);
		for(auto i:ptol[st]){
			for(auto j:ptol[ed]){
				ans=min(ans,dis[i.to][j.to]+i.val+j.val);
			}
		}
		pri("%lld\n",ans+w[st]+w[ed]);
	}
	
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/