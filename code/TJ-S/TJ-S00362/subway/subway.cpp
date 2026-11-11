#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;//测试点编号、地铁线路数、地铁站数、每个地铁站最多被几条线路经过，出行计划数 
int a[505][100005][2];
int tb[100005][3];
int wt[100005][100005];
int dfs(int x,int y,int w){
//corr<<x<<'*'<<y<<endl;
	if(x==y)return tb[y][0];
	if(wt[x][y]!=0) return wt[x][y];
	int minn=1000000007;
	for(int i=1;i<=n;i++){
		while(a[i][x][0]!=1&&i<=n)i++;
		if(w==i)continue;
		for(int j=1;j<=m;j++){
//corr<<i<<'/'<<j<<endl;
			if(a[i][j][0]==1&&tb[j][1]==0){
				tb[j][1]=1;
				minn=min(minn,dfs(j,y,i)+a[i][j][1]+a[i][x][1]);
				tb[j][1]=0;
			}
		}
	}wt[x][y]=minn;
	return minn;
} 
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>tb[i][0];
	}for(int i=1;i<=n;i++){
		cin>>a[i][0][0];
		for(int j=1;j<=a[i][0][0];j++){
			int dp;
			cin>>dp;
			cin>>a[i][dp][1];
			a[i][dp][0]=1;a[0][dp][0]++;
		}
	}
//corr<<"------------\n";for(int i=0;i<=n;i++){for(int j=0;j<=m;j++){
//corr<<a[i][j][0]<<' ';}
//corr<<"\n";} 
	for(int aaaaa=0;aaaaa<q;aaaaa++){
		int x,y;
		cin>>x>>y;
		tb[x][1]=1;
		cout<<dfs(x,y,0)+tb[x][0]<<endl;
		tb[x][1]=0;
	} 
	return 0;
}
