#include <bits/stdc++.h>
using namespace std;

int a[500][500005],t[500][500005],w[500005];

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		int a=min(x,y),b=max(x,y);
		for(int i=a;i<b;i++){
			sum+=t[i][i]+t[i][i+1];
		}
		cout<<w[x]+w[y]+sum;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
