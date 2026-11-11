#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,a[500005],dis[500005];
vector<pair<int,int>>vec[500005];
bool y[500005];
struct node{
	int v,w;
};
operator < (node a,node b){
	return a.w>b.w;
}
void dij(int s){
	priority_queue<node>q;
	q.push({s,0});
	for(int i=1;i<=m;i++){
		dis[i]=INT_MAX;
		y[i]=0;
	}
	dis[s]=0;
	while(!q.empty()){
		int x=q.top().v;
		q.pop();
		if(y[x])continue;
		y[x]=1;
		for(auto i:vec[x]){
			int vv=i.first,ww=i.second;
			if(dis[vv]>dis[x]+ww){
				dis[vv]=dis[x]+ww;
				q.push({vv,dis[vv]});
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	if(m<=5000&&m<q){
	int qq[5005][5005];
	for(int i=1;i<=m;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		int t;
		cin>>t;
		int x1,y1,x2,y2;
		cin>>x1>>y1>>x2>>y2;
		vec[x1].push_back({x2,y1+y2});
		vec[x2].push_back({x1,y1+y2});
	}
	for(int i=1;i<=m;i++){
		dij(i);
		for(int j=1;j<=m;j++){
			qq[i][j]=dis[j];
		}
	}
	while(q--){
		int s,t;
		cin>>s>>t;
		cout<<qq[s][t]+a[s]+a[t]<<endl;
 	}
 	}
 	else{
 		for(int i=1;i<=m;i++)cin>>a[i];
		for(int i=1;i<=n;i++){
			int t;
			cin>>t;
			int x1,y1,x2,y2;
			cin>>x1>>y1>>x2>>y2;
			vec[x1].push_back({x2,y1+y2});
			vec[x2].push_back({x1,y1+y2});
		}
		while(q--){
			int s,t;
			cin>>s>>t;
			dij(s);
			cout<<dis[t]+a[s]+a[t]<<endl;
	 	}
	}
	return 0;
}
