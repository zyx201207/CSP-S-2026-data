#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define ll long long
const int N=505,M=2e3+5;
int c,n,m,d,Q;
ull w[M];
ull a[M],t[M];
ull dis[M][M];
ll cnt,head[M];
bool book[M];
struct edge{
	int nxt,to;
	ll dis;
}e[M<<1];
void e_add(int u,int v,int w){
	e[++cnt].to=v;
	e[cnt].dis=w;
	e[cnt].nxt=head[u];
	head[u]=cnt;
	return ;
}
struct node{
	int st;
	ll ti;
	bool operator <(const node&x)const{
		return x.ti<ti;
	}
};
priority_queue<node> q;
void fid(int s){
	for(int i=1;i<=m;i++)book[i]=0;
	dis[s][s]=0;
	q.push({s,0});
	while(!q.empty()){
		node x=q.top();q.pop();
		if(book[x.st])continue;
		book[x.st]=1;
		for(int i=head[x.st];i;i=e[i].nxt){
			if(dis[s][e[i].to]>dis[s][x.st]+e[i].dis){
				dis[s][e[i].to]=dis[s][x.st]+e[i].dis;
				q.push({e[i].to,dis[s][e[i].to]});
			}
		}
	}
}
int main(){	
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	for(int i=1;i<=M;i++){
		for(int j=1;j<=M;j++){
			dis[i][j]=-1;
		}
	}
	cin>>c>>n>>m>>d>>Q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a[j]>>t[j];
			for(int l=1;l<=j;l++){
				e_add(a[j],a[l],t[j]+t[l]);
				e_add(a[l],a[j],t[j]+t[l]);
			}
		}
	}
	for(int i=1;i<=m;i++){
		fid(i);
	}
	for(int i=1;i<=Q;i++){
		int x,y;
		cin>>x>>y;
		cout<<dis[x][y]+w[x]+w[y]<<'\n';
	}
	
	return 0;
}
