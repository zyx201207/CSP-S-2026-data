#include <bits/stdc++.h>
using namespace std;

const int N=550,M=5e5+500;
int c,n,m,d,q,nd,tim,x,y;
//int tmp,tmptime;
int w[M],kk[N];
long long dis[N][N],ans;
bool isrp[M][N];
int numrp[M],rp[M][22];
long long trp[M][22];//roadpassed,time_roadpassed

//void output_dis(){
//	for(int i=1; i<=n; i++){
//		for(int j=1; j<=n; j++){
//			cout<<dis[i][j]<<" ";
//		}
//		cout<<endl;
//	}
//	cout<<endl<<endl;
//}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout); 
	cin>>c>>n>>m>>d>>q; 
	for(int i=1; i<=m; i++)scanf("%d",&w[i]);
	for(int i=1; i<=n; i++){
		scanf("%d",&kk[i]);
		for(int j=1; j<=kk[i]; j++){
			scanf("%d%d",&nd,&tim);
			isrp[nd][i]=1;
			rp[nd][++numrp[nd]]=i,trp[nd][numrp[nd]]=tim;
		} 
	}
	
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			if(i!=j)dis[i][j]=100000000000000;
		}
	}
	for(int i=1; i<=m; i++){
		for(int j=1; j<=numrp[i]; j++){
			for(int k=1; k<=numrp[i]; k++){
				if(j==k)continue;
				dis[rp[i][j]][rp[i][k]]=min(dis[rp[i][j]][rp[i][k]],trp[i][j]+trp[i][k]); 
			}
		}
	}
	//cout<<numrp[3]<<trp[][]endl;
	
	//output_dis();
	
	for(int k=1; k<=n; k++){
		for(int i=1; i<=n; i++){
			if(i==k)continue;
			for(int j=1; j<=500; j++){
				if(j==k||j==i)continue;
				if(dis[i][j]>dis[i][k]+dis[j][k]){
					dis[i][j]=dis[i][k]+dis[j][k];
				}
			}
		}
	}
	
	//output_dis();
	
	while(q--){
		ans=10000000000000000;
		scanf("%d%d",&x,&y);
		for(int i=1; i<=numrp[x]; i++){
			for(int j=1; j<=numrp[y]; j++){
				for(int k=1; k<=n; k++){
					ans=min(ans,w[x]+w[y]+trp[x][i]+trp[y][j]+dis[rp[y][j]][k]+dis[rp[x][i]][k]);
//					if(ans==32){
//						cout<<i<<" "<<j<<endl;
//					}
				}
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}