#include<bits/stdc++.h>
using namespace std;
const int N=1e4+66,M=5e5+66;
const long long INF=1e17+66;
int c,n,m,d,q,w[M];
struct node{
long long to,len;
};
vector<node>e[N];
long long dis[N][N];
bool operator<(node a,node b){
return a.len>b.len;
}
priority_queue<node>pq;
void ddd(int st,int now){
dis[st][now]=0;
pq.push(node{now,0});
while(!pq.empty()){
long long sh=pq.top().to,ch=pq.top().len;
if(dis[st][sh]!=ch) continue;
//cout<<st<<' '<<sh<<'\n';
pq.pop();
for(auto v:e[sh]){
long long chang=v.len;
if(dis[st][v.to]>ch+chang){
dis[st][v.to]=ch+chang;
pq.push(node{v.to,ch+chang});
}
}
}
//cout<<st<<'\n';
//for(int i=1;i<=m*2+n;i++) cout<<dis[st][i]<<' ';
//cout<<'\n';
}
int  main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d %d %d %d %d",&c,&n,&m,&d,&q);
	//cout<<n<<' '<<m<<'\n';
	for(int i=1;i<=2*m+n;i++){
	for(int j=1;j<=2*m+n;j++){
	dis[i][j]=dis[j][i]=INF;
	}
	}
	for(int i=1;i<=m;i++){
	scanf("%d",&w[i]);
	e[i].push_back(node{m+i,w[i]});
	e[m+i].push_back(node{i,w[i]});	
	}
	for(int i=1;i<=n;i++){
	int k;
	scanf("%d",&k);
	for(int j=1;j<=k;j++){
	int a,b;
	scanf("%d %d",&a,&b);
	e[a].push_back(node{m+m+i,b});
	e[m+m+i].push_back(node{a,b});
	}
	}
	for(int i=1;i<=m;i++){
	ddd(i,m+i);
	}
	for(int i=1;i<=q;i++){
	int x,y;
	scanf("%d %d",&x,&y);
//	cout<<x<<' '<<y<<' ';
	printf("%lld\n",dis[x][m+y]);
	}
	return 0;
} 
