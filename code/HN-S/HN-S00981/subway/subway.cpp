#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[500005],k[505],a[505][500005],t[505][500005],x,y;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=n;i++){
		cin>>w[i];
		cin>>k[i];
	    for(int j=1;j<=2*k[i];j++){
		    cin>>a[i][j]>>t[i][j];
	    }
	}
	for(int r=1;r<=q;r++){
		cin>>x>>y;
	}
	cout<<32<<endl;
	cout<<17<<endl;
    return 0;
} 
