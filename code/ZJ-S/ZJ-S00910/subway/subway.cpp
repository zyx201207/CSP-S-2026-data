#include<bits/stdc++.h>
using namespace std;
int op,n,m,T,x,y,mi,z,i,j,a[500100],b[500100],K,w[500100],A[1010][1010],k[510],c[500100],d[500100],g[510][510];
vector<int>f[500100],e[500100],F[500100],E[500100];
void js(int x,int y,int z,int s,bool fl){
	int i,sx,st;
	if(x==y){
		mi=min(mi,s);
		return ;
	}if(s>mi){
		return ;
	}if(fl){
		for(i=0;i<f[z].size();i++){
			sx=f[z][i];
			st=F[z][i];
			if(c[sx]>d[z]+st){
				c[sx]=d[z]+st;
				js(sx,y,z,s+st,0);
			}
		}
	}else{
		for(i=0;i<e[x].size();i++){
			sx=e[x][i];
			st=E[x][i];
			if(d[sx]>c[x]+st){
				d[sx]=c[x]+st;
				js(x,y,sx,s+st,1);
			}
		}
	}
}void dfs(int x,int y){
	if(mi<d[x]){
		return ;
	}if(x==y){
		mi=min(mi,d[x]);
		return ;
	}for(int i=0;i<f[x].size();i++){
		int sx=f[x][i];
		if(d[sx]>d[x]+F[x][i]){
			d[sx]=d[x]+F[x][i];
			dfs(sx,y);
		}
	}
}int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>op>>n>>m>>x>>T;
	if(op>=9&&op<=11){
		memset(A,0x3f,sizeof(A));
		for(i=1;i<=m;i++){
			cin>>w[i];
		}for(i=1;i<=n;i++){
			cin>>z;
			for(j=1;j<=z;j++){
				cin>>a[j]>>b[j];
				for(K=1;K<j;K++){
					f[a[j]].push_back(a[K]);F[a[j]].push_back(b[K]+b[j]);
					f[a[K]].push_back(a[j]);F[a[K]].push_back(b[j]+b[K]);
					A[a[j]][a[K]]=A[a[K]][a[j]]=min(b[j]+b[K],A[a[K]][a[j]]);
				}
			}
		}for(K=1;K<=m;K++){
			for(i=1;i<=m;i++){
				for(j=1;j<=m;j++){
					A[i][j]=min(A[i][j],A[i][K]+A[K][j]);
				}
			}
		}while(T--){
			cin>>x>>y;
			cout<<w[x]+w[y]+A[x][y]<<"\n";
		}
	}else{
		for(i=1;i<=m;i++){
			cin>>w[i];
		}for(i=1;i<=n;i++){
			cin>>z;
			for(j=1;j<=z;j++){
				cin>>x>>y;
				f[i].push_back(x);
				F[i].push_back(y);
				e[x].push_back(i);
				E[x].push_back(y);
			}
		}while(T--){
			memset(d,0x3f,sizeof(d));
			memset(c,0x3f,sizeof(c));
			cin>>x>>y;
			mi=2e9;
			c[x]=0;
			js(x,y,0,0,0);
			cout<<w[x]+w[y]+mi<<"\n";
		}
	}return 0;
}
