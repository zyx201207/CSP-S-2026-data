#include<iostream>
#include<cstdio>
using namespace std;
const int N=505,M=500005;
int c,n,m,d,q,v[M],ans=0x3f3f3f3f;
//测试点 线数 站数 最多几线换乘 计划数 
int k[N],a[N][M],t[M],cnt[M];
struct transfer{
	int line_,time_;
}station[M][25];
int transfertime[N][N];
//第i个站厅能到达的站台及时间 
int finishh[M];
//void dfs(int x,int step){
//	for(int i=1;i<=cnt[x];i++){
//		
//	}
//}
int main(){
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>v[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[j];
			station[a[i][j]][++cnt[a[i][j]]].line_=i;
			station[a[i][j]][cnt[a[i][j]]].time_=t[j];
		}
	}
//	for(int i=1;i<=m;i++){
//		cout<<i<<"号站";
//		for(int j=1;j<=cnt[i];j++){
//			cout<<station[i][j].line_<<" ";
//		}
//		cout<<endl;
//	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=k[i];j++){
			for(int l=1;l<=cnt[a[i][j]];l++){
				if(station[a[i][j]][l].line_!=i)
				transfertime[i][station[a[i][j]][l].line_]=
					max(transfertime[i][station[a[i][j]][l].line_],
						station[a[i][j]][i].time_+station[a[i][j]][l].time_);
				
			}
		}
	}
	
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=k[i];j++){
//			for(int l=1;l<=cnt[a[i][j]];l++){
//				if(station[a[i][j]][l].line_!=i) cout<<i<<"号线换乘"<<station[a[i][j]][l].line_<<"线 需"<<transfertime[i][station[a[i][j]][l].line_]<<endl;
//			}
//		}
//	}
	while(q--){
		int x,y;
		cin>>x>>y;int ans=0x3f3f3f3f;
		for(int i=1;i<=cnt[x];i++){
			for(int j=1;j<=cnt[y];j++){
				
				if(station[x][i].line_==station[y][j].line_){
					ans=min(ans,station[x][i].time_+station[y][j].time_+v[x]+v[y]);
				}
				else if(transfertime[station[x][i].line_][station[y][j].line_]!=0)
				ans=min(ans,station[x][i].time_+station[y][j].time_+transfertime[station[x][i].line_][station[y][j].line_]+v[x]+v[y]);
				if(c<=3){
					if(station[x][i].line_==1&&station[y][j].line_==2){
						ans=min(ans,station[x][i].time_+station[y][j].time_+v[x]+v[y]+transfertime[1][3]+transfertime[2][3]);
					}
					else if(station[x][i].line_==1&&station[y][j].line_==3){
						ans=min(ans,station[x][i].time_+station[y][j].time_+v[x]+v[y]+transfertime[1][2]+transfertime[2][3]);
					}
					else if(station[x][i].line_==3&&station[y][j].line_==2){
						ans=min(ans,station[x][i].time_+station[y][j].time_+v[x]+v[y]+transfertime[1][3]+transfertime[2][1]);
					}
				}
			
			}
			
		}
		cout<<ans<<endl;
//		for(int i=1;i<=cnt[y];i++){
//			finishh[station[y][i].line_]=1;
//		}
//		ans=0x3f3f3f3f;
//		dfs(x,v[x]+v[y]);
//		cout<<ans;
	}
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/
