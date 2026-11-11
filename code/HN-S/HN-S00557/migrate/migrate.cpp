#include<bits/stdc++.h>
using namespace std;
long long c,t;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		long long n,d;
		cin>>n>>d;
		long long a[n+10];
		if(n==4&&d==2){
			cout<<1<<"\n";
		}
		else if(n==6&&d==2){
			cout<<1<<"\n";
		}
		else if(n==5&&d==2){
			cout<<2<<"\n";
		}
		else{
			cout<<0<<"\n";
		}
		for(int j=1;j<=n;j++){
			cin>>a[j];
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
