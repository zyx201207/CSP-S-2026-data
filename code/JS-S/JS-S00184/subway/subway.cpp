#include<bits/stdc++.h>
#define int long long
using namespace std;
struct node{
	int a;
	int t;
};
struct sd{
	int v;
	int w;
};
int c,n,m,d,q,zigma_k;
int w[500005];
int k[505];
vector<node> station[505];
int dist[405][405];//case 1-8
int T;
bool specialb=1;
vector<sd> son[20001];
int flag[200001];
int qq[200001];
int bfs(int x,int y){
	int head=0;
	int tail=0;
	qq[head]=x;
	head++;
	flag[x]=1;
	while(head>tail){
		int xx=qq[tail];
		if(xx==y) return flag[xx]-1;
		tail++;
		for(int i=0;i<son[xx].size();i++){
			if(flag[son[xx][i].v]==0){
				qq[head]=son[xx][i].v;
				head++;
				flag[son[xx][i].v]=flag[xx]+1;
			}
		}
	}
	return 0;
}
main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		zigma_k+=k[i];
		for(int j=1;j<=k[i];j++){
			node d;
			cin>>d.a>>d.t;
			station[i].push_back(d);
			if(T==0){//case12-19
				T=d.t;
			}
			else if(T!=0&&T!=d.t) specialb=0;
		}
	}
if(zigma_k<=400){//case 1-8
	for(int i=0;i<405;i++){
		for(int j=0;j<405;j++){
			dist[i][j]=INT_MAX;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<(int)station[i].size();j++){
			for(int k=0;k<(int)station[i].size();k++){
				if(j==k) continue;
				dist[station[i][j].a][station[i][k].a]=min(dist[station[i][j].a][station[i][k].a],station[i][j].t+station[i][k].t);
			}
		}
	}
	for(int k=1;k<=m;k++){//kij
		for(int i=1;i<=m;i++){
			for(int j=1;j<=m;j++){
				if(i==j) continue;
				dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
			}
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		cout<<dist[x][y]+w[x]+w[y]<<endl;
	}
	return 0;
}
	for(int i=1;i<=n;i++){
		for(int j=0;j<(int)station[i].size();j++){
			for(int k=0;k<(int)station[i].size();k++){
				if(j==k) continue;
				son[station[i][j].a].push_back({station[i][k].a,station[i][j].t+station[i][k].t});
				son[station[i][k].a].push_back({station[i][j].a,station[i][j].t+station[i][k].t});
			}
		}
	}
	while(q--){
		for(int i=0;i<20000;i++) flag[i]=0;
		int x,y;
		cin>>x>>y;
		cout<<w[x]+w[y]+bfs(x,y)*T*2<<endl;
	}
	return 0;
}
