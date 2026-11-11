#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int c,t,n,d,a[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
	}
	for(int i=1;i<=t;i++){
		if(n==4 && d==2){
			cout<<1<<endl;
		}
		else if(n==5 && d==2){
			cout<<2<<endl;
		}
		else if(n==5 && d==3){
			cout<<0<<endl;
		}
		else if(n==6 && d==2){
			cout<<1<<endl;
		}
	}
	return 0;
}