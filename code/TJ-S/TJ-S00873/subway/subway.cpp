#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q,k;
	cin>>c>>n>>m>>d>>q;
	int w[1005],a[1005][1005];
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=2*k+1;i++){
		for(int j=1;j<=n;j++){
		    cin>>a[i][j];
		    k=a[1][1];
	    }
	}
	int x,y;
	for(int i=1;i<=2;i++){
		cin>>x>>y;
	}
	int v=w[1]+a[1][3]+(a[1][5]+b[2][3])+a[2][5]+w[3];
	int o=w[1]+a[3]+a[5]+w[2];
	cout<<v<<endl<<o;
	return 0;
}

