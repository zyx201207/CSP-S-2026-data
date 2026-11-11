#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+5;
int n,k; 
vector<int>vt[maxn]; 
int sum[maxn];//子树i如果不被解决的产生的花费  
int bfs(int x,int y,int xz){
	static int q[maxn],dt,dw,dis[maxn],fa[maxn];
	static bool vis[maxn],bj[maxn];
	dt=1,dw=0;
	for(int i=1;i<=n;i++){vis[i]=bj[i]=0;}
	q[++dw]=x,q[++dw]=y;
	dis[x]=dis[y]=0;
	bj[x]=bj[y]=vis[x]=vis[y]=1;
	while(dw-dt+1){
		int fff=q[dt++]; 
		for(int i:vt[fff]){
			if(vis[i]){continue;}
			vis[i]=1;
			dis[i]=dis[fff]+1;
			fa[i]=fff;
			q[++dw]=i;
		}
	}
	int hf=0;
	for(int i=1;i<=n;i++){
		if(dis[i]>xz){
			int x=i;
			for(int j=1;j<=xz;j++){
				x=fa[x];
				if(bj[x]){break;}
			}
			while(!bj[x]){
				bj[x]=1;
				hf++;
				x=fa[x];
			}
		}
	}
	return hf;
}
bool check(int x){
	for(int i=1;i<=n;i++){for(int j=1;j<=n;j++){if(i!=j){if(bfs(i,j,x)<=k-2){return 1;}}}}
	return 0;
}
void dd(){
	cin>>n>>k;
	for(int i=1;i<=n;i++){vt[i].clear();}
	for(int i=1;i<n;i++){
		int u,v;
		cin>>u>>v;
		vt[u].push_back(v);
		vt[v].push_back(u); 
	}
	int lt=-1,rt=n-k+2,mid;
	while(lt+1<rt){
		mid=lt+rt>>1;
		if(check(mid)){rt=mid;}
		else{lt=mid;}
	}
	cout<<rt<<'\n';
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int c,t;
	cin>>c>>t;
	while(t--){dd();}
	return 0;
}
/*
思路（预计思考到17:40） 
1.二分答案+判断可否实现，选两个点使得如果存在距离这两个点的距离超过mid则向那个方向多花费一些点补齐（单次补齐为一个路径）
时间复杂度O(n*n*nlogn)  30分 
*/
