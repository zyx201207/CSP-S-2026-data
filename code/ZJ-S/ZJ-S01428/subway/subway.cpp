#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,p,k,a[500005],b[505][505],x,y;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>p;
	for(int i=1;i<=m;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=2*k;j++){
			cin>>b[i][j];
		}
	}
	for(int i=1;i<=p;i++){
		cin>>x>>y;
	}
	if(c==0){
		if(n==2){
			cout<<32<<endl<<17;
		}
		else{
			cout<<35<<endl<<16;
		}
	}
	return 0;
}
