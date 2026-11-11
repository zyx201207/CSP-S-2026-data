#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=510,K=1010;
int c,n,m,d,q;
int w[K],f[K+N][K+N];
vector<pair<int,int>> a[K+N];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	memset(f,0x3f,sizeof f);
	for(int i=1;i<=n;i++){
		f[i][i]=0;
	}
	int id=m;
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		id++;
		for(int z=1;z<=k;z++){
			int j,t;
			cin>>j>>t;
			a[id].push_back({j,t});
			a[j].push_back({id,t});
			f[id][j]=t;
			f[j][id]=t;
		}
	}
	for(int k=1;k<=m+n;k++){
		for(int i=1;i<=m+n;i++){
			for(int j=1;j<=m+n;j++){
				if(f[i][j]>f[i][k]+f[k][j]){
					f[i][j]=f[i][k]+f[k][j];
				}
			}
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		cout<<w[x]+w[y]+f[x][y]<<endl;
	}
	return 0;
	}
