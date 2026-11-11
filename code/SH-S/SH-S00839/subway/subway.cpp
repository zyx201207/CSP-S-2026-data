#include<bits/stdc++.h>
using namespace std;
const int M=2e3+5,N=1e5+5;
int c,n,m,d,q,w[M],k[M],a[N][M],t[N][M],x[N],y[N],vis[M][3],visx[N][M],minn,r;
int dfs(int num,int lx,int xl,int ht){//num:地铁站号码 lx:0口1厅2台 xl:当前在的站台线路 ht:已花费时间·
	vis[num][lx]=-1;
	if(num==y[r]&&lx==0){
		minn=min(minn,ht); 
		return 0;
	}
	if(lx==2){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=k[i];j++){
				if(vis[a[i][j]][1]==0){
					//cout<<a[i][j]<<" "<<1<<" "<<ht+t[i][j]<<"\n";
					dfs(a[i][j],1,i,ht+t[i][j]);
				}
			}
		} 
	}
	if(lx==1){
		for(int i=1;i<=m;i++){
			if(vis[num][0]==0){
				//cout<<num<<" "<<0<<" "<<ht+w[i]<<"\n";
				dfs(num,0,xl,ht+w[i]);
			}
		}
		for(int i=1;i<=k[num];i++){
			if(vis[num][2]==0){
				//cout<<num<<" "<<2<<" "<<ht+t[num][i]<<"\n";
				dfs(num,2,xl,ht+t[num][i]);
			}
		}
	}
	if(lx==0){
		for(int i=1;i<=m;i++){
			if(vis[num][1]==0){
				//cout<<num<<" "<<1<<" "<<ht+w[i]<<"\n";
				dfs(num,1,xl,ht+w[i]);
			}
		}
	}
	return 0;
} 
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int v=1;v<=m;v++){
		cin>>w[v];//口-厅 
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];//经过站数 
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];//a:经过站 t:厅-台 
		}
	}
	for(r=1;r<=q;r++){
		minn=1e7;
		for(int i=1;i<=m;i++){
			for(int j=0;j<=2;j++){
				vis[i][j]=0;
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				visx[i][j]=0;
			}
		}
		cin>>x[r]>>y[r];//起点终点 
		dfs(x[r],0,0,0);
		cout<<minn<<"\n";
	}
	return 0; 
}


