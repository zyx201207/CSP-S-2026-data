#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[500000+10];
struct node{
	int v,dis;
};
vector<node>edge[500000+10+500];
struct node2{
	int u,dis;
	bool operator>(const node2& a)const{
		return dis>a.dis;
	}
};
priority_queue<node2,vector<node2>,greater<node2>>qe;
int dis[500000+10+500];
bool f[500000+10+500];
void dij(int st,int ed){
	memset(dis,0x3f,sizeof(dis));
	memset(f,0,sizeof(f));
	qe.push({st,0});
	f[st]=1;
	dis[st]=0;
	while(!qe.empty()){
		node2 vv=qe.top();
		qe.pop();
		f[vv.u]=1;
		for(node vk:edge[vv.u]){
			if(f[vk.v]==true){
				continue;
			}
			f[vk.v]=true;
			if(dis[vk.v]>dis[vv.u]+vk.dis){
				dis[vk.v]=dis[vv.u]+vk.dis;				
			}
			qe.push({vk.v,vk.dis});
		}
	}
	return;
}
void solve2(){
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int a,t,u=m+i;
			cin>>a>>t;
			edge[a].push_back({u,t});
			edge[u].push_back({a,t});
		}
	}
	while(q--){
		int xk,yk;
		cin>>xk>>yk;
		dij(xk,yk);
		cout<<dis[yk]+w[xk]+w[yk]<<endl;
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);	
	cin>>c>>n>>m>>d>>q;
	solve2();
	return 0;
}
/*
41025
*/

