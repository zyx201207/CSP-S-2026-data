//SN-S00659 马星辰 西安市曲江第一学校 
#include <bits/stdc++.h>
using namespace std;
int n,c,m,d,pla,sta,en,ans=100000000,k[510],w[500010];
struct node{
	int t,b;
	bool a;
};
node zk[510][50010];
bool f[510][50010];
//ti,j表示 i号线第j站大厅到i号站台时间 
//c表示编号,wi表示i站点入口到大厅的时间 
//ai,j表示i号线经过哪些站 
//n表示线路总数，m表示站点总数，d表示一个站点最多能连d条线
//pla表示计划数，sta表示起点，en表示终点，ki表示 i号线经过几个站点 
void dfs(int id,int p,int pid,int sum){
	if(p==en){
		ans=min(ans,sum+w[en]+zk[id][pid].t);
		return ;
	}
	if (sum>=ans) return ;
	if (pid!=k[id]&&f[id][zk[id][pid+1].b]==0){
		f[id][zk[id][pid+1].b]=1;
		dfs(id,zk[id][pid+1].b,pid+1,sum);
		f[id][zk[id][pid+1].b]=0;
	}
	if (pid!=1&&f[id][zk[id][pid-1].b]==0){
		f[id][zk[id][pid-1].b]=1;
		dfs(id,zk[id][pid-1].b,pid-1,sum);
		f[id][zk[id][pid-1].b]=0;
	}
	int ppid=pid;
	for (int i = 1;i <= n;i++){
		if (zk[i][p].a==1){
			for (int j = 1;j <= k[i];j++){
				if (zk[i][j].b==p){
					pid=j;
					break;
				}
			}
			if (pid!=k[i]&&f[i][zk[i][pid+1].b]==0){
				f[i][zk[i][pid+1].b]=1;
				dfs(i,zk[i][pid+1].b,pid+1,sum+zk[i][pid].t+zk[id][ppid].t);
				f[i][zk[i][pid+1].b]=0;
			}
			if (pid!=1&&f[i][zk[i][pid-1].b]==0){
				f[i][zk[i][pid-1].b]=1;
				dfs(i,zk[i][pid-1].b,pid-1,sum+zk[i][pid].t+zk[id][ppid].t);
				f[i][zk[i][pid-1].b]=0;
			}	
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>pla;
	for (int i = 1;i <= m;i++){
		cin>>w[i];
	} 
	for (int i = 1;i <= n;i++){
		cin>>k[i];
		for (int j = 1;j <= k[i];j++){
			cin>>zk[i][j].b>>zk[i][j].t;
			zk[i][zk[i][j].b].a=1; 
		}
	}
	for (int pl=1;pl<=pla;pl++){
		cin>>sta>>en;
		ans=100000000;
		memset(f,0,sizeof f);
		for (int i = 1;i <= n;i++){
			for (int j = 1;j <= k[i];j++){
				if (zk[i][j].b==sta){
					dfs(i,sta,j,w[sta]+zk[i][j].t);
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
