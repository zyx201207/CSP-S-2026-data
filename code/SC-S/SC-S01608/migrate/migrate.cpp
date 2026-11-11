#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,T;
int n,d;
int x[2000005];
int dis[5005];
int wy[5005];
int dif[5005];
int fd[2000005];
//vector<int>f[2000005],b[2000005];
int to[5005];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);////////////
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>T;
	while(T--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		} 
//		if(c<=10){
			int ans=0;
			for(int qwq=0;qwq<=n+1;qwq++){
				to[qwq]=0;
			}
//			memset(to,0,sizeof(to));
			for(int i=1;i<=n;i++){
				for(int j=i;j<=n;j++){
					if(x[j]-x[i]<=d){
						to[i]=j;
					}
					else{
						break;
					}
				}
			}
			for(int i=1;i<=n;i++){
				for(int qwq=0;qwq<=n+1;qwq++){
					dis[qwq]=1e17;
					dif[qwq]=0;
					wy[qwq]=0;
				}
//				memset(dis,0x3f,sizeof(dis));
//				memset(dif,0,sizeof(dif));
//				memset(wy,0,sizeof(wy));
				dis[i]=0;
				int ls=i;
//				cout<<"//:";
				for(int j=i;j<=n;j++){
					if(dis[j]>1e9){
						break;
					}
					for(int k=ls;k<=to[j];k++){
						dis[k]=min(dis[k],dis[j]+1);
					}
//					cout<<dis[j]<<' ';
					ls=to[j]+1;
				}
//				cout<<endl;
				wy[i]=1;
				int far=0;
				int sum=0;
				for(int j=i;j<=n;j++){
//					if(wy[i]==0){
//						break;
//					}
					sum+=dif[j];
					wy[j]+=sum;
					if(j==i||dis[j]!=dis[j-1]){
						for(int k=j;k<=n;k++){
							if(dis[k]==dis[j]){
								far=k;
							}
							else{
								break;
							}
						}
					}
//					cout<<'('<<far+1<<' '<<to[j]<<')'<<' ';
					dif[far+1]+=wy[j];
					dif[to[j]+1]-=wy[j];
//					cout<<wy[i]<<' ';
					if(wy[j]==2){
						ans++;
					}
				}
//				cout<<endl;
			}
			cout<<ans<<endl;
//		}
//		else{
//			for(int i=1;i<=n;i++){
//				
//			}
//		}
	}
	return 0;
}
//3h磕T3应该死磕的出来。
//1.5h后不敢磕了。 
/*
0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6


1.构成双屿路径对的块一定是相邻的 
a<b<c<d c-a,d-b<=D
2.定义一个多屿路径对为
a<b<e<c<d c-a<D d-b<D
 
*/ 