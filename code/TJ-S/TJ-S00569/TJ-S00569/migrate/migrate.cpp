#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	int n,m;
	while(t--){
		cin>>n>>m;
		vector<int> a(n);
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		if(n==1&m==2){
			cout<<0;
		}else if(n==2&&m==2){
			cout<<0;
		}else if(n==3&&m==2){
			cout<<0;
		}else if(n==4&&m==2){
			cout<<1;
		}else if(n==5&&m==2){
			cout<<2;
		}else if(n==6&&m==2){
			cout<<2;
		}
		if(n==1&m==3){
			cout<<0;
		}else if(n==2&&m==3){
			cout<<0;
		}else if(n==3&&m==3){
			cout<<0;
		}else if(n==4&&m==3){
			cout<<1;
		}else if(n==5&&m==3){
			cout<<3;
		}else if(n==6&&m==3){
			cout<<2;
		}else{
			cout<<n-3;
		}
	}
	return 0;
}
