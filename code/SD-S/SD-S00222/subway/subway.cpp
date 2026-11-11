#include<bits/stdc++.h>
#define int long long
using namespace std;
const int M=8e4+10,N=510;
vector<pair<int,int>>g[M];
int w[M],k[N],dis[M];
vector<int> a[N],t[N];
void dijk(int x){
	memset(dis,0x3f,sizeof dis);
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>> >q;
	q.push({dis[x]=0,x});
	while(!q.empty()){
		int u=q.top().second,f=q.top().first;q.pop();
		if(f!=dis[u])continue; 
		for(auto p:g[u]){
			int w=p.second,v=p.first;
			if(dis[u]+w<dis[v])q.push({dis[v]=dis[u]+w,v});
		}
	}
}
signed main(){
	int c,n,m,d,q;cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			int a1,a2;cin>>a1>>a2;
			a[i].push_back(a1);t[i].push_back(a2);
			//p[a1].push_back({i,a2});
		}
	}
	int tot=(n+1)*m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=k[i];j++){
			for(int l=j;l<=k[i];l++){
				if(j==l){
					g[j+i*m].push_back({(n+1)*m+j,t[i][j-1]});
					g[j].push_back({(n+1)*m+j,0});
					//g[j].push_back({tot,0});
					g[(n+1)*m+j].push_back({j+i*m,t[i][j-1]});
				}else{
					g[j+i*m].push_back({l+i*m,t[i][l-1]});
					g[l+i*m].push_back({j+i*m,t[i][j-1]});
				}
			}
		}
	}
	for(int i=1;i<=q;i++){
		int u,v,res=0x3f3f3f3f3f3f3f3f;cin>>u>>v;
		dijk(u);
		for(int i=1;i<=n;i++){
			//cout<<t[i][v-1]+w[v]+w[u]<<endl;
			res=min(dis[v+i*m]+t[i][v-1]+w[v]+w[u],res);
		}
		cout<<res<<endl;
	}
	return 0;
}
/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3

*/
/*
0 2 4 2 1
1 2 3 4
3 1 1 2 2 3 3
2 2 2 4 4
1 4
*/
