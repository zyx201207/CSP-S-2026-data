#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int N=6e5+10;
int c,n,m,mm,d,q,w[N],k[N],a[N],t[N],x,y,dis[N];
bool vis[N];
struct node{
	int to,we;
};
bool operator <(const node o,const node p){
	return o.we>p.we;
} 
vector<node> v[N];
priority_queue<node> qu;
signed main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>c>>n>>m>>d>>q;
	mm=m;
	for(int i=1;i<=m;i++){
		cin>>w[i];
		mm++;
		v[i].push_back({mm,w[i]});
		v[mm].push_back({i,w[i]});
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[j]>>t[j];
			mm++;
			v[a[j]+m].push_back({mm,t[j]});
			v[mm].push_back({a[j]+m,t[j]});
			if(j==1)continue;
			v[mm].push_back({mm-1,0});
			v[mm-1].push_back({mm,0}); 
		}
	}
	while(q--){
		cin>>x>>y;
		memset(dis,0x3f,sizeof(dis));
		memset(vis,0,sizeof(vis));
		qu.push({x,0});
		dis[x]=0;
		while(!qu.empty()){
			node now=qu.top();
			qu.pop();
			int k=now.to;
			if(vis[k]==1)continue;
			vis[k]=1;
			for(auto i:v[k]){
				int to2=i.to;
				if(dis[to2]>dis[k]+i.we){
					dis[to2]=dis[k]+i.we;
					qu.push({to2,dis[to2]});
				}
			}
		}
		cout<<dis[y]<<endl;
	}
	return 0;
}
