#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#include<cstring>
#define int long long
using namespace std;
int a[500005];
//struct node{
//	int u,v;
//};
int g[1000][1000];
//void dij(int u){
//	queue<int> q;
//	d[u]=0;
//	vis[u]=1;
//	q.push(u);
//	int maxid=u;
//	while(!q.empty()){
//		int x=q.top();
//		q.pop();
//		for(auto p:g[x]){
//			if(d[x]+p.v<d[p.u]&&!vis[p.u]){
//				d[p.u]=d[x]+p.v;
//			}
//			int maxn=1145141919810;
//			for(int i=1;i<=m+n;i++){
//				if(vis[i]==0&&d[i]<maxn){
//					maxid=i;
//					maxn=d[i];
//				}
//			}
//			vis[maxid]=1;
//			q.push(maxid);
//		}
//	}
//}

signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
//	cin.tie(0);
//	cout.tie(0);
	int c,n,m,d,q,k;
	cin>>c>>n>>m>>d>>q;
	memset(g,0x3f,sizeof g);
	for(int i=1;i<=m;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			int a1,t1;
			cin>>a1>>t1;
			g[a1][m+i]=t1;
			g[m+i][a1]=t1;
		}
	}
	for(int i=1;i<=m+n;i++){
		for(int k1=1;k1<=m+n;k1++){
			for(int j=1;j<=m+n;j++){
				g[k1][j]=min(g[k1][i]+g[i][j],g[k1][j]);
//				cout<<g[i][k1]<<" ";
			}
		}
	}
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		cout<<a[x]+a[y]+g[x][y]<<endl;
	}
	return 0;
} 
