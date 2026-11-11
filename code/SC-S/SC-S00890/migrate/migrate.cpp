#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		int n,d,i=1;
		cin>>n>>d;
		int x[200006];
		while(i<=n){
			cin>>x[i];
			i++;
		}
		if(x[2]-x[1]>d){
			
			cout<<0;
		}
		else{
			d/=x[2]-x[1];
			d=d*2-1;
			cout<<n-d<<"\n";
			
		}
	} 
	
	
	return 0;
}
//RP++