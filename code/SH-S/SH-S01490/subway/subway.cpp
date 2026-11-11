#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,q,idx = 0;
long long otin[41507];
long long consump [41507][505];
vector<int> trans[41507];
struct edge{
	int v;
	long long c;
	int next;
}E[1500002];
int head[505];
void add(int u,int v,int c){
	idx++;
	E[idx].v = v;
	E[idx].c = c;
	E[idx].next = head[u];
	head[u] = idx;
}
struct ndis{
	int n;
	long long dis;
	bool operator >(const ndis &a)const{return dis > a.dis;}
};
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1;i<=m;i++) cin >> otin[i];
	for(int i = 1;i<=n;i++){
		long long ki;
		cin >> ki;
		for(int j = 1;j <= ki;j++){
			long long stop,t;
			cin >> stop >> t;
			consump[stop][i] = t;
			trans[stop].push_back(i);
			add(stop + n,i,otin[stop]+t);
			add(i,stop + n,otin[stop]+t);
		}
	}
	for(int i = 1;i <= m;i++){
		if(trans[i].size()>=2){
			for(int j = 0;j<trans[i].size();j++){
				for(int f = 0;f<trans[i].size();f++){
					if(trans[i][j] != trans[i][f]){
						int linea = trans[i][j],lineb = trans[i][f],nstop = i; 
						long long cost = consump[nstop][linea] + consump[nstop][lineb];
						add(linea,lineb,cost);
					}
				}
			}
		}
	}
	while(q){
		q--;
		int xr,yr;
		cin >> xr >> yr;
		xr = xr+n,yr = yr+n;
		long long dis[30505];
		bool vis[30505];
		for(int i = 1; i <= n+m;i++) dis[i] = 1000000000000000; 
		for(int i = 1; i <= n+m;i++) vis[i] = 0; 
		priority_queue<ndis,vector<ndis>,greater<ndis> > pq;
		pq.push((ndis){xr,0});
		dis[xr] = 0;
		while(!pq.empty()){
			ndis kkk = pq.top();pq.pop();
			long long disnow = kkk.dis;
			int u = kkk.n;
			if(vis[u])
				continue;
			vis[u] = 1;
			for(int i = head[u];i;i=E[i].next){
				int v = E[i].v;
				long long c = E[i].c;
				if(!vis[v] && c + disnow < dis[v]){
					dis[v] = c + disnow;
					pq.push((ndis){v,dis[v]});
				} 
			}
		}
		cout << dis[yr] <<"\n";
	}
	return 0;
} 
