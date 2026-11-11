#include <bits/stdc++.h>

using namespace std;
int c,n,m,d,q;
long long g[405][405];
long long ab[500005];
long long bc[500005];
long long lt[500005];
//priority_queue <node> pq;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>ab[i];
	}
	int k;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			if(i!=j)g[i][j]=1e18;
		}
	}
	
	int maxx=0;
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>lt[j]>>bc[j];
		}
		for(int j=1;j<=k;j++){
			for(int ii=1;ii<=k;ii++){
				if(j==ii)continue;		
				g[lt[j]][lt[ii]]=bc[j]+bc[ii];
			}
		}
	}
	for(int zj=1;zj<=m;zj++){
		for(int i=1;i<=m;i++){
			for(int j=1;j<=m;j++){
				g[i][j]=min(g[i][j],g[i][zj]+g[zj][j]);
			}
		}
	}
	
	int xx,yy;
	while(q--){
		cin>>xx>>yy;
		cout<<ab[xx]+g[xx][yy]+ab[yy]<<endl;
	}
	return 0;
}

