#include<bits/stdc++.h>
#define int long long
using namespace std;
struct node{
	int x,y,id;
}Q[100005];
struct NODE{
	int idx,dist;
	bool operator < (const NODE& x) const{
		return dist>x.dist;
	}
};
struct NODE2{
	int idx,dist;
};
const int INF=0x3f3f3f3f3f3f3f3f;
int c,n,m,d,q,tot,u,v,a,t,w[5000005],k[505],dist[50005],ans[100005],dist2[50005];
bool vis[50005],vis2[50005];
vector<int> ve[5000005],wi[5000005];
bool cmp(node x,node y){
	return x.x<y.x;
}
void dijk(int x){
	for(int i=1;i<=tot;i++){
		dist[i]=INF;
		vis[i]=0;
	}
	priority_queue<NODE> qu;
	qu.push((NODE){x,0});
	dist[x]=0;
	while(qu.size()){
		NODE sn=qu.top();
		qu.pop();
		u=sn.idx;
		if(vis[u]){
			continue;
		}
		vis[u]=1;
		for(int i=0;i<ve[u].size();i++){
			v=ve[u][i];
			if(dist[v]>dist[u]+wi[u][i]){
				dist[v]=dist[u]+wi[u][i];
				qu.push((NODE){v,dist[v]});
			}
		}
	}
}
void dijk2(int x){
	for(int i=1;i<=tot;i++){
		dist2[i]=INF;
		vis2[i]=0;
	}
	queue<NODE2> qu;
	qu.push((NODE2){x,0});
	dist2[x]=0;
	while(qu.size()){
		u=qu.front().idx;
		qu.pop();
		if(vis2[u]){
			continue;
		}
		vis2[u]=1;
		for(int i=0;i<ve[u].size();i++){
			v=ve[u][i];
			if(dist2[v]>dist2[u]+wi[u][i]){
				dist2[v]=dist2[u]+wi[u][i];
				qu.push((NODE2){v,dist2[v]});
			}
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	tot=m;
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a>>t;
			ve[a].push_back(tot+j);
			ve[tot+j].push_back(a);
			wi[a].push_back(t);
			wi[tot+j].push_back(t);
			
			if(j>1){
				ve[tot+j].push_back(tot+j-1);
				ve[tot+j-1].push_back(tot+j);
				wi[tot+j].push_back(0);
				wi[tot+j-1].push_back(0);
			}
		}
		tot+=k[i];
	}
	n=tot;
	for(int i=1;i<=q;i++){
		cin>>Q[i].x>>Q[i].y;
		Q[i].id=i;
	}
	sort(Q+1,Q+1+q,cmp);
	for(int i=1;i<=q;i++){
		if(c>=0&&c<=11){
			if(i==1){
				dijk(Q[i].x);
			}else if(Q[i].x!=Q[i-1].x){
				dijk(Q[i].x);
			}
			ans[Q[i].id]=dist[Q[i].y]+w[Q[i].x]+w[Q[i].y];
		}
		if(c>=12&&c<=15){
			if(i==1){
				dijk2(Q[i].x);
			}else if(Q[i].x!=Q[i-1].x){
				dijk2(Q[i].x);
			}
			ans[Q[i].id]=dist2[Q[i].y]+w[Q[i].x]+w[Q[i].y];
		}
	}
	for(int i=1;i<=q;i++){
		cout<<ans[i]<<'\n';
	}
	return 0;
} 
