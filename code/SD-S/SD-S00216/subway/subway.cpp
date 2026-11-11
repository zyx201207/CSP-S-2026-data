#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int w[100100];
int k[1100];
int t[1100][1100],a[1100][1100];
int x[110000],y[110000];
int g[5][500500] ;
int ccc[10010];
void f(int kk,int ii){
	for(int i=1;i<=kk;i++){
		for(int j=1;j<=kk;j++){
			g[a[ii][i]][a[ii][j]]=0;
			g[a[ii][j]][a[ii][i]]=0;
		}
	}	
	return ;
} 
void bb(int in,int out,int s1,int s2){
	for(int i=1;i<=k[s1];i++){
		for(int j=1;j<=k[s2];j++){
			g[a[s1][i]][a[s2][j]]=min(g[a[s1][i]][a[s2][j]],t[s1][in]+t[s2][out]);
		}
	}
	return ;
}
int find (int qwe){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i][j]==qwe){
				return t[i][j];
			}
		}
	}
	return 0;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	for(int i=1;i<=2;i++){
		for(int j=1;j<=500000;j++){
			g[i][j]=999999999;
		}
	}
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
		}
		f(k[i],i);
	}
	for(int i=1;i<=q;i++){
		cin>>x[i]>>y[i];
	}
	for(int o=1;o<=n;o++){
		for(int oo=1;oo<=n;oo++){
			for(int i=1;i<=k[o];i++){
				for(int j=1;j<=k[oo];j++){
					int in=a[o][i];
					int out=a[oo][j];
					if(in ==out){
						bb(i,j,o,oo);
					}
				}
			}
		} 
	}
	for(int i=1;i<=m;i++){
		ccc[i]=find(i);
	}
	for(int i=1;i<=q;i++){
		int zhan=w[x[i]]+w[y[i]];
		int asd=ccc[x[i]]+ccc[y[i]];
		cout<<zhan+asd+g[x[i]][y[i]]<<endl;
	}
	return 0;
	
} 

