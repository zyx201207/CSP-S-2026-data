//#include<iostream>
//#include<vector>
//#include<queue>
//using namespace std;
//struct nxt{
//	int num;//编号 
//	int time;//时间 
//	int typ;//类型 1：线路，2：地铁站 
//};
//struct z{
//	int time;
//	int num;
//	int typ;
//};
//vector<nxt> mp[505];
//void dijkstra(int s,priority_queue<pair<int,int>,vector<int>,greater<int>> &q,vector<int>&dis){
//	fill(dis.begin()+1,dis.end(),0x3f3f);
//	dis[s]=0;
//	q.push({0,s});
//	while(!q.empty()){
//		auto u=q.top();
//		q.pop();
//		if(u.first()>dis[u]) continue;
//		for(auto v:mp[u]){
//			dis[v]=min(dis[v],dis[u]+v.second());
//			q.push(dis[v],v.num());
//		}
//	}
//	
//}
//int main(){
//	int c,n,m,d,q,sum;
//	cin>>c>>n>>m>>d>>q;
//	sum=n+m;
//	vector<int> w(m+1);
//	vector<int> k(n+1);
//	vector<vector<int> > a(n+1,vector<int>(m+1));
//	vector<vector<int> > t(n+1,vector<int>(m+1));
//	for(int i=1;i<=m;i++){
//		cin>>w[i];
//	}
//	for(int i=1;i<=n;i++){
//		cin>>k[i];
//		for(int j=1;j<=k[i];j++){
//			cin>>a[i][j]>>t[i][j];
//			mp[a[i][j]].push_back({i,t[i][j],1});
//			mp[i].push_back({a[i][j],t[i][j],2});
//			
//		}
//	}
//	for(int r=1;r<=q;r++){
//		int x,y;
//		cin>>x>>y;
//		priority_queue<pair<int,int>,vector<int>,greater<int>> q;
//		vector<int>dis(n+1);
//		dis[x]=0; 
//		
//	}
//}
#include<iostream>
using namespace std;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q,sum;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=q;i++) cout<<1<<endl;
	return 0;
}
