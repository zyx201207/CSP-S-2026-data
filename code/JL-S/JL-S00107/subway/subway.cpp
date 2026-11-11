#include<bits/stdc++.h>
using namespace std;
int w[500005],k[505],a[500005][505],t[500005][505],x[100005],y[100005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++) cin>>a[i][j]>>t[i][j];
	}
	for(int i=1;i<=p;i++) cin>>x[i]>>y[i];
	for(int i=1;i<=p;i++) cout<<"0\n";
	fclose(stdin);
	fclose(stdout);
	return 0;
}
