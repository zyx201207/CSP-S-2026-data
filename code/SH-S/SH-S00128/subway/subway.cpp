#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,a[50000005],k,o,p;
int b[505][500005];
int main(){
	
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
	cin>>o>>p;
	b[i][o]=p;
		}
	}


while(q--){
cin>>o>>p;
if(n==1){
cout<<a[o]+a[p]+b[1][o]+b[1][p];return 0;}

for(int i=1;i<=n;i++){
	for(int j=1;j<=m;j++){
		if(b[i][o]!=0){
			cout<<cout<<a[o]+a[p]+b[i][o]+b[i][p];return 0;
		}
	}
}

	}
	return 0;
}  
