#include<bits/stdc++.h>
using namespace std;
long long c, n,m,d,q;long long dist[10005];
long long  pos[1005][2];
vector<long long>t[10005]; 
 map<int,long long>mp;
 vector<pair<long long,long long > >w[1005];
  //vector<long long >z[10005];
 void in(){cin>>c>>n>>m>>d>>q;
 for(int i=0 ;i<m;i++){
 long long qw;
 cin>>qw;
 mp[i].insert(qw);
} 
 for( int j=0;j<n;j++){
 	int k;
 cin>> k;
 for(int i=0;i<2*k;i+=2){ 
 long long u,d;
 cin>>u>>d;
 d+=mp[u];
 w[k].push_back({u,d});
 }}
 for(int g=0;g<q;g++){
  cin>>pos[g][1];
  cin>>pos[g][2];
 }}
 long long  bfs[](long long c,long long p,long long dist[]){
 	 
 	priority_queue<pair<long long,long long > >dj;
	 dj.push(p,w[p]);
	 dist[p]=w[p];
	 while(!dj.empty){long long v=dj.top();
	 dj.pop();
	 for(auto &e:w[v]){
	 	long long u=e.first;
	 	long long as=e.second;
	 	if(dist[u]>e) continue;
	 	jf(dist[u]>dist[v]+as) dist[u]=dist[v]+as
	 	dj.push({u,dist[u]})
	 	bfs(u,v,dist[u]);
	 }}
	 return dist;
	  
 }
 
int main(){
freopen("subway.in","r",stdin);
freopen("subway.out","w",stdout); 
in();
int ans[1005];
for(int i=0£»i<q;i++ ){ 
   bfs(pos[i][1]);
   ans[i]=dist[pos[i][2]] ;}
int T=ans.size()
for (int i=0;i<T;i++){
	cout<<ans[i];
}
return 0;
}
  




}
