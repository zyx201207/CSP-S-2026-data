#include<bits/stdc++.h>
using namespace std;
const int maxm=500005,maxn=505;
int c,m,n,d,q,x,y;
int w[maxm];//µØÌú¿Ú-Õ¾Ìü
struct node{
	int to,cst;
};
node make(int to,int cst){
	node nd;
	nd.cst=cst;
	nd.to=to;
	return nd;
}
int cur;
vector<node> a[maxn];
vector<node> sta[maxm];
bool vis_sta[maxm];
bool vis_li[maxn];
int dist[maxn][maxn];
node cost[maxn];
int head;
//int dist[maxn][maxm];
void dfs(int flg,int k){
	if(flg){
		for(int i=0;i<sta[k].size();i++){
			int to=sta[k][i].to;
			int cst=sta[k][i].cst;
			if(vis_li[to]) continue;
			//if(cur+cst>ans) continue;
			cur+=cst;
			vis_li[to]=true;
			cost[head].cst+=cst;
			cost[head].to=to;
			dfs(0,to);
			cost[head].cst-=cst;
			cur-=cst;
			vis_li[to]=false;
		}
	}
	else{
		for(int i=0;i<=head;i++){
			if(dist[cost[i].to][k]>cost[head].cst-cost[i].cst){
				dist[cost[i].to][k]=cost[head].cst-cost[i].cst;
				dist[k][cost[i].to]=cost[head].cst-cost[i].cst;
			}
		}
		for(int i=0;i<a[k].size();i++){
			int to=a[k][i].to;
			int cst=a[k][i].cst;
			if(vis_sta[to]) continue;
			//if(cur+cst>ans) continue;
			cur+=cst;
			vis_sta[to]=true;
			cost[head+1].cst=cost[head].cst+cst;
			head++;
			dfs(1,to);
			head--;
			cur-=cst;
			vis_sta[to]=false;
		}
	}
	return;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){//½¨Í¼ 
		int kk,to,cst;
		cin>>kk;
		//k[i]=kk;
		while(kk--){
			cin>>to>>cst;
			sta[to].push_back(make(i,cst));
			a[i].push_back(make(to,cst));
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++) dist[i][j]=100000000;
	}
	for(int i=1;i<=n;i++){
		memset(vis_sta,0,sizeof(vis_sta));
		memset(vis_li,0,sizeof(vis_li));
		cost[0].to=i;
		cost[0].cst=0;
		vis_li[i]=true;
		dfs(0,i);
		vis_li[i]=false;
	}
	/*
	for(int i=1;i<=n;i++){
		for(int j=0;j<a[i].size();j++) cout<<a[i][j].to<<" "<<a[i][j].cst<<endl;
		cout<<endl;
	}
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++) cout<<dist[i][j]<<" ";
		cout<<endl;
	}*/
	while(q--){
		cin>>x>>y;
		int ii,jj;
		int ans=100000000;
		for(int i=0;i<sta[x].size();i++){
			for(int j=0;j<sta[y].size();j++){
				if(ans>sta[x][i].cst+sta[y][j].cst+dist[sta[x][i].to][sta[y][j].to]){
					ans=sta[x][i].cst+sta[y][j].cst+dist[sta[x][i].to][sta[y][j].to];
					ii=i,jj=j;
				}
			} 
		}
		cout<<ans+w[x]+w[y]<<endl;
	}
	return 0;
}
