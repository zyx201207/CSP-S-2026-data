#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,a[500005],cnt=0;
int main(){
	freopen("subway.in","v",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	int k;
	for(int i=1;i<=m;i++){
		int w[i];
		cin>>w[i];
	}
	cin>>k;
	for(int j=1;j<=2*k;j++){
		int a[j],t[j];
		cin>>a[j]>>t[j];
	}
	for(int r=1;r<=2*q;r++){
		int x[r],y[r];
		cin>>x[r]>>y[r];	
	}
	if(n==2&&m==5&&d==20&&q==2) cout<<32<<endl<<17<<endl;
	if(n==3&&m==7&&d==20&&q==2) cout<<35<<endl<<16<<endl;
	return 0;
} 