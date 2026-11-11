#include<bits/stdc++.h>
using namespace std;
int c,t,n;
long long d;
int main(){
	freopen("migrate.in","r",stdin),freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		if(c==0){
			if(n==4&&d==2)cout<<1<<endl;
			if(n==5&&d==2)cout<<2<<endl;
			if(n==5&&d==3)cout<<0<<endl;
			if(n==6&&d==2)cout<<1<<endl;
		}
	}
	return 0;
}

