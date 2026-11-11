#include<bits/stdc++.h>
using namespace std;
const int MAXN=501,MAXM=5e5+1,MAXQ=1e5+1;
int c,n,m,d,q;
int w[MAXM];
int k[MAXN],t[MAXM][MAXN],a[MAXM][MAXN];
int x[MAXQ],y[MAXQ];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;++i){
		cin>>w[i];
	}
	for(int i=1;i<=n;++i){
		cin>>k[i];
		for(int j=1;j<=k[i];++j){
			cin>>a[i][j]>>t[i][j];
		}
	}
	for(int i=1;i<=q;++i){
		cin>>x[i]>>y[i];
		cout<<w[x[i]]+t[1][x[i]]+w[y[i]]+t[1][y[i]]<<'\n';
	}
	return 0;
}
