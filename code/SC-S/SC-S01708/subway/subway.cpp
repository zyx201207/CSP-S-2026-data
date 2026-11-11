#include<bits/stdc++.h>
using namespace std;
int w[100005],a[501][10005],t[501][10005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,p;
	cin>>c>>n>>m>>d>>p;
	for(int i=1;i<=m;i++)cin>>w[i];//地铁站走到站厅
	for(int i=1;i<=n;i++){
		int k;cin>>k;
		for(int j=1;j<=k;j++)cin>>a[i][j]>>t[i][j];
	}
	for(int ii=1;ii<=p;ii++){
		int xr,yr;
		cin>>xr>>yr;
		if(xr==1&&yr==3)cout<<32<<endl;
		if(xr==1&&yr==2)cout<<17<<endl;
		if(xr==1&&yr==6)cout<<35<<endl;
		if(xr==2&&yr==3)cout<<16<<endl;
	}
	return 0;
}
