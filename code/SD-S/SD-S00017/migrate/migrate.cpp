#include<bits/stdc++.h>
#define ll long long
#define F first
#define S second
#define pi pair<int,int>
#define ull unsigned long long
#define endl "\n"
#define int long long
using namespace std;
int n;
ull m;
ll _abs(ll a){
	if(a<0){
		return -a;
	}return a;
}
ll max(ll a,ll b){
	if(a>=b){
		return a;
	}return b;
}
const int N=5000,INF=1e9+10;
ll a[N];
struct node{
	int w,u;
};
vector<node> g[N];
int lu[N][N];
int dis[N][N];
bool vis[N];
void dj(int s){
	for(int i=1;i<=n;i++){
		dis[s][i]=INF;
	}
	dis[s][s]=0;
	priority_queue<pi,vector<pi>,greater<pi>> q;
	q.push({0,s});
	while(!q.empty()){
		pi f=q.top();
		q.pop();
		int uu=f.S;
		for(auto e:g[uu]){
			if(dis[s][e.u]>dis[s][uu]+e.w){
				dis[s][e.u]=dis[s][uu]+e.w;
				lu[s][e.u]=1;
				q.push({dis[s][e.u],e.u});
			}
			else if(dis[s][e.u]==dis[s][uu]+e.w){
				lu[s][e.u]++;
				q.push({dis[s][e.u],e.u});
			}
		}
	}return;
}
void solve1(){
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(abs((a[j]-a[i]))<=m){
				g[i].push_back({1,j});
			}
		}
	}
	for(int i=1;i<=n;i++){
		dj(i);
	}
//	cout<<lu[5][8]<<endl;
//	for(int i=1;i<=n;i++){
//		for(auto e:g[i]){
//			cout<<e.u<<' ';
//		}cout<<endl;
//	}
	int ans=0;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(lu[i][j]==2){
//				cout<<i<<' '<<j<<endl;
				ans++;
			}
//			lu[i][j]=0;
		}
	}
	cout<<ans<<endl;
	for(int i=1;i<=n;i++){
		g[i].clear();
	}
}
void solve(){
	cin>>n>>m;
//	cout<<n<<endl;
	for(int i=1;i<=n;i++){
		cin>>a[i]; 
	} 
    solve1();
}
signed main(){
//	system("fc migrate1.ans migrate.out");
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int c,t;
    cin>>c>>t;
	while(t--){
		solve();
	} 
	return 0;
}

