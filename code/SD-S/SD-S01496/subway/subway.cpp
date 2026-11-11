#include<bits/stdc++.h>
using namespace std;
struct node{
	int ry[550];
}tu[550];
struct node2{
	int u,di,num;
};
int c,n,m,d,q;
int w[5050];
int a[5010],b[5010];
vector<node2> g[1010];
int dis[550];
void bfs(int st,int ed){
	queue<int> q;
	q.push(st);
	memset(dis,0x3f,sizeof dis);
	dis[st]=w[st];
	while(!q.empty()){
		int op=q.front();
		q.pop();
		//cout<<op<<endl;
		for(int i=0;i<g[op].size();i++){
			node2 x=g[op][i];
			q.push(x.u);
			if(dis[x.u]>dis[op]+x.di){
				dis[x.u]=dis[op]+x.di;
			}
			if(x.u==ed){
				dis[x.u]+=tu[x.u].ry[x.num];
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c;
	cin>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		memset(a,0,sizeof a);
		memset(b,0,sizeof b);
		for(int j=1;j<=k;j++){
			int x,y;
			cin>>x>>y;
			a[j]=x,b[j]=y;
			tu[x].ry[i]=y;
		}
		for(int j=1;j<k;j++){
			if(j==1){
				if(i==1){
					g[a[j]].push_back({a[j+1],b[j],i});
				} 
				else{
					g[a[j]].push_back({a[j+1],b[j]+tu[a[j]].ry[i-1],i});
					
				} 
			}
			else if(j==k-1){
				g[a[j]].push_back({a[j+1],b[j+1],i});
			}
			else{
				g[a[j]].push_back({a[j+1],0,i});
			}
		}
	}
	
//	for(int i=1;i<=m;i++){
//		for(int j=0;j<g[i].size();j++){
//			cout<<i<<" "<<g[i][j].u<<" "<<g[i][j].di<<endl;
//		}
//	}
//	
	while(q--){
		int st,ed;
		cin>>st>>ed;
		bfs(st,ed);
		cout<<dis[ed]+w[ed]<<endl; 
	}
	return 0;
}
