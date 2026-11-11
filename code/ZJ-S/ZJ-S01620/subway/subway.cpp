#include<bits/stdc++.h>
using namespace std;
long long w[505],t[505][505],f[505][505],x[505][505],y[505][505];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	long long c,n,m,d,q;
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++){
		scanf("%lld",&w[i]);
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			f[i][j]=5*1e11;
		}
	}
	for(long long i=1;i<=n;i++){
		long long z;
		scanf("%lld",&z);
		for(int j=1;j<=z;j++){
			scanf("%lld%lld",&x[i][j],&y[i][j]);
		}
		for(long long j=1;j<=z;j++){
			for(long long k=j+1;k<=z;k++){
				if(j==k) continue;
				f[min(x[i][j],x[i][k])][max(x[i][j],x[i][k])]=min(f[min(x[i][j],x[i][k])][max(x[i][j],x[i][k])],y[i][j]+y[i][k]);
			}
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=i+1;j<=m;j++){
			for(int k=1;k<=m;k++){
				if(i==k||j==k) continue;
				if(f[min(i,k)][max(i,k)]==0||f[min(j,k)][max(j,k)]==0) continue;
				f[min(i,j)][max(i,j)]=min(f[min(i,j)][max(i,j)],f[min(i,k)][max(i,k)]+f[min(j,k)][max(j,k)]);
			}
		}
	}
	while(q--){
		int a,b,a1,b1;
		scanf("%d%d",&a1,&b1);
		a=min(a1,b1);
		b=a1+b1-a;
		long long ans=f[a][b]+w[a]+w[b];
		printf("%lld",ans);
		cout<<endl;
	}
	return 0;
}

