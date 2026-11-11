#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define lowbit(x) ((x)&(-x))
using namespace std;
template<typename T>inline void read(T &n);
const int N=5005,INF=1e9;
int C;
ll x[N];
vector<int>e[N];
int dis[N],cnt[N];//最短路径和最短路数量 
bitset<N>vis;
queue<int>q;
//40分暴力建边+bfs 
//不需要往回走，因为这样显然不是最短路 
inline void solve(){
	int n;
	ll d; 
	read(n),read(d);
	for (int i=1;i<=n;i++) read(x[i]);
	for (int i=1;i<=n;i++){
		for (int j=1;j<i;j++){
			if (x[i]-x[j]<=d){//O(n^2)反向建边 
				e[i].push_back(j);
			}
		}
	}
	ll ans=0;
	for (int u=1;u<=n;u++){//对于每一个i,求出在此之前的路径数量 
		for (int i=1;i<=n;i++) dis[i]=INF,cnt[i]=0; 
		dis[u]=0;
		cnt[u]=1;
		q.push(u);
		while (!q.empty()){
			int x=q.front();
			q.pop();
			vis[x]=1;
			for (auto y:e[x]){
				if (dis[y]==dis[x]+1){
					cnt[y]+=cnt[x];
				}else if (dis[y]==INF){
					dis[y]=dis[x]+1;
					cnt[y]=cnt[x];
					q.push(y);
				}
			}
		}
		for (int i=1;i<u;i++){
			if (cnt[i]==2){
//				cout<<i<<" "<<u<<" "<<dis[i]<<" "<<"\n";
				ans++;
			}
		}
	}
	cout<<ans<<'\n';
	for (int i=1;i<=n;i++) e[i].clear();
}
int main(){
	ios::sync_with_stdio(0);
//	freopen("debug.in","r",stdin);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int T;
	read(C),read(T);
	while (T--) solve();
	
	return 0;
}
template<typename T>inline void read(T &n){
	n=0;T f=1;
	char c;
	do{
		c=getchar();
		if (c=='-') f=-1;
	}while (c<'0'||c>'9');
	while (c>='0'&&c<='9'){
		n=(n<<1)+(n<<3)+(c^48);
		c=getchar();
	}
	n*=f;
}

