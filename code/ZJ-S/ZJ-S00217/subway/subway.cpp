#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[500005],k,a[505][500005],t[505][500005];
int main(){
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++)cin>>a[i][j]>>t[i][j];
	}
	while(q--){
		int x,y;
		cin>>x>>y;
	}
	return 0;
}
