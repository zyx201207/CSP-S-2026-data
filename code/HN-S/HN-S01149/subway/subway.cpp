#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define pii pair < int,int >
#define fi first
#define se second
const int N=5e2+5;
const int M=5e5+5;
const int Q=1e5+5;
int c,n,m,d,q;
int w[N];
pair < pii,int > qry[Q];
vector < vector < pii > > a;
int dis[N],ans[Q];
void dij(int st){
	memset(dis,0x3f,sizeof(dis));
	priority_queue < pii,
			vector < pii >,
			greater< pii > > pq;
	pq.push({0,st});
	dis[st]=0;
	while(pq.size()){
		pii text=pq.top();pq.pop();
		const int &u=text.se;
		const int &t=text.fi;
		if(t!=dis[u]) continue;
		for(int i=0;i<a[u].size();i++){
			const int &v=a[u][i].fi;
			const int &w=a[u][i].se;
//			cout<<"[debug]:"<<u<<' '<<v<<' '<<w<<endl;
			if(dis[v]>dis[u]+w){
				dis[v]=dis[u]+w;
				pq.push({dis[v],v});
			}
		}
	}
//	cout<<"[debug]:";
//	for(int i=1;i<=m;i++){
//		cout<<dis[i]<<' ';
//	}
//	cout<<endl;
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
//	freopen("subway3.in","r",stdin);
//	freopen("out.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	a.resize(n*m+m+1,vector < pii >());
	for(int i=1;i<=n;i++){
		int k;cin>>k;
		int last;
		for(int j=1;j<=k;j++){
			int x,t;cin>>x>>t;
			a[x].push_back({i*m+x,t});
			a[i*m+x].push_back({x,t});
			if(j!=1){
				a[last].push_back({i*m+x,0});
				a[i*m+x].push_back({last,0});
			}
			last=i*m+x;
		}
	}
//	memset(dis,0x3f,sizeof(dis));
//	for(int i=1;i<=m;i++){
//		if(dis[i]>INT_MAX){
//			cout<<"[debug]:"<<i<<endl;
//			dij(i);
//		}
//	}
	for(int i=1;i<=q;i++){
		int x,y;cin>>x>>y;
		qry[i].fi={min(x,y),max(x,y)};
		qry[i].se=i;
	}
	sort(qry+1,qry+1+q);
	for(int i=1;i<=q;i++){
		if(qry[i].fi.fi!=qry[i-1].fi.fi)
			dij(qry[i].fi.fi);
		const int &u=qry[i].fi.fi;
		const int &v=qry[i].fi.se;
		ans[qry[i].se]=w[u]+w[v]+dis[v];
	}
	for(int i=1;i<=q;i++){
		cout<<ans[i]<<endl;
	}
	return 0;
}
