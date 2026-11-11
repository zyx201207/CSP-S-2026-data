#include <iostream>
using namespace std;
int main(){
	int c,n,m,d,q,r,n,a[10086],b[10086],e[10086],f[10086],g[10086],h[10086];
	cin >> c >> n >> m >> d >> q;
	for(int i = 0;i<m;i++){
		cin>>a[i];
	}
	for(int i = 0;i<r;i++){
		cin>>b[i];
	}	
	for(int i = 0;i<r+n+2;i++){
		cin>>e[i];
	}	
	for(int i = 0;i<r+n+2;i++){
		cin>>f[i];
	}	
	for(int i = 0;i<2;i++){
		cin>>g[i];
	}
	for(int i = 0;i<2;i++){
		cin>>h[i];
	}	
	cout >> g[0]+g[1] >> endl;
	cout >> h[0]+h[1] >> endl;	
	return 0;
}
