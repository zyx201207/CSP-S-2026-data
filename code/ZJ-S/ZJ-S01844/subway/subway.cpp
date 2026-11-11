#include<bits/stdc++.h>
#define rd(x) cin>>x
#define pt(x) cout<<x
#define rep(i,x,y) for(ll (i)=(x);(i)<=(y);++i)
#define down(i,x,y) for(ll (i)=(x);(i)>=(y);--i)
#define rp(i,p) for(auto i:p)
#define mx(x,y) x=max(x,y)
#define mn(x,y) x=min(x,y)
using namespace std;
typedef long long ll;
const int N=1.5e6+10;
const int M=5e5+10;
const int D=5e2+10;
const int mod=1e9+7;
const int inf=1e9;
const ll linf=1e18;
ll c,n,m,d,Q,sum;
ll u,v,tim,tot,K,lst;
ll dis[N],res[M];

bool mp[D][D];
ll num[M],dp[D][D];
vector<ll> List[M],vec2[D];
struct Edge{
	ll to,len;
};
bool operator < (const Edge &x,const Edge &y){
	return x.len<y.len;
}
vector<Edge> vec[N];
struct Que{
	ll u,v,id;
}q[M];
void dij(ll st){
	memset(dis,0x3f,sizeof dis),dis[st]=0;
	priority_queue<Edge> pq;
	pq.push({st,0});
	while(!pq.empty()){
		Edge top=pq.top();
		ll id=top.to,w=top.len;
		pq.pop();
		rp(i,vec[id]){
			ll nxt=i.to;
			if(dis[nxt]>w+i.len) dis[nxt]=w+i.len,pq.push({nxt,dis[nxt]});
		}
	}
}
bool cmp(Que x,Que y){
	return x.u<y.u;
}
void parts(){
//	pt("-1"),pt('\n');
	memset(mp,false,sizeof mp),memset(dp,0x3f,sizeof dp);
	rep(i,1,m) rd(num[i]);
	rep(i,1,n){
		rd(K);
		rep(j,1,K){
			rd(u),rd(v),tim=v,List[u].push_back(i);
//			pt(u),pt(' ');
		}
//		pt('\n');
	}
//	rep(i,1,m){
//		pt("#"),pt(i),pt('\n');
//		rp(j,List[i]) pt(j),pt(' ');
//		pt('\n');
//	}
	rep(i,1,m) rp(j,List[i]) rp(k,List[i]) if(j!=k&&!mp[j][k]) vec2[j].push_back(k),vec2[k].push_back(j),mp[j][k]=mp[k][j]=true;
//	rep(i,1,n){
//		rep(j,1,n) pt(int(i==j||mp[i][j]));
//		pt('\n');
//	}
	priority_queue<Edge> pq;
	rep(i,1,n){
		dp[i][i]=0,pq.push({i,0});
		while(!pq.empty()){
			Edge top=pq.top();
			ll id=top.to,w=top.len;
			pq.pop();
//			pt(id),pt(' '),pt(w),pt('\n');
			rp(j,vec2[id]){
//				pt(j),pt(' '),pt(dp[i][j]),pt(' '),pt(w+2*tim),pt('\n');
				if(dp[i][j]>w+2*tim) dp[i][j]=w+2*tim,pq.push({j,dp[i][j]});
			}
		}	
	}
//	rep(i,1,n) rep(j,1,n) if(dp[i][j]<10000) pt(i),pt(' '),pt(j),pt(' '),pt(dp[i][j]),pt('\n');
	rep(i,1,Q){
		rd(u),rd(v);
		ll res=linf;
		rp(j,List[u]) rp(k,List[v]) mn(res,dp[j][k]);
		pt(res+num[u]+num[v]+2*tim),pt('\n');
	}
}
void work(){
	rd(c),rd(n),rd(m),rd(d),rd(Q);
	if(c>=12&&c<=19) return parts();
	rep(i,1,m) rd(u),vec[i].push_back({i+m,u}),vec[i+m].push_back({i,u}),sum+=2;
	tot=m<<1;
	rep(i,1,n){
		rd(K),lst=0;
		rep(j,1,K){
			rd(u),rd(v),vec[u+m].push_back({++tot,v}),vec[tot].push_back({u+m,v}),sum+=2;
			if(lst) vec[tot].push_back({lst,0}),vec[lst].push_back({tot,0}),sum+=2;
			lst=tot;
		}
	}
//	pt(tot),pt(' '),pt(sum),pt(' '),pt(Q*(tot+sum)*log2(tot+sum));
//	rep(i,1,tot){
//		pt("#"),pt(i),pt(":\n");
//		rp(j,vec[i]) pt(j.to),pt(' '),pt(j.len),pt('\n');
//		pt('\n');
//	} 
	rep(i,1,Q) rd(q[i].u),rd(q[i].v),q[i].id=i;
	sort(q+1,q+1+Q,cmp);
//	rep(i,1,Q) pt(q[i].u),pt(' '),pt(q[i].v),pt('\n');
	rep(i,1,Q){
		if(q[i].u==q[i-1].u) res[q[i].id]=dis[q[i].v];
		else dij(q[i].u),res[q[i].id]=dis[q[i].v];
	}
	rep(i,1,Q) pt(res[i]),pt('\n');
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int T;
	T=1;
//	rd(T);
	while(T--) work();
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
/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/
/*
12 3 7 20 2
8 3 6 1 7 2 9
3 1 5 2 5 5 5
3 2 5 3 5 7 5
4 3 5 5 5 4 5 6 5
1 6
2 3


25
*/
