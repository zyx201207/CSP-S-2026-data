#include <bits/stdc++.h>
using namespace std;

#define For(i,x,y,...) for(int i=(x),##__VA_ARGS__;i<=(y);i++)
#define foR(i,x,y,...) for(int i=(x),##__VA_ARGS__;i>=(y);i--)
#define Rep(i,x,y,...) for(int i=(x),##__VA_ARGS__;i<(y);i++)
typedef long long ll;
#define me(s,x) memset(s,x,sizeof s)
#define pb emplace_back
#define fi first
#define se second
#define PII pair<int,int>
#define endl '\n'

template<typename T=int>T read(){T x;cin>>x;return x;}
const int N=505,M=5e5+5,Q=1e5+5,M1=2e4+5;
ll w[N];
int c,n,m,d,que;
vector<int> e[N];
vector<pair<int,ll>> a[M];
bool vis[M];
ll dis[N][25],ans[Q];
vector<PII> x[M];
struct ques{
	int qx,qy;
}qq[N];
int t[M1][N],idx[M1][N],iddx[M1][25];
bool bk[N][25];
struct no{
	ll d;
	int idd,idx;
	bool fl;
	bool operator<(const no &y)const{
		return d>y.d;
	}
};
priority_queue<no> q;
void bfs(int s){
//	for(auto [id,t]:a[s]) q.push({0,id,s,1});
	Rep(i,0,a[s].size()) q.push({a[s][i].se,s,a[s][i].fi,1});
	For(i,1,m){
		For(j,1,d)dis[i][j]=0x3f3f3f3f3f3f3f3f;
	}
	For(i,1,n){
		dis[s][idx[s][i]]=t[s][i];
	}
	while(!q.empty()){
		auto [di,u,y,flg]=q.top();q.pop();
		if(bk[u][idx[u][y]]) continue;
		bk[u][idx[u][y]]=1;
		if(flg==1){
			for(auto v:e[y]){
				if(u==v) continue;
				if(dis[v][idx[v][y]]>di){
					dis[v][idx[v][y]]=di;
					q.push({di,v,y,0});
				}
			}
		}
		else{
			for(auto [id,tim]:a[u]){
				if(id==y) continue;
				if(dis[u][idx[u][id]]>di+tim+t[u][y]){
					q.push({di+tim+t[u][id],u,id,1});
					dis[u][idx[u][id]]=di+tim+t[u][y];
				}
			}
		}
	}
}
void MAIN(){
	cin>>c>>n>>m>>d>>que;
	For(i,1,m){
		cin>>w[i];
	}
	For(i,1,n,k){
		cin>>k;
		For(j,1,k,id){
			ll tim;
			cin>>id>>tim;
			a[id].pb(i,tim);
			t[id][i]=tim;
			idx[id][i]=a[id].size();
			iddx[id][a[id].size()]=i;
			e[i].pb(id);
		}
	}
	For(i,1,que){
		cin>>qq[i].qx>>qq[i].qy;
		x[qq[i].qx].pb(qq[i].qy,i);
		vis[qq[i].qx]=1;
	}
	For(i,1,m){
		if(vis[i]){
			bfs(i);
			for(auto [v,id]:x[i]){
				ll res=0x3f3f3f3f3f3f3f3f;
				For(j,1,d){
//					cout<<j<<" "<<dis[v][j]<<endl;
					res=min(res,dis[v][j]+t[v][iddx[v][j]]);
				}
//				cout<<dis[2][1]<<endl;
				ans[id]=res+w[i]+w[v];
			}
		}
	}
	For(i,1,que) cout<<ans[i]<<endl;
}signed main(){
	freopen("subway.in","r",stdin),freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int te=1;while(te--){
		MAIN();
	}
	return 0;
}
