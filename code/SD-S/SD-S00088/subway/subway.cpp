#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e3+10;
int c,n,m,d,q;
int w[N],f[N][N],a[N],t[N];;
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;//m个站，n条线路 
	memset(f,0x3f,sizeof(f));
	for(int i=1;i<=m;i++){
		cin>>w[i];
		f[i][i]=0;
	}
//	cout<<"a\n";
	for(int i=1,k;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a[j]>>t[j];
		}
//		cout<<"a\n";
		for(int j=1;j<k;j++){
			for(int l=j+1;l<=k;l++){
//				cout<<a[j]<<' '<<t[j]<<" a "<<a[l]<<' '<<t[l]<<'\n';
				f[a[j]][a[l]]=min(f[a[j]][a[l]],t[j]+t[l]);
			}
		}
	}
//	cout<<"a\n";

	for(int k=1;k<=m;k++){
		for(int i=1;i<=m;i++){
			for(int j=1;j<=m;j++){
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
			}
		}
	}
//	for(int i=1;i<=m;i++){
//		for(int j=1;j<=m;j++){
//			cout<<f[i][j]<<' ';
//		}
//		cout<<'\n';
//	}
	while(q--){
		int x,y;
		cin>>x>>y;
//		cout<<x<<' '<<y<<' ';
		cout<<f[x][y]+w[x]+w[y]<<'\n';
	}
	return 0;
}

