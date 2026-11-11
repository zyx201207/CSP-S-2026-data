#include<bits/stdc++.h>
using namespace std;
struct node{
	int l,r;
};
int c,n,m,k,q,w;
int a[1000001];
int d[1000001];
int x[1000001],y[1000001];
int tim=0,ans=INT_MAX;
int f[1000001];
bool vis[1000001];
vector<node> g[501];
void bfs(int x){
	vis[x]=1;
	//cout<<x<<" ";
	if(x==w){
		ans=min(ans,tim);
		return ;
	}
	int ma=INT_MAX,t;
	for(auto v:g[x]){
		if(vis[v.l]==1){
			continue;
		}
		//cout<<v.l<<"\n";
		tim+=(a[v.l]+d[v.l]);
		bfs(v.l); 
		tim-=d[v.l];
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>k>>q;
	for(int i=1;i<=m;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int qwq;
		cin>>qwq;
		for(int j=1;j<=qwq;j++){
			cin>>x[j]>>y[j];
			d[x[i]]=y[i];
		}
		for(int j=2;j<=qwq;j++){
			g[x[j-1]].push_back({x[j],y[j]});
			g[x[j]].push_back({x[j-1],y[j]});
		}
		g[x[qwq]].push_back({x[1],y[1]});
		g[x[1]].push_back({x[qwq],y[1]});
	}
	for(int i=1;i<=q;i++){
		int q;
		cin>>q>>w;
		for(int i=1;i<=n;i++){
			f[i]=i;
		}
		tim=(d[1]+a[1]);
		ans=INT_MAX;
		for(int i=1;i<=n;i++){
			vis[i]=0;
		}
		bfs(q);
		cout<<ans;
	}
	return 0;
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
