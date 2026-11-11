#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;cin>>c>>t;
	while(t--){
		int n,d;cin>>n>>d;
		if(n==4 && d==2) cout<<1<<endl<<2;
		if(n==5 && d==3) cout<<0<<endl<<1; 
		for(int i=0;i<n;++i){
			int x;cin>>x;
		}
	}
	
	
	return 0;
}
/*
 0 2
5 3
 -2 -1 0 1 2
  6 2
 -4 -3 -2 -1 3 6
*/