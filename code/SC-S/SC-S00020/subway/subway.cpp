#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
const int M=505;
int c,n,m,d,q;
int w[N];
int k[N];
int a[M][N],t[M][N];
int x[N],y[N];
int shijian[N];
bool flag[N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d %d %d %d %d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++){
		scanf("%d ",&w[i]);
	}
	for(int i=1;i<=n;i++){
		scanf("%d ",&k[i]);
		for(int j=1;j<=k[i];j++){
			scanf("%d %d",&a[i][j],&t[i][j]);
		}
	}
	for(int i=1;i<=q;i++){
		scanf("%d %d",&x[i],&y[i]);
	}
	for(int i=1;i<=q;i++){
		int posa,posb;
		for(int j=1;j<=n;j++){
			for(int z=1;z<=k[i];z++){
				if(a[j][z]==x[i])posa=j;
				if(a[j][z]==y[i])posb=j;
			}
		}
		if(posa==posb)flag[i]=true;
	}
	for(int i=1;i<=q;i++){
		int posa;
		if(flag[i]==true){
			for(int j=1;j<=n;j++){
				for(int z=1;z<=k[i];z++){
					if(a[j][z]==x[i])posa=j;
				}
			}
			shijian[i]=w[x[i]]+t[posa][x[i]]+t[posa][y[i]]+w[y[i]];
		}else{
			int posa,posb,posc;
			for(int j=1;j<=n;j++){
				for(int z=1;z<=k[i];z++){
					if(a[j][z]==x[i])posa=j;
					if(a[j][z]==y[i])posb=j;
					for(int p=1;p<=k[i];p++){
						if(a[j][z]==a[j+1][p])posc=a[j][z];
					}
				}
			}
			shijian[i]=w[x[i]]+t[posa][x[i]]+(t[posa][posc]+t[posb][posc])+t[posb][y[i]]+w[y[i]];
		}
	}
	for(int i=1;i<=q;i++){
		printf("%d\n",shijian[i]);
	}
	return 0;
}