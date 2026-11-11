#include<iostream>
#include<vector> 
#include<algorithm>
#include<queue>
using namespace std;
#define int long long 
int a[5000005];
vector<pair<int,int> >e[5005005];
bool vis[5005005];
long long dis[500005];
	int t=500;
	priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >q;
void djk(int s){
	for(int ii=1;ii<=t;ii++){
		dis[ii]=100000000000ll;
		vis[ii]=0;
	} 
	while(!q.empty()){
		q.pop();
	}
	//cout<<s<<endl;
	dis[s]=0;
	//vis[s]=1;
	q.push({dis[s],s});
	while(!q.empty()){
		auto u=q.top();
		q.pop();
		int uu=u.second;
		if(vis[uu]){
			continue;
		}
		vis[uu]=1;
		for(auto v:e[uu]){
			if(dis[v.first]>dis[uu]+v.second){
				
				dis[v.first]=dis[uu]+v.second;
				
				q.push({dis[v.first],v.first});
			}
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int cc,n,m,d,q;
	cin>>cc>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		//cout<<k<<endl;
		int h=t+1;
		int gg=0;
		while(k--){
		int c,m;
		cin>>c>>m;
		if((++t)!=h){
			e[t].push_back({t-1,0});
			e[t-1].push_back({t,0});
		}
		e[c].push_back({t,m});
		e[t].push_back({c,m});
		gg=c;
	}
	}
	for(int i=1;i<=q;i++){
		int xk,yk;
		cin>>xk>>yk;
		djk(xk);
//		for(int j=1;j<=t;j++){
//		cout<<dis[j]<<" ";
//	}
		cout<<dis[yk]+a[xk]+a[yk]<<endl;
	}
	return 0;
}

