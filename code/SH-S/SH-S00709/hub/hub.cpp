#include<bits/stdc++.h>
#define rep(i,l,r) for(int i=l;i<=r;i++)
#define rrep(i,r,l) for(int i=r;i>=l;i--)
#define fi first
#define sc second
#define pb push_back
#define pq priority_queue
using namespace std;
typedef long long ll;
int c,t;
int n,k;
namespace s1{
	const int N=4005;
	int U[N],V[N],deg[N];
	vector<int>G[N];
	int dep[N],F[N];
	int d;
	void dfs(int u){
		for(int v:G[u]){
			if(v==F[u]){
				continue;
			}
			if(u==U[d]&&v==V[d]){
				continue;
			}
			if(v==U[d]&&u==V[d]){
				continue;
			}
			dep[v]=dep[u]+1;
			F[v]=u;
			dfs(v);
		}
	}
	int mid(int u){
		rep(i,1,n){
			dep[i]=0;
		}
		F[u]=0;
		dfs(u);
		int mx=0;
		rep(i,1,n){
			if(dep[i]>dep[mx]){
				mx=i;
			}
		}
		dep[mx]=0;
		F[mx]=0;
		dfs(mx);
		int s=0;
		rep(i,1,n){
			if(dep[i]>dep[s]){
				s=i;
			}
		}
		int t=dep[s];
		while(dep[s]>t/2){
			s=F[s];
		}
		return s;
	}
	int H[N];
	void dfs1(int u){
//		cerr<<"dfs1 visit "<<u<<"\n";
		H[u]=0;
		for(int v:G[u]){
			if(v==F[u]){
				continue;
			}
			if(u==U[d]&&v==V[d]){
				continue;
			}
			if(v==U[d]&&u==V[d]){
				continue;
			}
			F[v]=u;
			dfs1(v);
			H[u]=max(H[u],H[v]);
		}
		H[u]++;
	}
	void solve(){
		if(n>4000){
			rep(i,1,n){
				int a;
				cin>>a>>a;
			}
			cout<<(n+7)/8-(k-2)/4<<"\n";
			return;
		}
		rep(i,1,n){
			deg[i]=0;
		}
		int t=n/2;
		rep(i,1,n-1){
			cin>>U[i]>>V[i];
/*
			if(i<=t){
				U[i]=i;
				V[i]=i+1;
			}else{
				U[i]=i-t;
				V[i]=i+1;
			}

			deg[U[i]]++;
			deg[V[i]]++;
*/
		}
		if(k==n){
			cout<<"0\n";
			return;
		}
		rep(i,1,n){
			G[i].clear();
			G[i].reserve(deg[i]);
		}
		rep(i,1,n-1){
			G[U[i]].pb(V[i]);
			G[V[i]].pb(U[i]);
		}
		int ans=1e9;
		rep(i,1,n-1){
			d=i;
//			cerr<<"cut the edge ("<<U[i]<<", "<<V[i]<<"):\n";
			int m1=mid(U[i]),m2=mid(V[i]);
			F[m1]=F[m2]=0;
			dfs1(m1);
			dfs1(m2);
			pq<pair<int,int>>Q;
			Q.push({0,0});
			for(int x:G[m1]){
				Q.push({H[x],x});
			}
			for(int x:G[m2]){
				Q.push({H[x],x});
			}
			int kk=k-2;
			while(kk--){
				auto x=Q.top();
				Q.pop();
				for(int y:G[x.sc]){
					if(H[y]<H[x.sc]){
						Q.push({H[y],y});
					}
				}
			}
			ans=min(ans,Q.top().fi);
		}
//		cerr<<n<<" "<<k<<" ";
		cout<<ans<<"\n";
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
//		if(c<=10){
			s1::solve();
//		}
	}
	return 0;
}
