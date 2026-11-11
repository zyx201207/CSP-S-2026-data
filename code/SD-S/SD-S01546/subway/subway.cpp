//freopen checked?

#include<bits/stdc++.h>
#define int long long

using namespace std;
const int N=5e2+5,M=5e5+5,inf=0x3f3f3f3f3f3f3f3f;
set<int>v[N];
int dis[N][N];
int st[N][N];
//int f[N][N];
int c,n,m,d,q,w[M],x,y;
struct subway {
	int k;
	int a[N],t[N];
	map<int,int>mp;
}subw[N];
vector<pair<int,int>>g[N];
//int enc(int x,int y) {
//	return x*N+y;
//}
//pair<int,int>dec(int x) {
//	pair<int,int>pii={x/N,x%N};
//	return pii;
//}
signed main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin.tie(nullptr)->sync_with_stdio(false);
	cin>>c>>n>>m>>d>>q;
	memset(dis,0x3f,sizeof dis);
//	memset(f,0x3f,sizeof f);
	for(int i=1;i<=m;++i)cin>>w[i];
	for(int i=1;i<=n;++i) {
		cin>>subw[i].k;
		for(int j=1;j<=subw[i].k;++j) {
			cin>>subw[i].a[j]>>subw[i].t[j];
			v[subw[i].a[j]].insert(i);
			subw[i].mp[subw[i].a[j]]=j;
		}
	} 
//	for(int i=1;i<=n;++i) {
//		for(int j=1;j<=n;++j) {
//			for(auto t:v[i]) {
//				if(v[j].count(t)) {
//					if(mp.count({i,j}))mp[{i,j}]=mp[{j,i}]=min(mp[{i,j}],)
//				}
//			}
//		}
//	}
//	for(int i=1;i<=n;++i) {
//		for(int j=1;j<=n;++j) {
//			if(i==j)continue;
//			for(auto t:v[i]) {
//				int x=v[j].lower_bound(t);
//				if(x==t)dis[enc(i,j)]=min(dis[enc(i,j)],subw[i].t[)
//			}
//		}
//	}
	for(int i=1;i<=m;++i) {//calc dis
		for(auto t:v[i]) {//400
			for(auto u:v[i]) {
				if(t==u)continue;
				if(subw[t].t[subw[t].mp[i]]+subw[u].t[subw[u].mp[i]]<dis[t][u])st[t][u]=st[u][t]=i;
				dis[t][u]=dis[u][t]=min(dis[t][u],subw[t].t[subw[t].mp[i]]+subw[u].t[subw[u].mp[i]]);
			}
		}
	}
//	for(int i=1;i<=n;++i) {//build graph
//		for(int j=1;j<=m;++j) {
//			if(i==j)continue;
//			if(dis[i][j]==inf)continue;
//			f[i][j]=dis[i][j];
//		}
//	}
	for(int i=1;i<=n;++i) {//floyd
		for(int j=1;j<=n;++j) {
			for(int k=1;k<=n;++k) {
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	while(q--) {
		cin>>x>>y;
		int ans=inf;
		for(auto t:v[x]) {//400
			for(auto u:v[y]) {
				ans=min(ans,subw[t].t[subw[t].mp[x]]+dis[t][u]+subw[u].t[subw[u].mp[y]]);
				if(st[t][u]==x)ans=min(ans,dis[t][u]-subw[t].t[subw[t].mp[x]]+subw[u].t[subw[u].mp[x]]);
				if(st[t][u]==y)ans=min(ans,dis[t][u]+subw[t].t[subw[t].mp[x]]-subw[u].t[subw[u].mp[x]]);
			}
		}
//		cout<<subw[1].t[1]<<" "<<subw[2].t[1]<<" "<<subw[1].t[2]<<" ";
		cout<<ans+w[x]+w[y]<<"\n";
	}
//	for(int i=1;i<=m;++i)cout<<subw[1].mp[i]<<" "<<subw[2].mp[i]<<"\n";
//	int x;cin>>x;
//	for(int i=1;i<=x;++i) {
//		int y,z;cin>>y>>z;
//		cout<<dis[y][z]<<"\n";
//	}
	return 0;
}
