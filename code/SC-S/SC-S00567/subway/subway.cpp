#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q;
long long w[500005];
vector<pair<long long,long long> >v[505];
vector<pair<long long,long long> >vec[505];
long long dis[505];
bool vis[505];
int main (){
	cin.tie(0)->sync_with_stdio(0);
	cout.tie(0)->sync_with_stdio(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	//m个地铁站->每个地铁站有一个站厅
	//n->n条线路
	//d ：每个地铁线的最大线数
	//q : 查询数
	for(int i=1;i<=m;i++){
		cin>>w[i];//站厅到地铁口的时间
	}
	for(int i=1;i<=n;i++){
		long long k;
		cin>>k;
		for(int j=1;j<=k;j++){
			long long a,t;
			cin>>a>>t;
			v[i].push_back({t,a});
		}
	}
	for(int i=1;i<=n;i++){
		for(auto cur : v[i]){
			for(auto uu : v[i]){
				long long fa=cur.second;
				long long son=uu.second;
				if(fa==son)continue;
				long long op=uu.first;
				long long val=cur.first;
				val+=op;
				vec[fa].push_back({val,son});
				vec[son].push_back({val,fa});
			}
		}
	}
	priority_queue<pair<long long,long long> , vector<pair<long long ,long long> > ,greater<pair<long long,long long> > >que;
	while(q--){
		long long x,y;
		cin>>x>>y;
		que.push({0,x});
		for(int i=1;i<=m;i++){
			dis[i]=1e18;
			vis[i]=0;
		}
		dis[x]=0;
//		long long iii=0;
		while(que.size()!=0){
			long long val=que.top().first;
			long long fa=que.top().second;
			que.pop();
//			if(iii==n)break;
			if(vis[fa]==1)continue;
			vis[fa]=1;
//			iii++;
			for(auto oo : vec[fa]){
				long long vv=oo.first;
				long long son=oo.second;
				if(vv+val<dis[son]){
					dis[son]=vv+val;
					que.push({dis[son],son});
				}
			}
		}
		cout<<dis[y]+w[x]+w[y]<<"\n";
	}
	return 0;
}