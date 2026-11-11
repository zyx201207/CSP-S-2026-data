#include<bits/stdc++.h>
using namespace std;
const int MAX_M=5e5+10;
const int MAX_N=505;
int C,N,M,D,Q,K;
int W[MAX_M];
int Ti[MAX_N][MAX_M];
int Dis[MAX_N][MAX_N];
int S[MAX_M]={0};
bool check[MAX_N][MAX_M];
int X,Y;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>C>>N>>M>>D>>Q;
	for(int i = 1;i<=M;i++){cin>>W[i];}
	for(int i = 1;i<=N;i++){
		cin>>K;
		for(int j = 1;j<=K;j++){
			int A,B;cin>>A>>B;Ti[i][A]=B;check[i][A]=true;
			if(S[A]!=0){
				Dis[S[A]][i]=Dis[i][S[A]]=Ti[S[A]][A]+Ti[i][A];
			}
			else{S[A]=i;}
		}
	}
	for(int i = 1;i<=N;i++){
		for(int j = 1;j<=N;j++){
			for(int k = j+1;k<=N;k++){
				if(Dis[i][j]!=0&&Dis[i][k]!=0){
					Dis[k][j]=Dis[j][k]=(Dis[j][k]==0? Dis[i][j]+Dis[i][k]:min(Dis[j][k],Dis[i][j]+Dis[i][k]));
				}
			}
		}
	}
	while(Q--){
		int Ans=1e9;
		cin>>X>>Y;
		int E[MAX_N],F[MAX_N],L1=0,L2=0;
		for(int i = 1;i<=N;i++){
			if(check[i][X]){L1++;E[L1]=i;}
			if(check[i][Y]){L2++;F[L2]=i;}
		}
		for(int i = 1;i<=L1;i++){
			for(int j = 1;j<=L2;j++){
				Ans=min(Ans,Dis[E[i]][F[j]]+Ti[E[i]][X]+Ti[F[j]][Y]);
			}
		}
		cout<<Ans+W[X]+W[Y]<<endl;
	}
	return 0;
}
