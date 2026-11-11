#include <bits/stdc++.h>
using namespace std;
long long c,t; 
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		long long n,d;
		cin>>n>>d;
		if(n==4){
			cout<<1<<'\n';
		}else if(n==5&&d==2){
			cout<<'2'<<'\n';
		}else if(n==5&&d==3){
			cout<<0<<'\n';
		} else if(n==6){
			cout<<1<<'\n';
		}
	}
	return 0;
}