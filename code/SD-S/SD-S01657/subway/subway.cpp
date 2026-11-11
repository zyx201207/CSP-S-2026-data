#include<bits/stdc++.h>
using namespace std;
const long long N=1e6+10;
int c,n,m,d,q,w[N],k[505][505],x,y,b[N];
int main(){
freopen("subway.in","r",stdin);
freopen("subway.out","w",stdout);
cin>>c>>n>>m>>d>>q;
for(int i=1;i<=m;i++){
	cin>>w[i];
}
for(int i=1;i<=n;i++){
	for(int j=1;j<=2*n+2;j++){
		cin>>k[i][j];
	}
}

cin>>x>>y;
for(int i=2;i<=2*n+1;i+=2){
	for(int j=x;j<=y;j++){
		b[i]=b[i]+w[i];	
		j=j+1;
	}
}
for(int i=1;i<=q;i++){
	
	cout<<(int)b[i]<<endl;
}
	return 0;
}
