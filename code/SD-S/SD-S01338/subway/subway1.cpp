#include<bits/stdc++.h>
using namespace std;
/*====================*/
#define endl '\n'
/*====================*/
const int N=5e2+10;
const int INF=0x7f7f7f7f;
/*====================*/
int a[N][N],b[N][N],w[N],k[N],c[N],g[N],h,n,m,d,q,minn=INF;
/*====================*/
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>h>>n>>m>>d>>q;
	for(int i=1;i<=m;++i) cin>>w[i];
	for(int i=1;i<=n;++i){
		cin>>k[i];
		for(int j=1;j<=k[i];++j) cin>>a[i][j]>>b[i][j];
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=k[i];++j){
			for(int t=1;t<=k[i];++t) if(a[i][j]==a[i][t]) c[i]=a[i][j],g[i]=b[i][j]+b[i][t];
		}
	}
	for(int i=1;i<=m;++i){
		if(c[i]) minn=min(minn,g[i]);
	}
	while(q--){
		int x,y;cin>>x>>y;bool flag=false;
		for(int i=1;i<=n;++i){
			if(a[i][x]&&a[i][y]){cout<<w[x]+w[y]+b[i][x]+b[i][y];}
			else {cout<<minn+w[x]+w[y];}
			cout<<endl;
			break;
		}
	}
	return 0;
}
