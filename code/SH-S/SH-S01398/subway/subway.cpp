#include<iostream>
#include<cstdio>
const int maxm=10001;
long long W[maxm],a[maxm],t[maxm],w[maxm][maxm];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	long long C,N,M,D,Q;
	std::cin>>C>>N>>M>>D>>Q;
	for(int i=1;i<=M;i++)std::cin>>W[i];
	for(int i=0;i<=M;i++)
		for(int j=0;j<=M;j++)w[i][j]=2*1e9+1; 
	for(int i=0;i<N;i++){
		int k;
		std::cin>>k;
		for(int j=0;j<k;j++)std::cin>>a[j]>>t[j];
		for(int x=0;x<k;x++)
			for(int y=x+1;y<k;y++)
				w[a[x]][a[y]]=std::min(w[a[x]][a[y]],t[x]+t[y]),
				w[a[y]][a[x]]=std::min(w[a[y]][a[x]],t[x]+t[y]); 
	}
//	for(int i=1;i<=M;i++){
//		for(int j=1;j<=M;j++)std::cout<<w[i][j]<<" ";
//		std::cout<<"\n";
//	}
	for(int k=1;k<=M;k++){
		for(int i=1;i<=M;i++){
			for(int j=i+1;j<=M;j++){
				w[i][j]=std::min(w[i][j],w[i][k]+w[k][j]);
				w[j][i]=std::min(w[j][i],w[j][k]+w[k][i]);
			}
		}
	}
	while(Q--){
		int x,y;
		std::cin>>x>>y;
		std::cout<<w[x][y]+W[x]+W[y]<<"\n";
	}
	return 0;
}
