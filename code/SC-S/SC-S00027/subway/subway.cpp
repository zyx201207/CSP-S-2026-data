#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
const int N=5e5+5,M=505;
long long INF=(long long)(1e9)*1e5;
long long c,n,m,d,q,ts[M];
long long tcc[M][M];
vector<int>zt[M],tct[N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>ts[i];
	for(int i=1;i<=n;i++){
		int k;cin>>k;
		for(int j=0;j<k;j++){
			int a,t;cin>>a>>t;
			tct[a].push_back(t);
			zt[a].push_back(i);
		}
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++){
			if(i==j)continue;
			tcc[i][j]=INF;
		}
	for(int i=1;i<=m;i++){
		int sz=zt[i].size();
		if(sz==1)continue;
		for(int t1=0;t1<sz;t1++){
			for(int t2=t1+1;t2<sz;t2++){
				int v=zt[i][t1],u=zt[i][t2];
				long long h=tct[i][t1]+tct[i][t2];
				tcc[v][u]=min(tcc[v][u],h);
				tcc[u][v]=min(tcc[u][v],h);
			}
		}
	}
	for(int t1=1;t1<=n;t1++){
		for(int t2=1;t2<=n;t2++){
			if(t1==t2)continue;
			for(int k=1;k<=n;k++){
				long long h=tcc[t1][k]+tcc[k][t2];
				tcc[t1][t2]=min(tcc[t1][t2],h);
				tcc[t2][t1]=min(tcc[t1][t2],h);
			}
		}
	}
	for(int i=0;i<q;i++){ 
		int u,v;
		cin>>u>>v;
		long long th=ts[u]+ts[v],mi=INF;
		int sz1=zt[u].size(),sz2=zt[v].size();
		for(int t1=0;t1<sz1;t1++){
			for(int t2=0;t2<sz2;t2++){
				mi=min(mi,tct[u][t1]+tct[v][t2]+tcc[zt[u][t1]][zt[v][t2]]);
			}
		}
		cout<<mi+th<<endl;
	}
	return 0;
}