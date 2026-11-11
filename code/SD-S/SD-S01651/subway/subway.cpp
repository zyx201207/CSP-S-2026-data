#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,k,ww[500],a[1010],t[1010],ans,w[1010][1010];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(long long i=1;i<=m;i++){
		cin>>ww[i];
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			w[i][j]=10000000010;
		}
	}
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a[j]>>t[j];
		}
		for(int j=1;j<=k;j++){
			for(int l=1;l<=k;l++){
				w[a[j]][a[l]]=min(t[l]+t[j],w[a[j]][a[l]]);
			}
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			for(int l=1;l<=m;l++){
				 w[i][j]=min(w[i][j],w[i][l]+w[l][j]);
			}
		}
	}
	while(q--){
		long long v,u;
		cin>>u>>v;
		cout<<w[u][v]+ww[u]+ww[v]<<"\n";
	}
	return 0;
}

