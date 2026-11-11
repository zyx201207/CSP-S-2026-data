#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
const int maxn=500010;
struct node{
	int next,to,len;
}edge[maxn*2];
int h[maxn],tot=2;
void add(int x,int y,int z){
	edge[tot++]=node{h[x],y,z};
	h[x]=tot-1;
}
int dis[maxn],vis[maxn],f[1100][1100];
int w[maxn];
priority_queue<pair<int,int> >q;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,p;
	cin>>c>>n>>m>>d>>p;
	for(int j=1;j<=m;j++){
		cin>>w[j];
	}
	for(int j=1;j<=n;j++){
		int k;
		cin>>k;
		for(int l=1;l<=k;l++){
			int a,t;
			cin>>a>>t;
			add(a,m+j,t);
			add(m+j,a,t);
		}
	}
	for(int i=1;i<=m;i++){
		int s=i;
		for(int j=0;j<maxn;j++){
			dis[j]=INT_MAX;
			vis[j]=0;
		}
		while(!q.empty()) q.pop();
		dis[s]=0;
		q.push({0,s});
		while(!q.empty()){
			int x=q.top().second;
			q.pop();
			if(vis[x]){
				continue ;
			}
			vis[x]=1;
			for(int j=h[x];j;j=edge[j].next){
				int to=edge[j].to;
				if(dis[to]>dis[x]+edge[j].len){
					dis[to]=dis[x]+edge[j].len;
					q.push({-dis[to],to});
				}
			}
		}
		for(int j=1;j<=m;j++){
			f[i][j]=dis[j];
		}
	}
//	cout<<"#";
//	for(int j=h[m+1];j;j=edge[j].next) cout<<edge[j].to<<" ";
//	cout<<endl;
	while(p--){
		int s,t;
		cin>>s>>t;
		cout<<f[s][t]+w[s]+w[t]<<endl;
	}

	return 0;
}
