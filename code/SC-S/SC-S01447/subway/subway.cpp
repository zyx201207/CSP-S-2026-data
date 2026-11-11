#include<bits/stdc++.h>
#define int long long
#define UseDijkstra
using namespace std;
//rp++++++++++++++++++++++++++++++++++++++++++
//记录每个线路之间的最短路径
int c,n,m,d,q;
struct edge{
	int to,val;
};
struct sbw{
	int w;
	vector<edge>lk;//lnk,val
};
vector<sbw>a;
#ifndef UseDijkstra
struct lnk{
	vector<edge>nodes;//sbw,val
};
#else
struct lnk{
	vector<edge>nodes;
	vector<edge>nods;
};
#endif
bool operator<(edge a,edge b){
	return a.val>b.val;
}
vector<lnk>lin;
vector<vector<int>> zxc;
//vector<wedge>edges;
const int wqd=9999999999999320ll;
#ifdef UseDijkstra
void dijkstra(int stt){
	priority_queue<edge>q;
	vector<bool> vis(n,0);
	for(edge i:lin[stt].nods){
			q.push(i);
	}
	while(!q.empty()){
		edge cur=q.top();
		q.pop();
		zxc[stt][cur.to]=min(cur.val,zxc[stt][cur.to]);
		zxc[cur.to][stt]=zxc[stt][cur.to];
		for(edge nw:lin[cur.to].nods){
			if(!vis[nw.to]){
				vis[cur.to]=1;
				edge tps=nw;
				tps.val+=cur.val;
				q.push(tps);
			}
		}
	}
}
#endif
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	a.resize(m+1);
	for(int i=1;i<=m;++i){
		cin>>a[i].w;
	}
	lin.resize(n+1);
	zxc.assign(n+1,vector<int>(n+1,wqd));
	for(int i=1;i<=n;++i){
		int k;
		cin>>k;
		lin[i].nodes.resize(k);
		for(int j=0;j<k;++j){
			int b,t;
			cin>>b>>t;
			lin[i].nodes[j]={b,t};
			a[b].lk.push_back({i,t});
		}
	}
	for(int i=1;i<=n;++i){
		zxc[i][i]=0;
		//for(int j=i+1;j<=n;++j){
		for(edge k:lin[i].nodes){
			for(edge l:a[k.to].lk){
				zxc[i][l.to]=min(zxc[i][l.to],k.val+l.val);
				zxc[l.to][i]=zxc[i][l.to];
				
			}
		}
		//}
	}
#ifndef UseDijkstra
	for(int k=1;k<=n;++k){
		for(int i=1;i<=n;++i){
			for(int j=i+1;j<=n;++j){
				if(zxc[i][j]>zxc[i][k]+zxc[k][j]){
					zxc[i][j]=zxc[i][k]+zxc[k][j];
					zxc[j][i]=zxc[i][j];
				}
			}
		}
	}
#else
	for(int i=1;i<=n;++i){
		for(int j=i+1;j<=n;++j){
			if(zxc[i][j]!=wqd){
				lin[i].nods.push_back({j,zxc[i][j]});
			}
		}
	}
	for(int i=1;i<=n;++i){
		dijkstra(i);
	}
#endif
	//
	//cout<<"djkstscfc\n";
//	for(int i=1;i<=n;++i){
//		for(int j=1;j<=n;++j){
//			cout<<zxc[i][j]<<" ";
//		}
//		cout<<"\n";
//	}
	//
	for(;q>0;--q){
		int x,y;
		cin>>x>>y;
		int ans=wqd;
		for(edge i:a[x].lk){
			for(edge j:a[y].lk){
				ans=min(ans,zxc[i.to][j.to]+i.val+j.val);
			}
		}
		cout<<ans+a[x].w+a[y].w<<endl;
	}
	return 0;
} 