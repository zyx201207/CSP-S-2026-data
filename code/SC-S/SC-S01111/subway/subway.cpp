#include<bits/stdc++.h>
#define int long long
using namespace std;
/*
首先

暴力建图对于每次询问都跑一遍 dij 

肯定是类似 O(1) 求解每次询问，我需要聪明一点的算贡献方式

可以考虑 O(n) 算答案，所以我需要对每一个线路都求一边最短路


*/
const int N=1e6+50,inf=1e18;
bool MS;
struct p{
	int to,nxt,w;
}e[N];
struct pp{
	int s,t;
}qq[N];
int idx,head[N];
void add(int u,int v,int w){
	e[++idx].to=u;
	e[idx].w=w;
	e[idx].nxt=head[v];
	head[v]=idx;
}
int d[505][150000],tot;
bool MT;
#define pii pair<int,int>
int n,m;
void dij(int s){
	for(int i=0;i<=tot;i++) d[s-m][i]=inf;
	priority_queue<pii,vector<pii>,greater<pii> > q;
	d[s-m][s]=0;
	q.push({0,s});
	while(!q.empty()){
		auto x=q.top();
		q.pop();
		int u=x.second;
		if(d[s-m][u] > x.first) continue;
		for(int i=head[u];i;i=e[i].nxt){
			int v=e[i].to;
			if(d[s-m][v] > d[s-m][u]+e[i].w){
				d[s-m][v]=d[s-m][u]+e[i].w;
				q.push({d[s-m][v],v});
			}
		}
	}
}
unordered_map<int,int> d2[505];
void dij2(int s){
	for(int i=0;i<=tot;i++) d2[s-m][i]=inf;
	priority_queue<pii,vector<pii>,greater<pii> > q;
	d2[s-m][s]=0;
	q.push({0,s});
	while(!q.empty()){
		auto x=q.top();
		q.pop();
		int u=x.second;
		if(d2[s-m][u] > x.first) continue;
		for(int i=head[u];i;i=e[i].nxt){
			int v=e[i].to;
			if(d2[s-m][v] > d2[s-m][u]+e[i].w){
				d2[s-m][v]=d2[s-m][u]+e[i].w;
				q.push({d2[s-m][v],v});
			}
		}
	}
}
int ww[N];
int id[505][150000],res[N];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int c,D,Q;
	cin>>c>>n>>m>>D>>Q;
	if(m>=140000){
		tot=m;
		for(int i=1;i<=m;i++) cin>>ww[i];
		for(int i=1;i<=n;i++){
			//表示地铁线路的点
			int k;
			cin>>k;
			tot++;
			for(int j=1;j<=k;j++){
				id[i][j]=tot;
				int v,w;
				cin>>v>>w;
				add(v,id[i][j],w);
				add(id[i][j],v,w);
			}
		}
		for(int i=1;i<=n;i++){
			dij2(i+m);
		}
		for(int i=1;i<=Q;i++){
			int l,r;
			cin>>l>>r;
			int ans=inf;
			for(int j=1;j<=n;j++){
				ans=min(ans,d2[j][l]+d2[j][r]);
			}
			cout<<ans+ww[l]+ww[r]<<'\n';
		}
		return 0;
	}
	tot=m;
	for(int i=1;i<=m;i++) cin>>ww[i];
	for(int i=1;i<=n;i++){
		//表示地铁线路的点
		int k;
		cin>>k;
		tot++;
		for(int j=1;j<=k;j++){
			id[i][j]=tot;
			int v,w;
			cin>>v>>w;
			add(v,id[i][j],w);
			add(id[i][j],v,w);
		}
	}
	for(int i=1;i<=n;i++){
		dij(i+m);
	}
	for(int i=1;i<=Q;i++){
		int l,r;
		cin>>l>>r;
		int ans=inf;
		for(int j=1;j<=n;j++){
			ans=min(ans,d[j][l]+d[j][r]);
		}
		cout<<ans+ww[l]+ww[r]<<'\n';
	}
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3

*/