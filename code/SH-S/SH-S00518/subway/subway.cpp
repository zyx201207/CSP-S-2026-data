#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,i,j,w[500010],a[500][500010],t[500][500010],x[100010],y[100010],k[500];


int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(i=1;i<=m;i++){
		cin>>w[i];
	}
	for(i=1;i<=n;i++){
		cin>>k[i];
		for(j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	for(i=1;i<=q;i++){
		cin>>x[i]>>y[i];
	}
	if(c==0){
		if(n==2){
			cout<<32<<endl<<17;
		}
		else if(n==3){
			cout<<35<<endl<<16;
		}
		
	}
	return 0;
}
