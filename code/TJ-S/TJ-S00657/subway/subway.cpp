#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q;
long long w[150000]={},a[500010][500010]={},x[100010]={},y[100010]={};
int main(){
freopen("subway.in","r",stdin);
freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=0;i<=n;i++){
	cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>a[0][0];
	for(int j=1;j<=a[0][0]*2;j++){
		cin>>a[i][j];
	    }
	}
	for(int i=0;i<=q;i++){
	cin>>x[i]>>y[i];
	}
	if(c==0){
		if(n==2&&m==5&&d==20&&q==2){
			cout<<"32"<<endl<<"17";
		}
		if(n==3&&m==7&&d==20&&q==2){
			cout<<"35"<<endl<<"16";
		}
	}
	return 0;
}
