#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
using namespace std;
template<typename T>void read(T &x){int f=1;char ch=getchar();x=0;while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}x=x*f;return;}

const int N=6e5+5;
int c,n,m,d,q;
int xxx[505];
struct f{int v,w;};
vector<f>g[N];
int dis[N];
//0 2 5 20 2 4 1 9 2 5 3 1 5 2 7 4 6 3 2 3 3 4 5 7 1 3 1 2
void dijkstra(int st,int en){
	priority_queue<int,vector<int>,greater<int>>q;
	for(int i=1;i<=n;i++)dis[i]=1e9;
	dis[st]=0;
	q.push(st);
	while(!q.empty()){
		int u=q.top();
		q.pop();
		for(auto i:g[u]){
			int v=i.v,w=i.w;
			if(dis[v]+w<dis[u]){
				dis[u]=dis[v]+w;
				q.push(v);
			}
		}
	}
}

signed main(){
//	freopen("subway.in","r",stdin);
//	freopen("subway.out","w",stdout);
	read(c),read(n),read(m),read(d),read(q);
	for(int i=1;i<=m;i++)read(xxx[i]);
	for(int i=1;i<=n;i++){
		int k;
		read(k);
		for(int j=1;j<=k;j++){
			int v,w;
			read(v),read(w);
			g[m+i].push_back({v,w});
			g[v].push_back({m+i,w});
		}
	}
	while(q--){
		int st,en;
		read(st),read(en);
		dijkstra(st,en);
		cout<<dis[en]+xxx[st]+xxx[en]<<endl;
	}
}

