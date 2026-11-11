#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;
int c,n,m,d,q,w[500010];
long long vis[500510];
struct node{
	int to;
	long long val;
	node():to(0),val(0){}
	node(int x,int y):to(x),val(y){}
	node(int x,long long y):to(x),val(y){}
	bool operator<(const node&oth)const{
		return val<oth.val;
	}
};
vector<node>e[500510];
void add(int x,int y,int v){
	e[x].emplace_back(y,v);
	e[y].emplace_back(x,v);
}
priority_queue<node>pq;
void dij(int s){
	vis[s]=0;
	pq.emplace(s,0);
	while(!pq.empty()){
		node now=pq.top();pq.pop();
		for(node nex:e[now.to]){
			if(vis[nex.to]>now.val+nex.val){
				vis[nex.to]=now.val+nex.val;
				pq.emplace(nex.to,vis[nex.to]);
			}
		}
	}
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1,k,a,t,j;i<=n;i++){
		cin>>k;
		for(j=1;j<=k;j++){
			cin>>a>>t;
			add(a,i+m,t);
		}
	}
	int x,y;
	while(q--){
		cin>>x>>y;
		memset(vis,0x3f,sizeof vis);
		dij(x);
		cout<<vis[y]+w[x]+w[y]<<"\n";
	}
	return 0;
}