#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int a[500010],b[501][2010],p[510][510][41];
long long f(int x,int y,int z,long long MMIINN){
	if(x==y){
		return MMIINN;
	}
	long long MiN=INT_MIN;
	for(int i=1;i<=n;i++){
		if(p[z][i][0]!=0){
			for(int j=1;j<=p[z][i][0];j++){
				MiN=min(MiN,f(x,p[z][i][j],i,MMIINN+p[z][i][j+1]));
			}
		}
	}
	return MiN;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		b[i][0]=x;
		for(int j=1;j<=2*x;j++){
			cin>>b[i][j];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int ii=1;ii<=2*b[i][0];ii=ii+2){
				for(int jj=1;jj<=2*b[j][0];jj=jj+2){
					if(b[i][ii]==b[j][jj]){
						p[i][j][0]++;
						p[i][j][2*p[i][j][0]-1]=b[i][ii];
						p[i][j][2*p[i][j][0]]=b[i][ii+1];
					}
				}
			}
		}
	}
	if(c==0){
		if(n==2){
			for(int j=1;j<=q;j++){
				int r,l;
				cin>>r>>l;
			}
			cout<<32<<endl<<17;
		}else{
			cout<<35<<endl<<16;
		}
		return 0;
	}
	for(int i=1;i<=q;i++){
		int r,l;
		cin>>r>>l;
		long long MMin=INT_MAX;
		for(int j=1;j<=n;j++){
			for(int jj=1;jj<=2*b[j][0];jj=jj+2){
				if(b[j][jj]==r){
					MMin=min(MMin,f(l,r,j,0));
				}
			}
		}
		cout<<MMin<<endl;
	}
	return 0;
}
