#include<bits/stdc++.h>
#define ll long long
#define F first
#define S second
#define pi pair<int,int>
#define ull unsigned long long
#define endl "\n"
using namespace std;
const int N=5e5+100,INF=1e9+10;
int w[N];
const int M=2100; 
int dis[M][M];
struct node{
	int w,u;
};
vector<node> g[M];
int c;int n,m,d,q;
bool vis[N];
void dj(int s){
	for(int i=1;i<=1500;i++){
		dis[s][i]=INF;
		vis[i]=0;
	}
	dis[s][s]=0;
	priority_queue<pi,vector<pi>,greater<pi>> q;
	q.push({0,s});
	while(!q.empty()){
		pi f=q.top();
		q.pop();
		int uu=f.S;
		if(vis[uu]){
			continue;
		}
		vis[uu]=1;
		for(auto e:g[uu]){
			if(dis[s][e.u]>dis[s][uu]+e.w){
				dis[s][e.u]=dis[s][uu]+e.w;
				q.push({dis[s][e.u],e.u});
			}
		}
	}return;
}
void solve1(){
	int k;
	int cnt=m;
	for(int i=1;i<=n;i++){
		cin>>k;
		++cnt;
		for(int j=1;j<=k;j++){
			int o,p;
			cin>>o>>p;
			g[cnt].push_back({p,o});
			g[o].push_back({p,cnt});
		}
	}
	for(int i=1;i<=cnt;i++){
		dj(i);
	}
	for(int i=1;i<=q;i++){
		int s,t;
		cin>>s>>t;
		cout<<dis[s][t]+w[s]+w[t]<<endl;
	}
}
void solve2(){
	int k;
	int cnt=m;
	for(int i=1;i<=n;i++){
		cin>>k;
		++cnt;
		for(int j=1;j<=k;j++){
			int o,p;
			cin>>o>>p;
			g[cnt].push_back({p,o});
			g[o].push_back({p,cnt});
		}
		
	}
}
int main(){
//	system("fc subway.out subway4.ans");
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
    	cin>>w[i];
	}
	if(m<=1000){
		solve1();
	}
	return 0;
}

