#include<bits/stdc++.h>
using namespace std;
int w[500005],a[505][500005],t[505][500005];
int main(){
	int c,n,m,d,q;
	cin>>c>>n>>m>>d<<q;
	for(int i = 1;i<=m;i++){
		cin>>w[i];
	}
	if(7<=c&&c<=11){
		for(int i = 1;i<=n;i++){
			int k;
			cin>>k;
			if(k!=2){
				continue;
			}
			for(int j = 1;j<=k;j++){
				cin>>a[i][j]>>t[i][j];
			}
		}
	}
	if(7<=c&&c<=11){
		
	}
}
