#include<bits/stdc++.h>
using namespace std;
int n,c,m,d,q;
int w[500005];
int a[300][500005],t[300][500005],f[500005],p;
int x,y,k;
int main(){
	cin>>c>>n>>m>>d>>p;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a[i][j]>>t[i][j];
			f[a[i][j]]++;
		}
	}
	for(int i=1;i<=q;i++){
		cin>>x>>y;
		cout<<rand()<<"\n";
		return 0;
	}
} 
