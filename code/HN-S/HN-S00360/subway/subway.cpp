#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define endl '\n'
using namespace std;
constexpr int mod=998244353;
inline int MOD(int a){return (a%mod+mod)%mod;}
inline int add(int a,int b){return (a+b)%mod;}
inline int red(int a,int b){return (a-b+mod)%mod;}
inline int mul(int a,int b){return a*b%mod;}
constexpr int N=500+5,M=5e5+5;
int c,n,m,d,q,W[M];
ll f[N][N];
struct edge{int v,w;};
vector<edge>ft[M];
void solve(){
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>W[i];
	for(int i=1;i<=n;i++){
		int len;
		cin>>len;
		for(int j=1;j<=len;j++){
			int u,w;
			cin>>u>>w;
			ft[u].push_back({i,w});
		}
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(i==j)f[i][j]=0;
			else f[i][j]=1e18;
	for(int qt=1;qt<=m;qt++){
		int sum=ft[qt].size();
		for(int i=0;i<sum;i++){
			int u=ft[qt][i].v,w_u=ft[qt][i].w;
			for(int j=i+1;j<sum;j++){
				int v=ft[qt][j].v,w_v=ft[qt][j].w;
				f[u][v]=min(f[u][v],(ll)w_u+(ll)w_v);
				f[v][u]=min(f[v][u],(ll)w_u+(ll)w_v);
			}
		}
	}
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		int sum_x=ft[x].size(),sum_y=ft[y].size();
		ll mn=1e18;
		for(int i=0;i<sum_x;i++){
			int u=ft[x][i].v,w_u=ft[x][i].w;
			for(int j=0;j<sum_y;j++){
				int v=ft[y][j].v,w_v=ft[y][j].w;
				mn=min(mn,f[u][v]+(ll)w_u+(ll)w_v);
			}
		}
		cout<<mn+(ll)W[x]+(ll)W[y]<<endl;
	}
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--)solve();
	return 0;
}
