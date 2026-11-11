#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,d,q,k[1005],w[1005],a[1005][1005],t[1005][1005],f[1005][1005];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld %lld %lld %lld %lld",&c,&m,&n,&d,&q);
	for(int i=1;i<=n;i++) scanf("%lld",&w[i]);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			f[i][j]=INT_MAX;
		}
	}
	for(int i=1;i<=m;i++){
		scanf("%lld",&k[i]);
		for(int j=1;j<=k[i];j++){
			scanf("%lld %lld",&a[i][j],&t[i][j]);
		}
		for(int j=1;j<=k[i];j++){
			for(int l=1;l<=k[i];l++){
				if(t[i][j]<f[a[i][j]][a[i][l]]) 
					f[a[i][j]][a[i][l]]=t[i][j];
			}
		}
	}
	for(int z=1;z<=n;z++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(f[i][j]>f[i][z]+f[z][j]){
					f[i][j]=f[i][z]+f[z][j];
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cout<<f[i][j]<<" ";
		}
		cout<<"\n";
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		cout<<w[x]+w[y]+f[x][y];
	}
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2*/
