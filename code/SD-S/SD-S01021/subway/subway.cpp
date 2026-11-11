#include<bits/stdc++.h>
using namespace std;
long long w[500010];
vector<vector<long long> > cost;
struct node{
	long long pos,t;
};
struct point{
	long long pos,lenth;
	bool operator<(const point other)const{
		return lenth<other.lenth;
	}
};
//bool visited[510000];
vector<vector<node> > tu(501000);
void diji(long long dian){
	priority_queue<point> q;
	q.push({dian,0});
	while(!q.empty()){
		point now=q.top();
		q.pop();
		for(auto it:tu[now.pos]){
//			if(!visited[it]){
//				visited[it]=1;
//			}
			if(it.t+now.lenth<cost[dian][it.pos]){
				cost[dian][it.pos]=it.t+now.lenth;
				q.push({it.pos,cost[dian][it.pos]});
			}
			
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);	
	

	long long c,n,m,d,q,k,a,t,x,y;
	cin>>c>>n>>m>>d>>q;
	cost.resize(m+n+1); 
	for(int i=1;i<=m;i++){
//		memset(cost[i],0x3f,);
		cin>>w[i];
	}
	for(int i=1;i<=n+m;i++){
		cost[i].resize(m+n+1);
		fill(cost[i].begin()+1,cost[i].begin()+1+m+n,LLONG_MAX);
	}
	for(int i=1;i<=n;i++){ //表示第i条线路经过的地铁站数。第i条线路作为一个点，其从m+1开始
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a>>t;
			tu[i+m].push_back({a,t});
			tu[a].push_back({i+m,t});
		}
	}
//	for(int i=1;i<=n+m;i++){
//		cout<<i<<": ";
//		for(auto it:tu[i]){
//			cout<<it.pos<<" "<<it.t<<"  ";
//		} 
//		cout<<endl;
//	}
//	cout<<n+m<<"\n\n\n";
//	cout<<cost.size()<<"\n\n\n"<<cost[7].size()<<"\n";
//	cout<<cost[7][7];
//	cout<<cost[n+m-1][n+m-1];
	for(int i=1;i<=n+m;i++) cost[i][i]=0;	
	for(int i=1;i<=m;i++){
		diji(i); 
	}
//	for(int i=1;i<=m+n;i++){
//		for(int j=1;j<=m+n;j++){
//			cout<<cost[i][j]<<" ";
//		}
//		cout<<endl;
//	}
	for(int i=1;i<=q;i++){
		cin>>x>>y;
		cout<<cost[x][y]+w[x]+w[y]<<"\n";
	}
	
//	cout<<ans;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/
