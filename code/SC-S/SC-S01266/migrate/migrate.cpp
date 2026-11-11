#include<bits/stdc++.h>
using namespace std;
struct zzz{
	int shuliang,juli;
}b[5001][5001];
int a[2000006];
int c,t,n,d,sum;
void dfs(int qd,int zd){
	int snm=0;
	if((zd-qd)%d==0) snm=(zd-qd)/d;
	else snm=(zd-qd)/d+1;
	b[qd][zd].juli=snm;
	return ;
}
void ck(int qd,int wzh,int zd,int jl){
	if(jl==0){
		if(wzh==zd) b[qd][zd].shuliang++;
		return ;
	}
	for(int i=1;i<=d;i++) ck(qd,wzh+i,zd,jl-1);
}
int main(){
	cin.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		sum=0;
		for(int i=1;i<=n;i++) cin>>a[i];
		for(int i=1;i<=n;i++){
			for(int j=i+2;j<=n;j++){
				dfs(i,j);
				ck(i,i,j,b[i][j].juli);
			}
		}
		sum=0;
		for(int i=1;i<=n;i++)
			for(int j=i+2;j<=n;j++)
				if(b[i][j].shuliang==2)
					sum++;
		cout<<sum<<"\n";
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				b[i][j].juli=0;
				b[i][j].shuliang=0;
			}
		}
	}
	return 0; 
}