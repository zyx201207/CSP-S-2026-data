#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=505,M=5e5+5,K=5e5+5;
int c,n,m,d,q; // shenme, d, q
int w[M],k[N];
vector<int> a[N],t[N];

int maxid;
struct Ln {
	int no,id;
};
map<int,vector<Ln> > repeat;
pair<int,int> used[M];
int newid[M];

int atline[M];

struct E {
	int to,w,nxt;
} e[500005];
int hd[100005],ne=0;
void adde(int u,int v,int w){
	e[++ne]=(E){v,w,hd[u]};
	hd[u]=ne;
}
struct Nd {
	int u,d;
	bool operator<(const Nd &b)const {
		return d>b.d;
	}
};
int dis[100005];
int dijkstra(int s,int t){
	for(int i=1;i<=maxid;i++) dis[i]=1e16;
	priority_queue<Nd> pq;
	dis[s]=0;
	pq.push((Nd){s,0});
	while(!pq.empty()){
		int u=pq.top().u,d=pq.top().d;
		pq.pop();
		if(u==t) break;
		for(int i=hd[u];i;i=e[i].nxt){
			int v=e[i].to,cand=d+e[i].w;
			if(cand>=dis[v]) continue;
			else {
				dis[v]=cand;
				pq.push((Nd){v,dis[v]});
			}
		}
	}
	return dis[t];
}

signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	maxid=n;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		a[i].push_back(0);
		t[i].push_back(0);
		for(int j=1;j<=k[i];j++){
			a[i].push_back(0);
			t[i].push_back(0);
			cin>>a[i][j]>>t[i][j];
			if(used[a[i][j]].first){
				if(repeat.find(a[i][j])==repeat.end()){
					repeat[a[i][j]].push_back((Ln){
							used[a[i][j]].first,
							used[a[i][j]].second
						}
					);
//printf("repeat[%d].append( ( %d, %d ) )\n",a[i][j],
//	used[a[i][j]].first,
//	used[a[i][j]].second
//);
				}
				repeat[a[i][j]].push_back((Ln){i,j}); // for finding t
//printf("repeat[%d].append( ( %d, %d ) )\n",a[i][j],i,j);
			}
			else {
				used[a[i][j]]=make_pair(i,j);
				atline[a[i][j]]=i;
			}
		}
	}
	for(pair<int,vector<Ln> > item: repeat){
		int stt=item.first;
		// lines: item.second
		maxid++;
		newid[stt]=maxid;
		for(Ln ln: item.second){
			adde(ln.no,maxid,t[ln.no][ln.id]);
			adde(maxid,ln.no,t[ln.no][ln.id]);
		}
	}
	
//	maxid,repeat,used,recpos,newid,[edges],atline
//	printf("maxid: %d (should be of n=%d orig and %d new)\n",maxid,n,maxid-n);
//	printf("Transforms:\n");
	for(pair<int,vector<Ln> > item: repeat){
//		printf("\tstation = %d    Lines passing:\n",item.first);
		for(Ln iitem: item.second){
			printf("\t\tline %d, %d th station\n",iitem.no,iitem.id);
		}
	}
	printf("newid or atline:\n");
	for(int i=1;i<=m;i++){
		if(newid[i]) printf("\t%d: newid %d\n",i,newid[i]);
		else printf("\t%d: single station, line %d\n",i,atline[i]);
	}
	printf("Edges:\n");
	for(int u=1;u<=maxid;u++){
		printf("\tedges from %d:\n",u);
		for(int i=hd[u];i;i=e[i].nxt){
			int v=e[i].to,w=e[i].w;
			printf("\t\tto %d: %d min\n",v,w);
		}
	}
	
	for(int r=1;r<=q;r++){
		int x,y;
		cin>>x>>y;
		int ans=w[x]+w[y];
		if(newid[x]) x=newid[x]; else x=atline[x];
		if(newid[y]) y=newid[y]; else y=atline[y];
		int mindis=dijkstra(x,y);
		printf("%lld\n",ans,mindis);
	}
	return 0;
}








