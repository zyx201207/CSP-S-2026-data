#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
#define rep(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
#define down(i,a,b) for(int (i)=(a);(i)>=(b);(i)--)
void file(){
	 freopen("migrate.in","r",stdin);
	 freopen("migrate.out","w",stdout);
}
const ll INF=1e15;
const ld ERR=0.000000000001;
const ll N=5009;
// 多测不清空，爆零两行泪
ll n,d,x[N];
ll hd[N];
struct Edge{
	ll to,nxt;
}e[N*N*2];
ll nE=0;
void addedge(ll u,ll v){
	e[++nE]=(Edge){v,hd[u]};
	hd[u]=nE;
}
void init(){
	rep(i,1,n)hd[i]=0;
	nE=0;
} 
void input(){
	cin>>n>>d;
	rep(i,1,n)cin>>x[i];
}
ll dst[N][N],cnt[N][N];
void bfs(ll st){
	rep(i,1,n)dst[st][i]=INF,cnt[st][i]=0;
	dst[st][st]=0; cnt[st][st]=1;
	queue<ll> q;
	q.push(st);
	while(!q.empty()){
		ll u=q.front(); q.pop();
		for(ll i=hd[u];i;i=e[i].nxt){
			ll v=e[i].to;
			if(dst[st][v]==INF){
				dst[st][v]=dst[st][u]+1;
				cnt[st][v]=cnt[st][u];
				q.push(v);
			}
			else if(dst[st][v]==dst[st][u]+1)cnt[st][v]+=cnt[st][u];
		}
	}
}
void solveBF(){
	rep(i,1,n)
		rep(j,i+1,n){
			if(abs(x[i]-x[j])<=d){
				addedge(i,j);
				addedge(j,i);
//				cout<<i<<" "<<j<<endl;
			}
		}
	rep(i,1,n)bfs(i);
	ll ans=0;
//	rep(i,1,n){
//		rep(j,1,n)cout<<dst[i][j]<<" ";
//		cout<<endl;
//	}
//	rep(i,1,n){
//		rep(j,1,n)cout<<cnt[i][j]<<" ";
//		cout<<endl;
//	}
	rep(i,1,n){
		rep(j,i+1,n){
			if(cnt[i][j]==2)ans++;
		}
	}
	cout<<ans<<endl;
}
ll c,T;
int main(){
	file();
	cin>>c>>T;
	rep(i,1,T){
		init();
		input();
		solveBF();
	}
	return 0;
}

