#include <bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
int c,n,d,m,qs,cnt=1;
int head[500005],dist[500005];
bool vis[500005];
struct node {
	vector<pii>lns;//该点经过的地铁线路，走到站台的时长 
	
	int w; 
}nd[500005];
struct edge {//两地铁线间存在的换乘，ww表示耗时 
	int v,nxt,ww;
}ed[500005];
int add(int a,int b,int c) {
	//cout << "ff" << endl;
	//cout << a << ' ' << b<<' ' <<c << endl;
	ed[cnt].v=b;
	ed[cnt].ww=c;
	ed[cnt].nxt=head[a];
	head[a]=cnt++;
	//cout << head[a] << endl;
}
void dij(int p) {
	
	priority_queue<pii,vector<pii>,greater<pii> >qu; 
		dist[p]=0;
		qu.push(make_pair(0,p));
		while(!qu.empty()) {
			int cp=qu.top().second;
			int cw=qu.top().first;
			qu.pop();
			
			if(vis[cp])continue;
			vis[cp]=1;
			//cout << 'a' << endl;
			//cout << head[cp] << endl;
			for(int i=head[cp];i!=-1;i=ed[i].nxt) {
				edge e=ed[i];
				//cout << cw << ' ' << e.ww << endl;
				if(dist[e.v]>cw+e.ww) {
					dist[e.v]=cw+e.ww;
					//cout << "fix" << dist[e.v];
					qu.push(make_pair(dist[e.v],e.v));
				}
			}
		}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	for(int i=0;i<=500005;i++)head[i]=-1;
	memset(dist,0x3f,sizeof dist);
	cin >> c>>n>>m>>d>>qs;
	for(int i=1;i<=m;i++) {
		cin >> nd[i].w;
		//cout <<'0';
	}
	for(int i=1;i<=n;i++) {
		int k;cin >> k;
		for(int j=1;j<=k;j++) {
			int a;cin >> a;
			int t;cin >> t;
			nd[a].lns.push_back(make_pair(i,t));
			//cout <<'a';
		}
		
		
	}
	for(int i=1;i<=m;i++) {
			node p=nd[i];
			 
			if(p.lns.size()>1) {
				for(int j=0;j<p.lns.size();j++) {
					for(int k=j+1;k<p.lns.size();k++) {
						add(p.lns[j].first,p.lns[k].first,p.lns[j].second+p.lns[k].second);
						//cout << ed[cnt-1].v << ' '<<ed[cnt-1].ww << ' '<<ed[cnt-1].nxt << endl;
						add(p.lns[k].first,p.lns[j].first,p.lns[j].second+p.lns[k].second);
						//cout << ed[cnt-1].v << ' '<<ed[cnt-1].ww << ' '<<ed[cnt-1].nxt << endl;
					//两线路间存在换乘节点，建立换乘边 
					//cout <<"added" << p.lns[j].first << ' ' << p.lns[k].first <<' '<<p.lns[j].second+p.lns[k].second <<endl;
					}
				}
			}
			//for(int i=1;i<=n;i++) {
			//	cout << head[i] <<' ';
			//}
			
		}
	//我写了个啥玩意 
	//沟石样例3为什么不过 
	//18:24 我废了 
	for(int i=0;i<qs;i++) {
		int p,q;cin >>p >>q;
		int tans=2e9;
		int ans=0;
		ans+=nd[p].w;ans+=nd[q].w;
		int sq=q;int sp=p;
		//dij最短路
		//O(n^3logn),力竭了 
		for(int j=0;j<nd[sp].lns.size();j++) {//枚举点p所经过的地铁线 
			int k=0;
			memset(dist,0x3f,sizeof dist);
			dij(nd[p].lns[j].first);
			//cout << j << ' ' << k <<endl;
			//for(int f=1;f<=2;f++)cout <<dist[f] <<' ';
			//cout << '\n';
			
			for(;k<nd[sq].lns.size();k++) {//枚举点q所经过的地铁线 
//				if(nd[p].lns[j].first==nd[p].lns[k].first){
//					tans=min(tans,ans+nd[p].lns[j].second+nd[q].lns[j].second);
//				}
				ans=nd[p].w+nd[q].w;
				if(nd[p].lns[j].first!=nd[q].lns[k].first){//换乘 
					
					ans+=dist[nd[q].lns[k].first];
					
					
				} 
				tans=min(tans,ans+nd[p].lns[j].second+nd[q].lns[k].second);
			}
			
		}
		cout <<tans <<endl; 
		
	}
	return 0;
}
