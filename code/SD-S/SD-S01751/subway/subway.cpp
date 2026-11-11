#include<bits/stdc++.h>
using namespace std;
const int N=5*1e5+10;
long long c,n,m,d,q,w[N],t[N][N];
vector<vector<long long>>xi;
vector<vector<long long>>e;
long long bfs(long long x,long long y,long long xian){
	long long cnt=1e20;
	for(auto &o:e[x]){
		for(auto &xia:xi[o])cnt=min(cnt,bfs(o,y,xia)+w[o]+t[0][xia]);
		if(o==y)break;
		/*if(o.nxt)cnt=min(cnt,bfs(o.nxt,y)+w[o.nxt]+o.v);
		*/
	}
	return cnt;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	/*for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		long long a,t,be=0;
		cin>>a>>t;
		e[0][a].v=t;
		fa[a]=0;
		be=a;
		cin>>a>>t;
	 	e[be].push_back({a,t});
	 	fa[a]=be;
		for(int j=3;j<=k;j++){
			cin>>a>>t;
			e[i].push_back({a,t});
	 		fa[a]=be;
		}
	}*/
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		long long a,be;
		cin>>a>>t[i][1];
		be=a;
		xi[a].push_back(i);
		for(int j=2;j<=k-1;j++){
			cin>>a>>t[i][j];
			e[be].push_back(a);
			be=a;
			xi[a].push_back(i);
		}
		cin>>a>>t[i][k];
		xi[a].push_back(i);
	}
	while(q--){
		long long x,y;
		cin>>x>>y;
		cout<<w[x]+w[y]+bfs(x,y,xi[x][0])<<'\n';
	}
	return 0;
}
