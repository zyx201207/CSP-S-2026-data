#include<bits/stdc++.h>
#define IOSO ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define endl '\n'
#define QwQ return 0;
#define int long long
using namespace std;
const int N=5e5+10;
int kou_ting[N];
struct node{
	int v,w;
	bool operator>(const node &o) const {
		return w>o.w;
	}
};
vector<node> g[N];
vector<int> g1[N];
int dis[1010][1010];
int n,m;
int minn=0x3f3f3f3f;
int tot[1010][1010];
int vis[1010][1010];
struct Node{
	int zh,xi,w;
	bool operator>(const Node &o) const {
		return w>o.w;
	}
};
inline void dij(int zt,int xian,int sum){
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			tot[i][j]=0x3f3f3f3f;
			vis[i][j]=0;
		}
	}
	priority_queue<Node,vector<Node>,greater<Node> > q;
	tot[zt][xian]=sum;
	q.push({zt,xian,sum});
	while(!q.empty()){
		Node u=q.top();
//		cout<<u.zh<<" "<<u.xi<<" "<<u.w<<endl;
		q.pop();
		if(vis[u.zh][u.xi]) continue;
		vis[u.zh][u.xi]=1;
		for(int xian1 : g1[u.zh]){
			for(node p : g[xian1]){
				int v=p.v;
//				cout<<xian1<<" "<<p.v<<endl;
				if(xian1==u.xi){
					if(tot[v][xian1]>tot[u.zh][u.xi]){
						q.push({v,xian1,tot[u.zh][u.xi]});
					}
				}else{
//					cout<<xian1<<" "<<p.v<<endl;
					int sum=dis[u.zh][u.xi]+dis[v][xian1];
//					cout<<sum<<" "<<tot[v][xian1]<<endl;
//					cout<<endl;
					if(tot[v][xian1]>tot[u.zh][u.xi]+sum){
						tot[v][xian1]=tot[u.zh][u.xi]+sum;
						q.push({v,xian1,tot[v][xian1]});
					}
				}
			}
		}
	}
}
signed main(){
	IOSO;
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>kou_ting[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int id,w;
			cin>>id>>w;
			dis[id][i]=w;
			g1[id].push_back(i);
			g[i].push_back({id,w});
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		int sum=kou_ting[x];
		int minn=0x3f3f3f3f;
		for(int xian : g1[x]){
			int sum1=sum+dis[x][xian];
			dij(x,xian,sum1);
			for(int xian1 : g1[y]){
				int ans=tot[y][xian1]+dis[y][xian]+kou_ting[y];
//				cout<<ans<<endl;
				minn=min(minn,ans);
			}
//			cout<<minn<<endl;
		}
		cout<<minn<<endl;
	}
	QwQ;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/