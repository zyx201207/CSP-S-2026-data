#include<bits/stdc++.h>
using namespace std;
const int N=505;
const int M=5e5+10;
int c,n,m,d,q1;
int k[N];
long long w[N];
int head[N];
int t[N][1005];
struct node{
	int to,next;
	long long t;
} edge_n[M];
struct point{
	int thr[21];
	int tail;
} edge_m[M];
int idx=0;
long long f[1005][1005];
void add(int x,int y,int value){
	edge_m[y].tail+=1;
    edge_m[y].thr[edge_m[y].tail]=x;
    idx+=1;
    edge_n[idx].t=value;
    edge_n[idx].to=y;
    edge_n[idx].next=head[x];
    head[x]=idx;
}
void find(int edge,int x,int t_p){
	int i=head[edge];
	while(i!=0){
		if(i==0) break;
		if(edge_n[i].to==x){
			f[x][x]=0;
		}else{
		    f[edge_n[i].to][x]=min(edge_n[i].t+t_p,f[edge_n[i].to][x]);
		    f[x][edge_n[i].to]=min(edge_n[i].t+t_p,f[x][edge_n[i].to]);
		}
		i=edge_n[i].next;
	}
	return ;
}
bool vis[N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q1;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++) head[i]=0;
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=2*k[i];j++) {
			int x;
			long long v;
			cin>>x>>v;
			t[i][x]=v;
			add(i,x,v);
		}
	}
	int q[100005][2];
	for(int i=1;i<=q1;i++){
		cin>>q[i][1]>>q[i][2];
	}     
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++) f[i][j]=1e18;
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=edge_m[i].tail;j++){
			int e=edge_m[i].thr[j];
			if(!vis[e]){
				find(e,i,t[i][e]);
			    vis[e]=true;
			}
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			if(i==j) continue;
			for(int k=1;k<=m;k++){
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
			}
		}
	}
	for(int i=1;i<=q1;i++){
		int ans=f[q[i][1]][q[i][2]]+w[q[i][1]]+w[q[i][2]];
		cout<<ans<<endl;
	}
	return 0;
}