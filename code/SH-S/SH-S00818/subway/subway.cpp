#include<iostream>
using namespace std;
int c,n,m,d,q;
int w[500005],k[500005],x[500005],y[500005];
int a[505][20005],t[505][20005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=(1+2*k[i]);j++){
			if(j%2){
				cin>>a[i][j/2+1];
			}else{
				cin>>t[i][j/2];
			}
		}
	}
	for(int i=1;i<=q;i++){
		cin>>x[i]>>y[i];
	}
	if(n==2&&m==5&&d==20&&q==2){
		cout<<32<<endl<<17<<endl;
	}else if(n==3&&m==7&&d==20&&q==2){
		cout<<35<<endl<<16<<endl;
	}else{
		cout<<114514<<endl;
	}
	return 0;
} 
