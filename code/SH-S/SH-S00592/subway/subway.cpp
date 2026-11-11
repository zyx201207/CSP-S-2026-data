#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,f[505][505],w[500005];
bool vis[500005];
struct Node{
	long long l,t;
};
struct DIJ{
	long long x,dis;
	bool operator<(const DIJ &B)const{
		return dis>B.dis;
	}
};
vector<Node> a[500005];//经过地铁站a[i]的线路，l为该线路编号，t为到站厅时间 
//c=1~8,20~25 -> normal
//c=9~11 -> Special A
//c=12~19 -> Special B
void dij(int s){
	priority_queue<DIJ> q;
	q.push({s,0});
	memset(vis,0,sizeof(vis));
	vis[s]=1;
	while(!q.empty()){
		long long x=q.top().x,dis=q.top().dis;
		q.pop();
		if(dis>f[s][x])	continue;
//		cerr<<"checking "<<s<<" "<<x<<" "<<dis<<endl;
		for(int i=1;i<=n;++i){
//			cerr<<i<<' '<<s<<' '<<x<<' '<<dis<<' '<<f[s][i]<<' '<<f[x][i]<<endl;
			if(f[s][i]>dis+f[x][i]||(!vis[i]&&f[s][i]==dis+f[x][i])){
				f[s][i]=dis+f[x][i];
				f[i][s]=dis+f[x][i];
				vis[i]=1;
//				cerr<<"now f["<<s<<"]["<<i<<"]="<<f[s][i]<<endl;
				q.push({i,f[s][i]});
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>q; 
	memset(f,0x3f,sizeof(f));
	for(int i=1;i<=n;++i)
		f[i][i]=0;
	for(int i=1;i<=m;++i)
		cin>>w[i];
	for(int i=1;i<=n;++i){
		int k,x,y;
		cin>>k;
		for(int j=1;j<=k;++j){
			cin>>x>>y;
			for(auto z:a[x]){
				f[i][z.l]=min(f[i][z.l],y+z.t);
				f[z.l][i]=min(f[z.l][i],y+z.t);
			}
			a[x].push_back({i,y});
		}
	}
//	for(int i=1;i<=n;++i){
//		for(int j=1;j<=n;++j)
//			cerr<<f[i][j]<<' ';
//		cerr<<endl;
//	}
	for(int i=1;i<=n;++i)
		dij(i);
	while(q--){
		int x,y;
		cin>>x>>y;
		long long ans=9e18;
		for(auto ll:a[x])
			for(auto rr:a[y])
				ans=min(ans,ll.t+rr.t+f[ll.l][rr.l]);
		ans+=w[x]+w[y];
		cout<<ans<<"\n";
	}
	return 0;
}
