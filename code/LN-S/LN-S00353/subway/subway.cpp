#include<bits/stdc++.h>
using namespace std;
const int MAXN=500005;
int c,n,m,d,q;
int w[MAXN],k[505],a[505][MAXN],t[505][MAXN],x[100005],y[100005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++) cin>>a[i][j]>>t[i][j];
	}
	for(int i=1;i<=q;i++) cin>>x[i]>>y[i];       
	if(n==1){
		for(int i=1;i<=q;i++){
			cout<<w[x[i]]+w[y[i]]+t[1][x[i]]+t[1][y[i]]<<endl;
		}
	}
	return 0;
}
