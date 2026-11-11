#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int w[500010];
int a[5001][5001],t[5001][5001];
int x,y;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);

	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int j=1;j<=n;j++){
		int k;
		cin>>k;
		for(int i=1;i<=k;i++) cin>>a[j][i]>>t[j][i];
	}
	while(q--){
		cin>>x>>y;
		cout<<w[x]+w[y]<<endl;
	}

	fclose(stdin);
	fclose(stdout);
	return 0;
}
