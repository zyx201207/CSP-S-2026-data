#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,n,m,d,q;
int w[500005];
int k[500005],a[505][5005];
int t[505][5005];
struct Node{
	int u,v,w;
}edge[500005];
int head[5005],tot;
void add(int u,int v,int w){
	edge[++tot]=(Node){head[u],v,w};
	head[u]=tot;
}
int both[500005];
bool vis[1005][1005];//记录每条路线经过的车站
bool vis1[80005];
int dis[80005];
void spfa(int st){
	queue<int>q1;
	vis1[st]=1,dis[st]=0;
	q1.push(st);
	while(!q1.empty()){
		int s=q1.front();
		q1.pop();
		vis1[s]=0;
		for(int i=head[s];i;i=edge[i].u){
			int v=edge[i].v,w=edge[i].w;
			//cout<<dis[7]<<" ";
			if(dis[v]>dis[s]+w){
				dis[v]=dis[s]+w;
				if(vis1[v]==0){
					vis1[v]=1;
					q1.push(v);
				}
			}
		}
	}
}
int arr[505][50005];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
			arr[i][a[i][j]]=t[i][j];
			vis[i][a[i][j]]=1;
		}
		for(int j=1;j<k[i];j++){
			for(int t=j+1;t<=k[i];t++){
				add(a[i][j]+(i-1)*m,a[i][t]+(i-1)*m,0);
				add(a[i][t]+(i-1)*m,a[i][j]+(i-1)*m,0);
			}
		}
	}
	for(int i=1;i<=m;i++){
		int r=0;
		for(int j=1;j<=n;j++){
			if(vis[j][i]){//第j条路线经过车站i 
				both[++r]=j;
			}
		}
		for(int j=1;j<r;j++){
			for(int k=j+1;k<=r;k++){
				int x=i+(both[j]-1)*m,y=i+(both[k]-1)*m;
				add(x,y,arr[both[j]][i]+arr[both[k]][i]),add(y,x,arr[both[j]][i]+arr[both[k]][i]);
				//cout<<both[j]<<" "<<both[k]<<"\n";
				//cout<<x<<" "<<y<<" "<<arr[both[j]][i]<<" "<<arr[both[k]][i]<<"\n";
			}
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		int ans1=0x3f3f3f3f3f3f3f;
		for(int i=0;i<n;i++){
			memset(vis1,0,sizeof vis1);
			memset(dis,0x3f3f,sizeof dis);
			int st=x+i*m;
			spfa(st);
			int ans=0x3f3f3f3f3f3f3f;
			for(int j=0;j<n;j++){
				if(dis[y+j*m]<=0x3f3f3f3f3f3f){
					ans=min(ans,dis[y+j*m]+arr[j+1][y]);
					//cout<<st<<" "<<y+j*m<<" "<<dis[y+j*m]<<"\n";
				}
			}
			ans1=min(ans1,ans+arr[i+1][x]);
		}
		cout<<ans1+w[x]+w[y]<<"\n";
	}
	return 0;
}