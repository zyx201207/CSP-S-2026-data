#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q;//编号、线路数、站数、站最多几条线路,出行计划数
long long w[505];//站的口走到站厅需要的时间。
long long k[505];// 第i条线路经过的站数
long long an[505][505];//第i站线路
long long aa[505];//第i站线路数
long long a[505][505];//j站的站厅走到第i条线路的站台时间
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			int ai,t;
			cin>>ai>>t;
			an[ai][i]=1;
			aa[ai]++;
			a[ai][i]=t;
		}
	}
	for(int i=1;i<=q;i++){
		long long x,y,ans=INT_MAX;//起点和终点站编号,ans
		//long long xz=1,yz=1,xyzcnt=0;//厅到min台
		cin>>x>>y;
		for(int j=1;j<=aa[x];j++){
			//cout<<j<<" "<<an[x][j]<<" "<<an[y][j]<<endl;
			if(an[x][j]==1&&an[y][j]==1){//一个线路?
				ans=min(w[x]+w[y]+a[x][j]+a[y][j],ans);
			}
		}
		if(ans!=INT_MAX){
			cout<<ans<<endl;
			 break;
		 }
		long long box=INT_MAX,b=0,xx=0,yy=0;//find the smallest changing station
		for(long long i=1;i<=m;i++){
			for(long long xz=1;xz<=n;xz++){
				for(long long yz=1;yz<=n;yz++){
					if(xz==1&&yz==2&&i==2){
						//cout<<an[i][xz]<<an[i][yz]<<an[x][xz]<<an[y][yz];
					}
					if(an[i][xz]==1&&an[i][yz]==1&&(a[i][xz]+a[i][yz])<box&&an[x][xz]==1&&an[y][yz]==1){
						box=a[i][xz]+a[i][yz];
						b=i;
						xx=xz;
						yy=yz;
					}
				}
			}
		}
		//cout<<xx<<" "<<yy<<" "<<b<<endl;
	ans=w[x]+w[y]+a[x][xx]+a[y][yy]+a[b][xx]+a[b][yy];
	cout<<ans<<endl;
}
	return 0;
}
