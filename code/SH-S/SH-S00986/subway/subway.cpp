#include <bits/stdc++.h>
using namespace std;


const unsigned long long N=500;
const unsigned long long M=500005;
unsigned long long c,n,m,d,q;
vector<pair<unsigned long long,unsigned long long> > G[M<<1];
unsigned long long w[M],vis[N],dis[N];
unsigned long long ans;
int main(){
	//ÏÈÕ¾Ìü£¬Õ¾Ì¨+=n 
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout); 
	cin>>c>>n>>m>>d>>q;
	for(unsigned long long i=1;i<=m;i++){
		cin>>w[i];
	} 
//	cout<<"A"<<endl;
	for(unsigned long long i=1;i<=n;i++){
		unsigned long long k;
		cin>>k;
		for(unsigned long long j=0;j<k;j++){
			unsigned long long v,w;
			cin>>v>>w;
			G[i+m].push_back({v,w});
			G[v].push_back({i+m,w});
		}
//		cout<<"B"<<endl;
	}
//	for(unsigned long long i=1;i<=m+n;i++){
//		for(unsigned long long j=0;j<G[i].size();j++){
//			cout<<i<<" to "<<G[i][j].first<<", cost="<<G[i][j].second<<endl;
//		}
//		cout<<endl;
//	}
	priority_queue<pair<unsigned long long,unsigned long long>,vector<pair<unsigned long long,unsigned long long> >,greater<pair<unsigned long long,unsigned long long> > > qu;
	for(unsigned long long e=1;e<=q;e++){
		unsigned long long l,r;
		cin>>l>>r;
		ans=w[l]+w[r];
		memset(vis,0,sizeof(vis));
		memset(dis,0x3f3f3f3f,sizeof(dis));
		dis[l]=0;
		vis[l]=1;
		while(qu.size()){
			qu.pop(); 
		}
		qu.push({0,l});
		while(!qu.empty()){
			unsigned long long u=qu.top().second;
			qu.pop();
			vis[u]=1;
			for(unsigned long long i=0;i<G[u].size();i++){
				unsigned long long v=G[u][i].first,w=G[u][i].second;
			//	cout<<u<<" linked "<<v<<" w="<<w<<endl;
				if(dis[v]>dis[u]+w&&!vis[v]){
					dis[v]=dis[u]+w;
					vis[v]=1;
				//	cout<<"dis["<<v<<"]="<<dis[v]<<endl;
					qu.push({dis[v],v});
				} 
			}
		}
		cout<<dis[r]+ans<<" ";
	}
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
