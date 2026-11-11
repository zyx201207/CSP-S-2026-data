#include<bits/stdc++.h> 
using namespace std;
#define ll long long
const int N = 5e5+10;
int c,n,m,d,q,cnt = 0,res = 0;
int w[N],fa[N],dis[N],vis[N],vis2[N];
struct node{
	int to,next;
	int co;
}a[N];
int pre[N];
void add(int u,int v,int t){
	cnt++;
	a[cnt].to = v;
	a[cnt].co = t;
	a[cnt].next = pre[u];
	pre[u] = cnt;
}
struct edge{
	int to,next;
	int ti; 
}b[N];
int pre2[N];
void add2(int u,int v,int c){
	res++;
	b[res].to = v;
	b[res].ti = c;
	b[res].next = pre2[u];
	pre2[u] = res;
}
int dij(int st,int ed){
	memset(dis,0x3f3f3f3f,sizeof(dis));
	memset(vis,0,sizeof(vis));
	memset(vis2,0,sizeof(vis));
	priority_queue<pair<int,int>,vector<pair<int,int> > ,greater<pair<int,int> > > pq;
	pq.push({0,st});
	dis[st] = 0;
	while(pq.size()>0){
		auto top = pq.top();
		int v = top.first;
		int u = top.second;
		pq.pop();
		if(vis[u] == 1) continue;
		vis[u] = 1;
		for(int i=pre2[u];i!=0;i=b[i].next){
			int g = b[i].to,w = b[i].ti;
			if(vis2[g] == 1) continue;
			vis2[g] = 1;
			for(int j=pre[g];j!=0;j=a[j].next){
				int to = a[j].to,co = a[j].co;
				if(to == u) continue;
				if(to == ed){
					dis[to] = min(dis[to],w+v+co);
					break;
				}
				else if(fa[to] > 1 && dis[to] > w + v + a[i].co){
					dis[to] = w+v+co;
					pq.push({dis[to],to});
				}
			}
		}
	}
	return dis[ed];
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int x,t;
			cin>>x>>t;
			fa[x]++;
			add(i,x,t);
			add2(x,i,t);
			
		}
	}
	while(q--){
		int l,r;
		cin>>l>>r;
		cout<<w[l]+dij(l,r)+w[r]<<'\n';
	}
	return 0;
}
/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3

*/
