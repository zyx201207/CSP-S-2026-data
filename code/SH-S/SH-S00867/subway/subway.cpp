#include <bits/stdc++.h>
using namespace std;
#define int long long
//将路程从站-...-站-...-站 转化为 站-线路-...-线路-站 

//我忘记了floyd，我是糖笔吧
//要滚回入门组了 

//CCF orz orz orz orz
//评测机评测机你跑快点吧 

int w[1000000];vector<int> son[1000000];
vector<int> a[600000],b[600000];int ut[501][501],dis[501][501];

signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			ut[i][j]=LLONG_MAX/2;
			dis[i][j]=LLONG_MAX/2;
		}
	}
	for(int i=1;i<=n;i++){
		int k;cin>>k;
		for(int j=1;j<=k;j++){
			int p,t;cin>>p>>t;
			a[p].push_back(t);
			b[p].push_back(i);
			for(int l=0;l<a[p].size()-1;l++){
				ut[i][b[p][l]]=min(ut[i][b[p][l]],a[p][l]+t);
				ut[b[p][l]][i]=ut[i][b[p][l]];
			}
		}
	}
	for(int i=1;i<=n;i++){
		dis[i][i]=0;
		priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > pq;
		pq.push(make_pair(0,i));
		while(!pq.empty()){
			int d=pq.top().first,x=pq.top().second;
			pq.pop();
			if(dis[i][x]!=d) continue;
			for(int j=1;j<=n;j++){
				if(dis[i][j]>dis[i][x]+ut[x][j]){
					dis[i][j]=dis[i][x]+ut[x][j];
					pq.push(make_pair(dis[i][j],j));
				}
			}
		}
	}
	/*
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cout<<dis[i][j]<<" ";
		}
		cout<<endl;
	}
	*/
	while(q--){
		int u,v;cin>>u>>v;int minn=LLONG_MAX/2;
		for(int i=0;i<a[u].size();i++){
			for(int j=0;j<a[v].size();j++){
				minn=min(minn,a[u][i]+a[v][j]+dis[b[u][i]][b[v][j]]); 
			}
		}
		cout<<minn+w[u]+w[v]<<"\n";
	}
	return 0;
}
