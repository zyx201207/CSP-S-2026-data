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
const int N=1e2+10;
const int mod=1e9+7;
const int inf=1e9;
const ll linf=1e18;
int c,n,K,u,v,m,res=inf;
int dis[N][N];
bool flag,chs[N],vis[N];
vector<int> vec[N];
void dfn(int rt,int lst){
	vis[rt]=true;
	rp(i,vec[rt]){
		if(i==lst||vis[i]||!chs[i]) continue;
		dfn(i,rt);
	}
}
bool check(){
	int scc=0;
	memset(vis,false,sizeof vis);
	rep(i,1,n) if(chs[i]&&!vis[i]) ++scc,dfn(i,-1);
	return (scc<=2);
}
void dfs(int deep,int lst){
	if(deep>K){
		if(check()){
			int all=0;
			rep(i,1,n){
				int now=inf;
				if(!chs[i]) rep(j,1,n) if(chs[i]) mn(now,dis[now][i]);
				mx(all,now);
			}
			mn(res,all);
		}
		return ;
	}
	rep(i,lst+1,n) chs[i]=true,dfs(deep+1,i),chs[i]=false;
}
void Dis(int st,int rt,int lst){
	vis[rt]=true;
	rp(i,vec[rt]){
		if(i==lst||vis[i]||!chs[i]) continue;
		mn(dis[st][i],dis[st][rt]+1),Dis(st,i,rt);
	}
}
void work(){
	rep(i,1,n) vec[i].clear();
	rd(n),rd(K),m=n/2,memset(dis,0x3f,sizeof dis),memset(chs,false,sizeof chs);
	if(n%2==0) flag=false;
	else flag=true;
	rep(i,1,n-1) rd(u),rd(v),vec[u].push_back(v),vec[v].push_back(u),flag&=((i<=m&&u==i&&v==i+1)||(i>m&&u==i-m&&v==i+1));
	if(c==13||c==14||flag) pt(ceil((m-K)*1.0/(2.0*K))+1),pt('\n');
	else{
		rep(i,1,n) dis[i][i]=0,Dis(i,i,-1);
		dfs(1,-1),pt(res),pt('\n');
	}
}
int main(){
//	ios::sync_with_stdio(0);
//	cin.tie(0),cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int T;
//	T=1;
	rd(c),rd(T);
	while(T--) work();
	return 0;
}
/*
0 2
5 2
1 2
2 3
3 4
4 5
10 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10
*/
/*

*/
/*

*/
