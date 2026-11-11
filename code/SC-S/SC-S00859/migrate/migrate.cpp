#include<bits/stdc++.h>
using namespace std;
int x[100000];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);	
	int c,t,sun=0;
	cin>>c>>t;
	while(t--){
		int n,d;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		if(sun==1) cout<<0;
		if(sun==2) cout<<1;
		if(sun>2) cout<<2;
	}
	return 0;
}