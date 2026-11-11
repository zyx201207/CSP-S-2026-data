//袁浩文 西安辅轮中学 SN-S00416
#include <bits/stdc++.h>
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
#define elif else if
#define pii pair<int,int>
#define lowbit(x) (x&-x)
#define fi first
#define se second
#define setdigit(x) cout<<fixed<<setprecision(x)
#define debug(...) fprintf(stderr,##__VA_ARGS__)
using namespace std;
const int maxn=5e5+5;
int c,n,m,d,q,tot=1,hd[maxn];
struct node{int to,nxt,w;}edge[maxn];
pii Q[100005];
void add(int u,int v,int w){edge[++tot]={v,hd[u],w},hd[u]=tot;}
struct node1{
	int id,dis;
	operator<(const node1&a)const{return a.dis>dis;}
};
vector<int>dis(maxn,inf);
void dijkstra(int s){
	priority_queue<node1>q;
	q.push({s,0});
	dis[s]=0;
	vector<int>dis(maxn,inf);
	while(!q.empty()){
		node1 cnt=q.top();q.pop();
		int u=cnt.id,ww=cnt.dis;
		for(int i=hd[u];i;i=edge[i].nxt){
			int v=edge[i].to,w=edge[i].w;
			if(dis[v]>dis[u]+w){
				dis[v]=dis[u]+w;
				q.push({v,dis[v]});
			}
		}
	}
}
//***我连dij都不会写了
void solve(){
	cin>>c>>n>>m>>d>>q;
	for(int i=1,w;i<=m;i++){
		cin>>w;
		add(i,i+m,w);
		add(i+m,i,w);//站到厅
	}
	for(int i=1,a,k;i<=n;i++){
		cin>>k;
		for(int j=1,t;j<=k;j++){
			cin>>a>>t;
			add(a+m,i+2*m,t);
			add(i+2*m,a+m,t);//厅到台
		}
	}
	for(int i=1,x,y;i<=q;i++){
		cin>>x>>y;
		if(x>y)swap(x,y);
		Q[i]={x,y};
	}
	sort(Q+1,Q+q+1);
	for(int i=1;i<=q;i++){
		if(Q[i].fi==Q[i-1].fi)cout<<dis[Q[i].se]<<"\n";
		else{
			for(int i=0;i<maxn;i++)dis[i]=inf;
			dijkstra(Q[i].fi);
			cout<<dis[Q[i].se]<<"\n";
		}
	}
}
signed main(){
	string filename="subway";
	freopen((filename+".in").c_str(),"r",stdin),freopen((filename+".out").c_str(),"w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int Case=1;
//	cin>>Case;
	while(Case--)solve();
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/
