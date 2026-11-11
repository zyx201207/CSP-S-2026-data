#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mkp make_pair
const ll inf=1000000000000000000ll;
const int N=80500;
const int M=81100;
int T,m,n,d,Q,inq[83000];
ll w[500005],dis[83000],ans[100005];
int num(int x,int y){
	return (x-1)*400+y;
}
vector < pair<int,int> > qes[100005];
vector < pair<int,ll> > e[83000];
void SPFA(int s){
	memset(inq,0,sizeof(inq));
	for(int i=0;i<=82999;i++)dis[i]=inf;
	dis[s]=0;
	queue <int> q;
	q.push(s);
	inq[s]=1;
	while(!q.empty()){
		int u=q.front();
		q.pop();
		inq[u]=0;
		for(auto xx:e[u]){
			int v=xx.first,w=xx.second;
			if(dis[u]+w<dis[v]){
				dis[v]=dis[u]+w;
				if(!inq[v]){
					q.push(v);
					inq[v]=1;
				}
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>T>>m>>n>>d>>Q;
	for(int i=1;i<=n;i++)cin>>w[i];
	for(int i=1;i<=m;i++){
		int k,x,y;
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>x>>y;
			e[num(i,x)].pb(mkp(N+i,0));
			e[N+i].pb(mkp(num(i,x),0));
			e[num(i,x)].pb(mkp(num(201,x),y));
			e[num(201,x)].pb(mkp(num(i,x),y));
		}
	}
	for(int i=1;i<=n;i++){
		e[M+i].pb(mkp(num(201,i),w[i]));
		e[num(201,i)].pb(mkp(M+i,w[i]));
	}
	for(int i=1;i<=Q;i++){
		int st,en;
		cin>>st>>en;
		qes[st].pb(mkp(en,i));
	}
	for(int i=1;i<=n;i++){
		if(qes[i].size()){
			SPFA(M+i);
			for(auto xx:qes[i]){
				int id=xx.second,tt=xx.first;
				ans[id]=dis[M+tt];
			}
		}
	}
	for(int i=1;i<=Q;i++)cout<<ans[i]<<'\n';
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