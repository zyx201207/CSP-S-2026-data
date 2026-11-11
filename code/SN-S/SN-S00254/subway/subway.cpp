#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
long long w[500005];
int k[505];
int a[505][500005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int xr,yr;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	int g=0;
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>g;
			cin>>a[i][g];
		}
	}
	for(int u=1;u<=q;u++){
		cin>>xr>>yr;
		for(int i=1;i<=n;i++){
			cout<<a[i][xr]+a[i][yr]+w[xr]+w[yr]<<endl;
		}
	}
	return 0;
}
