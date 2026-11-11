#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N(500010);
ll c,n,m,d,q;
ll w[N];
struct node{
	int a,t;
}a[510][20010];
vector<pair<int,int> >e[N];
ll dist[N*2],ans(0);
void djstl(int st,int ed){
	queue<int>q;
	q.push(st);
	dist[st]=0;
	while(q.size()){
		int u(q.front());
//		cout<<u<<'\n';
		q.pop();
		for(int i(0);i<e[u].size();i++){
			int v(e[u][i].first);
			ll w(e[u][i].second);
			if(dist[v]>1LL*dist[u]+w){
				dist[v]=dist[u]+w;
				q.push(v);
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i(1);i<=m;i++){
//		cout<<i<<':'<<q<<' '<<m<<'\n';
		scanf("%lld",&w[i]);
	}
	for(int i(1);i<=n;i++){
		int k;
		scanf("%d",&k);
		for(int j(1);j<=k;j++){
			scanf("%d%d",&a[i][j].a,&a[i][j].t);
			e[i+m].push_back({a[i][j].a,a[i][j].t});
			e[a[i][j].a].push_back({i+m,a[i][j].t});
		}
//		cout<<i<<'\n';
	}
//	for(int i(1);i<=n;i++){
//		cout<<i<<':';
//		for(int j(0);j<e[i].size();j++){
//			cout<<e[i][j].first<<' ';
//		}
//		cout<<'\n';
//		cout<<i+N<<':';
//		for(int j(0);j<e[i+N].size();j++){
//			cout<<e[i+N][j].first<<' ';
//		}
//		cout<<'\n';
//	}
//	cerr<<q<<'\n';
	for(int i(1);i<=q;i++){
		int x,y;
		cin>>x>>y;
		for(int j(1);j<=m;j++){
			dist[j]=dist[j+m]=1e18+7;
		}
		djstl(x,y);
		ans+=dist[y];
		ans+=w[x]+w[y];
		cout<<ans<<'\n';
//		cerr<<i<<'\n';
		ans=0;
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
