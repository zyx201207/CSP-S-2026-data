#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
using LL=long long;
using PLL=pair<LL,LL>;
const int N=5e5+10;
struct Node{
	int t,ip;
};
Node make(int t,int ip){
	Node tmp;
	tmp.t=t;
	tmp.ip=ip;
	return tmp;
}
vector<Node> lin[500+10];
vector<Node> sta[int(5e5+10)];
LL dis[500+10][500+10];
bool vis[500+10][500+10];
LL w[N];
int c/*测试点编号*/,n/*线路*/,m/*站*/,d/*同站*/,q/*规划*/;

void dj(int x){
	priority_queue<PLL,vector<PLL>,greater<PLL> > q;
	memset(dis[x],0x3f,sizeof dis[x]);
	dis[x][x]=0;
	q.push({dis[x][x],x});
	while(!q.empty()){
		auto u=q.top();
		q.pop();
		if(vis[x][u.second]) continue;
		for(auto v:lin[u.second]){
			for(auto w:sta[v.ip]){
				if(dis[x][w.ip]>u.first+v.t+w.t){
					dis[x][w.ip]=u.first+v.t+w.t;
					q.push({dis[x][w.ip],w.ip});
				}
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1,a,t,k;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a>>t;
			lin[i].push_back(make(t,a));
			sta[a].push_back(make(t,i));
		}
	}
	for(int i=1;i<=n;i++){
		dj(i);
	}
	for(int i=1,x,y;i<=q;i++){
		cin>>x>>y;
		LL ans=0x3f3f3f3f3f3f3f3f;
		for(auto st:sta[x]){
			for(auto en:sta[y]){
				ans=min(ans,dis[st.ip][en.ip]+st.t+en.t+w[x]+w[y]);
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
