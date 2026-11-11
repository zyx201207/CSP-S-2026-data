#include<bits/stdc++.h>
#define int long long
using namespace std;
int kk,c,n,m,d,qw,w[1000005],vis[1000005],ju[1000005];
struct node {
	int x,y;
};
vector<node>q[1000005];
priority_queue<int>p;
void dij(int st){
	memset(vis,0,sizeof(vis));
	memset(ju,0x3f,sizeof(ju));
	p.push(st);
	ju[st]=0;
	while(!p.empty()){
		int qp=p.top();
		p.pop();
		vis[qp]=1;
		for(int i=0;i<q[qp].size();i++){
			int x=q[qp][i].x,y=q[qp][i].y;
			if(!vis[y]&&ju[y]>ju[qp]+x){
				ju[y]=ju[qp]+x;
				p.push(y);
			}
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>n>>m>>d>>qw;
	memset(ju,0x3f,sizeof(ju));
	for(int i=1;i<=m;i++){
		cin>>w[i]; 
	}
	
	
	
	for(int i=1;i<=n;i++){
		cin>>kk;
		int x,y;
		for(int j=1;j<=kk;j++){
			cin>>x>>y;
			q[x].push_back({y,m+i});
			q[m+i].push_back({y,x}); 
		}
	}
	
	int x,y;
	for(int i=1;i<=qw;i++){
		cin>>x>>y;
		dij(x);
		cout<<ju[y]+w[x]+w[y]<<endl;
	}
	return 0;
}
