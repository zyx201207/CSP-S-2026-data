#include<bits/stdc++.h>
#define for1(i,x,y,k) for(int i=x;i<=y;i+=k)
#define for2(i,x,y,k) for(int i=x;i>=y;i-=k)
#define int long long
#define pb push_back
#define pf push_front
#define md (t[p].l+t[p].r>>1)
#define mi (lc+rc>>1)
#define mid (l+r>>1)
#define maotai mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define pii pair<int,int>
#define lmid (l+(r-l)/3)
#define rmid (l+(r-l)/3*2)
using namespace std;
const int N=15,INF=1e15;
int c,t,n,k,uu,vv,minx;
int dep[N],fa[N],dp[N];
bool sf[N];
vector<int>g[N];
void dfs(int u,int v){
	dep[u]=dep[v]+1;
	fa[u]=v;
	for(auto vi:g[u]){
		if(vi!=v)
			dfs(vi,u);
	}
}
int lca(int a,int b){
	while(dep[a]!=dep[b]){
		if(dep[a]<dep[b])
			swap(a,b);
		a=fa[a];
	}
	while(a!=b){
		a=fa[a];
		b=fa[b];
	}
	return a;
}
int suan(){
	int kl=0;
	memset(dp,0x3f,sizeof(dp));
	dfs(1,0);
	for1(i,1,n,1){
		if(sf[i]){
			dp[i]=0;
			for1(j,1,n,1){
				if(!sf[j])
					dp[j]=min(dp[j],dep[i]+dep[j]-2*dep[lca(i,j)]);
			}
		}
	}
	for1(i,1,n,1)
		kl=max(kl,dp[i]);
	return kl;
}
void init(){
	for1(i,1,n,1)
		g[i].clear();
}
void sol(){
		for1(i,2,n,1){
			cin>>uu>>vv;
			g[uu].pb(vv);
			g[vv].pb(uu);
		}
		for1(i,0,(1<<n)-1,1){
			int op=0,al=0;
			memset(sf,false,sizeof(sf));
			memset(dep,0,sizeof(dep));
			memset(fa,0,sizeof(fa));
			for1(j,1,n,1){
				if((i>>j-1)&1){
					op++;
					sf[j]=true;
					bool _=false;
					for(auto vi:g[j]){
						if(sf[vi]){
							_=true;
							break;
						}
					}
					if(!_)
						al++;
				}
			}
			if(op==k && al==2){
//				for1(j,1,n,1)
//					cout<<sf[j]<<" ";
//				cout<<'\n';
//				cout<<suan()<<" ";
				minx=min(minx,suan());
			}
//			cout<<'\n'<<'\n';
		}
		cout<<minx<<'\n';
}
int sun(int x){
//	cout<<x<<'\n';
//	cout<<(n+1)/2-x-k+2<<" "<<(x-(x+1)/3)/2+1<<" "<<(x+1)/3<<'\n';
	return max({1ll,(n+1)/2-x-k+2,(x-(x+1)/3)/2+1,(x+1)/3});
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		minx=INF;
		cin>>n>>k;
		if(n<=10){
			init();
			sol();
			continue;
		}
		for1(i,2,n,1){
			cin>>uu>>vv;
		}
		if(n==3 || n==5 || k>n/2){
			cout<<1<<'\n';
			continue;
		}
		int l=3,r=(n+1)/2-k+2,anss=INF;
//		for1(i,l,r,1)sun(i);
//			cout<<sun(i)<<" ";
		while(l+10<r){
			if(sun(lmid)<sun(rmid))
				l=lmid;
			else
				r=rmid;
		}
		for1(i,l,r,1)
			anss=min(anss,sun(i));
		cout<<anss<<'\n';
	}
	return 0;
}
/*
0 1
15 4
1 2
2 3
3 4
4 5
5 6
6 7
7 8
7 9
6 10
5 11
4 12
3 13
2 14
1 15
*/
