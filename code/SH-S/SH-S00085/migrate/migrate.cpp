#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int c,t;
const int N=5005,BN=2e6+5;
long long n,d;
long long x[BN];
int cnt[N][N];
int dis[N][N];
int ntx[BN],cnt2[BN],dis2[BN];
int dist(int u,int v,int st){
	return (v-u-1)/st+1;
	
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>t;
	while(t--){
		long long ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		for(int i=1;i<=n;i++){
			ntx[i]=upper_bound(x+1,x+n+1,x[i]+d)-x-1;
		//	cout<<x[i]<<" "<<ntx[i]<<"\n";
		}
		if(c==0 or c==12){
			for(int i=2;i<=n;i++){
				cnt2[i]=0;
				dis2[i]=0;
			}
			int st=ntx[1]-1;
			
			for(int len=2;len<=n;len++){
				int u=1;
					int v=u+len-1;
					int nt=ntx[u];
					if(u==nt){
						cnt2[v]=0;
					}
					else if(nt>=v){
						cnt2[v]=1;
					}
					else{
						int diss=dist(u,v,st);
						
						int cntt=0;
						for(int k=v-st;k<=v-1;k++){
							if(dist(u,k,st)+dist(k,v,st)!=diss) break;
							cntt+=cnt2[k];
							if(cntt>2) break;
						}
						cnt2[v]=cntt;
					}
			}
		//	for(int i=1;i<=n;i++){
		//		cout<<cnt2[i]<<" ";
		//	}
		//	cout<<endl;
			for(int i=2;i<=n;i++){
				if(cnt2[i]==2){
					ans+=(n-i+1);
				}
			//	cout<<ans<<' ';
			}
			cout<<ans<<"\n";
		}
		else{
		
			//cout<<x[1]<<"\n";
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					if(i!=j) dis[i][j]=1e9;
					else dis[i][j]=0;
					cnt[i][j]=0;
				}
			}
			
			//cout<<endl;
			
			
			for(int len=2;len<=n;len++){
				for(int u=1;u<=n-len+1;u++){
					int v=u+len-1;
					int nt=ntx[u];
					if(u==nt){
						cnt[u][v]=0;
					}
					else if(nt>=v){
						cnt[u][v]=1;
						dis[u][v]=1;
					}
					else{
						dis[u][v]=dis[nt][v]+1;
						int cntt=0;
						for(int k=nt;k>u;k--){
							if(dis[k][v]!=dis[nt][v]){
								break;
							}
							cntt+=cnt[k][v];
							if(cntt>2) break;
						}
						
						cnt[u][v]=cntt;
						if(cntt==2) ans++;
						
					}
				}
			}
	//		for(int i=1;i<=n;i++){
	//			cout<<i<<":";
	//			for(int j=i+1;j<=n;j++){
	//				if(cnt[i][j]==2){
	//					cout<<j<<' ';
	//				}
	//			} 
	//			cout<<"\n";
	//		}
			cout<<ans<<"\n"; 
		}
	}
	return 0;
} 
