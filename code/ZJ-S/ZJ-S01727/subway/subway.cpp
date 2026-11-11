#include <bits/stdc++.h>

using namespace std;
#define ll long long
const ll MAXN=5e5+5,MAXM=1e3+5,MX=0x3f3f3f3f3f3f3f3f;
struct Edge{
	ll to,ew;
};
struct Node{
	ll st,ed,nw;
	bool operator<(const Node& other) const{
		return nw>other.nw;
	}
}tmp;
ll c,n,m,d,q,w[MAXN],k,a[MAXN],t[MAXN],st[MAXN],costt[MAXM][MAXM],num,x,y;
vector<Edge> v[MAXN];
priority_queue<Node> pq;
int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a[j]>>t[j];
		}
		for(int j=1;j<=k;j++){
			for(int u=j+1;u<=k;u++){
				v[a[j]].push_back({a[u],t[j]+t[u]});
				v[a[u]].push_back({a[j],t[j]+t[u]});
			}
		}
	}
	for(int u=1;u<=m;u++){
		for(int i=1;i<=m;i++){
			costt[u][i]=MX;
		}
		costt[u][u]=0;
		num=m;
		for(int i=1;i<=m;i++){
			pq.push({0,i,costt[u][i]});
		}
		while(num--){
			tmp=pq.top();
			while(st[tmp.ed]){
				pq.pop();
				tmp=pq.top();
			}
			st[tmp.ed]=1;
			for(int i=0;i<v[tmp.ed].size();i++){
				if(st[v[tmp.ed][i].to]){
					continue;
				}
				if(tmp.nw+v[tmp.ed][i].ew<costt[u][v[tmp.ed][i].to]){
					costt[u][v[tmp.ed][i].to]=tmp.nw+v[tmp.ed][i].ew;
					pq.push({tmp.ed,v[tmp.ed][i].to,costt[u][v[tmp.ed][i].to]});
				}
			}
		}
		while(!pq.empty()){
			pq.pop();
		}
		memset(st,0,sizeof(st));
	}
	while(q--){
		cin>>x>>y;
		cout<<costt[x][y]+w[x]+w[y]<<"\n";
	}
	return 0;
}
