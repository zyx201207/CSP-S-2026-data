// code by Umbrella.
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i,l,r) for(int i=(l);i<=(r);i++)
#define per(i,r,l) for(int i=(r);i>=(l);i--)
#define pii pair<int,int>
#define fir first
#define sec second
#define pb push_back
#define mkp make_pair
namespace Umbrella{
	const int inf=1e18;
	int c,n,m,d,q;
	int tot;
	int w[500005];
	vector<pii> e[500005];
	struct Que{
		int x,y,idx,ans;
	}qu[100005];
	int vis[500005],dis[500005];
	struct Node{
		int d,num;
		bool operator<(const Node& o)const {
			return d>o.d;
		}
	};
	void dij(int s,int L,int R){
		priority_queue<Node> pq;
		rep(i,1,m+tot){
			dis[i]=inf,vis[i]=0;
		}
		dis[s]=0;
		pq.push(Node{0,s});
		while(pq.size()){
			int u=pq.top().num; pq.pop();
			if(vis[u]) continue;
			vis[u]=1;
			for(auto [v,w1]:e[u]){
				if(vis[v]) continue;
				if(dis[u]+w1<dis[v]){
					dis[v]=dis[u]+w1;
					pq.push(Node{dis[v],v});
				}
			}
		}
		rep(i,L,R){
//			cout<<qu[i].y<<'\n';
//			cout<<dis[qu[i].y]<<'\n';
			qu[i].ans=dis[qu[i].y]+w[qu[i].x]+w[qu[i].y];
		}
	}
	void solve(){
		cin>>c>>n>>m>>d>>q;
		rep(i,1,m){
			cin>>w[i];
		}
		tot=m;
		rep(i,1,n){
			int K; cin>>K;
			rep(j,1,K){
				int a,t; cin>>a>>t;
				++tot;
				e[a].pb(mkp(tot,t));
				e[tot].pb(mkp(a,t));
				if(j>1){
					e[tot].pb(mkp(tot-1,0));
					e[tot-1].pb(mkp(tot,0));
				}
			}
		}
//		rep(i,1,m){
//			rep(j,0,(int)e[i].size()-1){
//				cout<<i<<' '<<e[i][j].fir<<' '<<e[i][j].sec<<'\n';
//			}
//		}
		rep(i,1,q){
			cin>>qu[i].x>>qu[i].y;
			qu[i].idx=i;
			if(qu[i].x>qu[i].y) swap(qu[i].x,qu[i].y);
//			cout<<qu[i].x<<' '<<qu[i].y<<'\n';
		}
		sort(qu+1,qu+q+1,[](Que u,Que v){
			if(u.x==v.x) return u.y<v.y;
			return u.x<v.x;
		});
		rep(i,1,q){
//			cout<<qu[i].x<<' '<<qu[i].y<<'\n';
			int s=qu[i].x;
			int R=i;
			rep(j,i+1,q){
				if(qu[j].x==s){
					R++;
				}
				else{
					break;
				}
			}
			dij(s,i,R);
			i=R;
		}
		sort(qu+1,qu+q+1,[](Que u,Que v){
			return u.idx<v.idx;	
		});
		rep(i,1,q){
			cout<<qu[i].ans<<'\n';
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int _T=1;
//	cin>>_T;
	while(_T--){
		Umbrella::solve();
	}
	return 0;
}
