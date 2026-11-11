#include<bits/stdc++.h>
using namespace std;
const long long Max_M=1e3+10;
long long C,N,M,D,Q;
long long Entrence[Max_M];
long long Dis[Max_M];
long long K[510];
vector<long long>E[510];
long long A[510][Max_M];
long long T[510][Max_M];
long long Go[510][510];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);	
	cin>>C>>N>>M>>D>>Q;
	for(long long i=1;i<=M;i++) cin>>Entrence[i];
	memset(T,0x3f,sizeof(T));
	memset(Go,0x3f,sizeof(Go));
	for(long long i=1;i<=N;i++){
		cin>>K[i];
		for(long long j=1,t;j<=K[i];j++){
			cin>>A[i][j]>>t;T[i][A[i][j]]=t;
			E[i].push_back(A[i][j]);
		}
		sort(E[i].begin(),E[i].end());
	}
	for(long long i=1;i<=N;i++){
		for(long long j=i+1;j<=N;j++){
			for(long long k=0;k<E[i].size();k++){
				for(long long l=0;l<E[j].size();l++){
					if(E[i][k]==E[j][l])Go[i][j]=Go[j][i]=min(Go[i][j],T[i][E[i][k]]+T[j][E[j][l]]);
				}
			}
			
		}
	}
	
	for(long long i=1,X,Y;i<=Q;i++){
		cin>>X>>Y;
		if(N==1) cout<<Entrence[X]+Entrence[Y]+T[1][X]+T[1][Y]<<endl;
		if(N==2){
			long long ans=1e9;
			ans=min(ans,Entrence[X]+Entrence[Y]+T[1][X]+T[1][Y]);
			ans=min(ans,Entrence[X]+Entrence[Y]+T[2][X]+T[2][Y]);
			ans=min(ans,Entrence[X]+Entrence[Y]+Go[1][2]+min(T[1][X],T[2][X])+min(T[1][Y],T[2][Y]));
			cout<<ans<<endl;
		}
		if(N==3){
			long long ans=1e9;
			ans=min(ans,Entrence[X]+Entrence[Y]+T[1][X]+T[1][Y]);
			ans=min(ans,Entrence[X]+Entrence[Y]+T[2][X]+T[2][Y]);
			ans=min(ans,Entrence[X]+Entrence[Y]+T[3][X]+T[3][Y]);
			ans=min(ans,Entrence[X]+Entrence[Y]+Go[1][2]+min(T[1][X],T[2][X])+min(T[1][Y],T[2][Y]));
			ans=min(ans,Entrence[X]+Entrence[Y]+Go[1][3]+min(T[1][X],T[3][X])+min(T[1][Y],T[3][Y]));
			ans=min(ans,Entrence[X]+Entrence[Y]+Go[3][2]+min(T[3][X],T[2][X])+min(T[3][Y],T[2][Y]));
			long long t=min(Go[1][2]+Go[2][3],min(Go[1][2]+Go[1][3],Go[2][3]+Go[1][3]));
			ans=min(ans,Entrence[X]+Entrence[Y]+t+min(T[1][X],min(T[3][X],T[2][X]))+min(T[1][Y],min(T[3][Y],T[2][Y])));
			cout<<ans<<endl;
		}		
	}
	return 0;
}
