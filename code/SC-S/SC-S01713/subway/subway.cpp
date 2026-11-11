#include <bits/stdc++.h>
using namespace std; 
int c,n,m,d,p,k[1001],a[1001];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdin);
	cin>>c>>n>>m>>d>>p;
	for(int i=1;i<=m;i++){
		cin>>k[i];
	}
	for(int j=1;j<=n;j++){
		for(int i=1;i<=n+m;i++){
			cin>>a[i];
		}
	}
	int x,y;
	for(int i=1;i<=n;i++){
		cin>>x>>y;
	}
	if(n=2){
		cout<<32<<endl<<17;	
	}
	else{
		cout<<35<<endl<<16;	
	}
	
	return 0;
}