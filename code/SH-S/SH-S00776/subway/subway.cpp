#include<bits/stdc++.h>
typedef long long ll;
typedef std::pair<int,ll> pil;
using std::cin;
using std::cout;
constexpr int N=509,M=5e5+9;
constexpr ll INF=1e16;
template<typename T>
inline void chkmin(T&a,const T b){
	a=std::min(a,b);
}
ll w[N][N];
int c,n,m,d,q,k[N];
ll cst[M];
std::vector<pil>lines[M];
void cal(){
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(w[i][j]>w[i][k]+w[k][j])w[i][j]=w[i][k]+w[k][j];
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>cst[i];
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)w[i][j]=INF;
	for(int i=1;i<=n;i++)w[i][i]=0;
	for(int i=1;i<=n;i++){
		cin>>k[i];
		int a;ll t;
		for(int _=1;_<=k[i];_++){
			cin>>a>>t;
			for(pil&u:lines[a]){
				if(w[i][u.first]>u.second+t){
					w[u.first][i]=w[i][u.first]=u.second+t;
				}
			}
			lines[a].push_back({i,t});
		}
	}
	cal();
	ll ans;
	for(int _=1,x,y;_<=q;_++){
		cin>>x>>y;ans=INF;
		for(pil&u:lines[x])for(pil&v:lines[y]){
			chkmin(ans,w[u.first][v.first]+u.second+v.second);
		}
		cout<<ans+cst[x]+cst[y]<<'\n';
	}
	return 0;
}

// TIME: O(n^3+K*d+q*d^2)
// 100pts!!!