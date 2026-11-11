#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+1;
ll c,n,m,d,q,w[501],k,a[501][501];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for (int i=1;i<=m;i++){
		cin>>w[i];
	}
	memset(a,0x3f,sizeof(a));
	for (int i=1,u,v;i<=n;i++){
		cin>>k;
		ll s=0;
		for (int i=1,w;i<=k;i++){
			if (i==1){
				cin>>u;
			}else {
				cin>>v;
			}
			cin>>w;
			s+=w;
		}
		a[u][v]=s;
		a[v][u]=s;
	}
	for (int i=1;i<=n;i++){
		for (int j=1;j<=n;j++){
			for (int k=1;k<=n;k++){
				a[j][k]=min(a[j][k],a[j][i]+a[i][k]);
			}
		}
	}
	while (q--){
		int x,y;
		cin>>x>>y;
		cout<<w[x]+w[y]+a[x][y]<<"\n";
	}
	return 0;
} 