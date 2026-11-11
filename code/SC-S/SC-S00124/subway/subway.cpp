#include <bits/stdc++.h>
using namespace std;
int w[100000000],k[100000000],x[100000000],y[100000000];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);		
	int c,n,m,d,p,q;
	cin>>c>>n>>m>>d>>p;
	for(int i=0;i<m;i++){
		cin>>w[i];
	}
	for(int i=0;i<1+2*k[i];i++){
		cin>>k[i];
	}
	for(int i=0;i<q;i++){
		cin>>x[i],y[i];
	}
	for(int i=0;i<q;i++){
		cout <<min(x[i]*y[i]/k[i]%w[i],k[i]*y[i]/w[i]%x[i],y[i]*k[i]/x[i]%w[i])<<endl;
	}
	return 0;
}