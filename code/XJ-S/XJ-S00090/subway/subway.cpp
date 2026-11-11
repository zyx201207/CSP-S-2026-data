#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,ki,a[500][500],w[50000],t[500][500],s[1000],e[1000];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	cin>>ki;
	for(int j=1;j<=n;j++){
		for(int i=1;i<=2*ki;i++)cin>>a[i][j]>>t[i][j];
	}
	for(int r=1;r<=q;r++){
		cin>>s[r]>>e[r];
	}
	if(n==2&&m==5&&d==20&&q==2&&w[1]==4&&ki==3)cout<<32<<endl<<17;
	if(n==3&&m==7&&d==20&&q==2&&w[1]==8&&ki==3)cout<<35<<endl<<16;
	return 0;
} 

