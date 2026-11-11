#include<bits/stdc++.h>
using namespace std;
const int N=510;
const int M=5e5+10;
long long F[N][N];//线路换乘（最短路数组） ,初始的“边”（直接换乘）也是这个数组 
struct node{
	int bian;//线路编号
	long long v;//换乘时间 
};
struct NODE{//车站 
	node a[25];
	int top=0;
	long long v;//进出站时间 
}Sta[M];//空间复杂度大约25*5e5<2e7,共不超过4e7个long long变量，空间小于400MB
int c,n,m,d,T;
void Floyd(){
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=i;j++){
				if(F[i][k]!=-1&&F[j][k]!=-1){
					if(F[i][j]==-1){
						F[i][j]=F[j][i]=F[i][k]+F[k][j];
					}
					else{
						F[i][j]=F[j][i]=min(F[i][j],F[i][k]+F[k][j]);
					}
				}
			}
		}
	}
	return  ;
} 
void init(){
	for(int i=1;i<=n;i++){
		int the;
		cin>>the;//经过多少个站 
		for(int j=1;j<=the;j++){
			int x,y;
			cin>>x>>y;
			Sta[x].a[++Sta[x].top]={i,y};
		} 
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<i;j++){
			F[i][j]=F[j][i]=-1;
		}
		F[i][i]=0;
	}
	for(int i=1;i<=m;i++){//遍历每一个车站，建图 注意：这里的复杂度并不是m*d*d，而是k的和乘上d，也就是m*d 的数量级 
		for(int j=1;j<=Sta[i].top;j++){
			for(int k=1;k<j;k++){
				long long the=Sta[i].a[j].v+Sta[i].a[k].v;//2e9,long long是因为后面有min 
				int tj=Sta[i].a[j].bian;
				int tk=Sta[i].a[k].bian;
				if(F[tj][tk]==-1){
					F[tj][tk]=F[tk][tj]=the;
				}
				else{
					F[tj][tk]=F[tk][tj]=min(F[tj][tk],the);
				}
			}
		}
	}
	return ;
}
long long ans=1e16;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>n>>m>>d>>T;
	for(int i=1;i<=m;i++){
		cin>>Sta[i].v;
	}
	init();
		Floyd();

/*	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cout<<F[i][j]<<" ";
		}
		cout<<endl;
	}*/
//	cout<<F[1][1]<<" "<<F[1][2]<<endl<<F[2][1]<<" "<<F[2][2]<<endl;
	while(T--){
		int x,y;
		cin>>x>>y;
		if(x==y){//特判边界，防止无效运动 
			cout<<0<<endl;
			continue;
		}
		ans=1e16;//仅换乘的步行时间加上走到站厅的步行时间，进出站的时间因为固定未计算 
		for(int i=1;i<=Sta[x].top;i++){
			for(int j=1;j<=Sta[y].top;j++){
				int ti=Sta[x].a[i].bian;
				int tj=Sta[y].a[j].bian;
				if(F[ti][tj]!=-1){
					ans=min(ans,F[ti][tj]+Sta[x].a[i].v+Sta[y].a[j].v);
				}
			}
		}
		cout<<ans+Sta[x].v+Sta[y].v<<endl;
	}
	return 0;
}
