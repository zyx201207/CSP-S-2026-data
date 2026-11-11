#include<bits/stdc++.h>
#define ll long long
#define pii pair<ll,ll>

using namespace std;

const ll N=555,M=5e5+12;
int c,n,m,d,q;
ll w[M],k[N];
//vector<ll> a[N],t[N];
vector<pii > D[M];

ll f[N][N];
inline void add(ll u,ll v,ll ww) {
	f[u][v]=min(f[u][v],ww);
}

int main() {
	
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	
	memset(f,0x3f,sizeof f);
		
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;++i) {
		cin>>w[i];
	}
	for(int i=1;i<=n;++i) {
		cin>>k[i];
		for(int j=1;j<=k[i];++j) {
			ll A,T; cin>>A>>T;
//			a[i].push_back(A),t[i].push_back(T);
			pii LS;
			LS.first=i,LS.second=T;
			D[A].push_back(LS);
		}
	}
	
	for(int i=1;i<=m;++i) {
		
		for(int j=0;j<D[i].size();++j) {
			for(int k=j+1;k<D[i].size();++k) {
				
				ll u=D[i][j].first,v=D[i][k].first;
				add(u,v,D[i][j].second+D[i][k].second);
				add(v,u,D[i][j].second+D[i][k].second);
				
			}
		}
		
	}
		
	for(int i=1;i<=n;++i) f[i][i]=0ll;
	for(int k=1;k<=n;++k) {
		for(int i=1;i<=n;++i) {
			for(int j=1;j<=n;++j) {
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
			}
		}
	}
	
	while(q--) {
		
		ll st,ed;
		cin>>st>>ed;
		
		ll res=-1;
		for(int i=0;i<D[st].size();++i) {
			for(int j=0;j<D[ed].size();++j) {
				
				ll U=D[st][i].first,V=D[ed][j].first;
				if(res==-1) res=D[st][i].second+D[ed][j].second+f[U][V]+w[st]+w[ed];
				else res=min(res,D[st][i].second+D[ed][j].second+f[U][V]+w[st]+w[ed]); 
				
			}
		}
		
		cout<<res<<'\n'; 
		
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

32
17


0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3

35
16




*/