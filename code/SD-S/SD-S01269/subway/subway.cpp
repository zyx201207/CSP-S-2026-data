#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define lowbit(x) ((x)&(-x))
using namespace std;
template<typename T>inline void read(T &n);
const int M=5e5+5;
const int N=505;
const ll INF=1e18;
struct node{
	int id;//线路编号、站厅站台时间 
	ll t;
};
ll w[M];
vector<node>b[M];//第i个地铁站被哪些线路经过以及走路时间 
ll dis[N][N];
//期望得分84分 
int main(){
	ios::sync_with_stdio(0);
//	freopen("debug.in","r",stdin);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int C,n,m,d,q;
	read(C),read(n),read(m),read(d),read(q);
	for (int i=1;i<=m;i++) read(w[i]);
	for (int i=1,k;i<=n;i++){
		read(k);
		for (int j=1,pos,t;j<=k;j++){
			read(pos),read(t);
			b[pos].push_back({i,t});
		}
	}
	for (int i=1;i<=n;i++){//floyd预处理 
		for (int j=1;j<=n;j++){
			if (i==j) continue;
			dis[i][j]=INF;
		}
	}
	//预处理每个地铁站，求出换乘代价 
	//时间复杂度瓶颈 
	for (int i=1;i<=m;i++){//O(m*d^2)
		for (auto x:b[i]){
			for (auto y:b[i]){
				if (x.id==y.id) continue;
				int u=x.id,v=y.id;
				dis[u][v]=min(dis[u][v],x.t+y.t);
			}
		}
	}
	for (int k=1;k<=n;k++){//floyd全源最短路 
		for (int i=1;i<=n;i++){
			for (int j=1;j<=n;j++){
				if (dis[i][k]==INF || dis[k][i]==INF) continue;
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	for (int x,y;q;q--){//处理询问 
		ll ans=INF;
		read(x),read(y);
		for (auto st:b[x]){//选择从第st个线路开始到ed线路结束 
			for (auto ed:b[y]){
				ans=min(ans,w[x]+w[y]+st.t+ed.t+dis[st.id][ed.id]);
			}
		}
		cout<<ans<<'\n';
	}
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

