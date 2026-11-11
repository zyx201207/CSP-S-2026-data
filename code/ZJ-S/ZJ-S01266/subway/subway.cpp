#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,st,ed;
long long w[500005],minn=LONG_LONG_MAX,mik;
int k[105];
vector<int> a[105];
int t[105][500005];
int aa,tt;
int sa[105];
bool han[105][500005];
vector<pair<int,int> > e[105];
int ke[105];
void bfs(int sss){
	int vis[105];
	memset(vis,0,sizeof(vis));
	priority_queue<pair<long long,int>,vector<pair<long long,int> >,greater<pair<long long,int> > > q;
	q.push({0,sss});
	while(!q.empty()){
		pair<int,int> pp=q.top();
		q.pop();
		int now=pp.second;
		if(vis[now]) continue;
		vis[now]=1;
		long long dis=pp.first;
		if(ke[now]) {
			mik=min(mik,dis);
			return;
		}
		int len=e[now].size();
		for(int i=0;i<len;i++){
			int to=e[now][i].second;
			int lon=e[now][i].first;
			if(vis[to]==0){
				q.push({dis+lon,to});
			}
		}
	}
	return;
}
void ndr(){
	int sha=INT_MAX,xia=INT_MAX;
	if(han[1][st]) sha=t[1][st];
	if(han[2][st]) sha=min(sha,t[2][st]);
	if(han[1][ed]) xia=t[1][ed];
	if(han[2][ed]) xia=min(xia,t[2][ed]);
	minn=minn+sha+xia;
	if(han[1][st]&&han[1][ed]){
		if(t[1][st]+t[1][ed]<minn) minn=t[1][st]+t[1][ed];
	}
	if(han[2][st]&&han[2][ed]){
		if(t[2][st]+t[2][ed]<minn) minn=t[2][st]+t[2][ed];
	}
	cout<<w[st]+w[ed]+minn<<endl;
	return;
}
void spp(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=k[i];j++){
			int bian=a[i][j-1];
			for(int op=1;op<=n;op++){
				if(han[op][bian]&&op!=i){
					e[op].push_back({t[i][bian]+t[op][bian],i});
					e[i].push_back({t[i][bian]+t[op][bian],op});
				}
			}
		}
	}
}
void spe(){
	mik=LONG_LONG_MAX;
	memset(ke,0,sizeof(ke));
	for(int i=1;i<=n;i++){
		if(han[i][ed]) ke[i]=1;
	}
	for(int i=1;i<=n;i++){
		if(han[i][st]) bfs(st);
	}
	cout<<mik+w[ed]+w[st]<<endl;
	return;
}
void baol(){
	int vis[405];
	memset(vis,0,sizeof(vis));
	priority_queue<pair<long long,int>,vector<pair<long long,int> >,greater<pair<long long,int> > > q;
	q.push({0,st});
	while(!q.empty()){
		pair<int,int> pp=q.top();
		q.pop();
		int now=pp.second;
		if(vis[now]) continue;
		vis[now]=1;
		long long dis=pp.first;
		if(now==ed){
			cout<<dis+w[st]+w[ed]<<endl;
			return;
		}
		for(int i=1;i<=n;i++){
			if(han[i][now]==0) continue;
			for(int j=1;j<=k[i];j++){
				int to=a[i][j-1];
				if(vis[to]==0) q.push({dis+t[i][now]+t[i][to],to});
			}
		}
	}
	return;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d",&c);
	scanf("%d",&n);
	scanf("%d",&m);
	scanf("%d",&d);
	scanf("%d",&q);
	for(int i=1;i<=m;i++){
		scanf("%d",&w[i]);
	}
	int ma=0;
	for(int i=1;i<=n;i++){
		scanf("%d",&k[i]);
		ma=max(ma,k[i]);
		for(int j=1;j<=k[i];j++){
			scanf("%d",&aa);
			a[i].push_back(aa);
			scanf("%d",&t[i][a[i][j-1]]);
			han[i][a[i][j-1]]=true;
		}
	}
	if(n==2){
		for(int i=1;i<=k[1];i++){
			if(han[2][a[1][i-1]]){
				if(t[1][a[1][i-1]]+t[2][a[1][i-1]]<minn) minn=t[1][a[1][i-1]]+t[2][a[1][i-1]];
			}
		}
	}
	else if(ma<=2) spp();
	while(q--){
		scanf("%d",&st);
		scanf("%d",&ed);
		if(st==ed){
			cout<<0<<endl;
		}
		else if(n==2){
			ndr();
		}
		else if(ma<=2){
			spe();
		}
		else baol();
	}
}
