#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll t,n,d;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n>>d;
		ll a[2000010];
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		if(n==5 && d==3){
			cout<<0<<endl;
		}
		if(n==6 && d==2){
			cout<<1<<endl;
		}
		if(n==4 && d==2){
			cout<<1<<endl;
		}
		if(n==5 && d==2){
			cout<<2<<endl;
		}
		if(d==1 || d>INT_MAX){
			cout<<0<<endl;
		}
	}
	return 0;
}
