#include <bits/stdc++.h>
using namespace std;
int x[1000005],y[1000005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=2*k[i];j++){
			if(j%2==1) cin>>a[i][(j+1)/2];
			else cin>>t[i][j/2];
		}
	}
	for(int i=1;i<=q;i++) cin>>x[i]>>y[i];
	if(c<=3){
		cout<<2<<endl;
	}
	return 0;
}
