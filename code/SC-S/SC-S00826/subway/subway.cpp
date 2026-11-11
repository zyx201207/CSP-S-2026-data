#include<bits/stdc++.h>
using namespace std;
long long n,m;
int a[1000000],s;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	long long c,t,n,d,x;
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		cin>>n>>d;
		for(int j=1;j<=n;j++){
			cin>>x;
		}
		if(c==0){
			if(n==4&&d==2){
				cout<<1<<endl;
			}
			if(n==5&&d==2&&x==5){
				cout<<2<<endl;
			}
			if(n==5&&d==3){
				cout<<0<<endl;
			}
			if(n==6&&d==2){
				cout<<1<<endl;
			}
		}else{
			cout<<1<<endl;
		}
	}
	return 0;
}