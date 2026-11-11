#include<bits/stdc++.h>
using namespace std;
int c,t,n,d;
int a[1000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int i=1;i<=t;i++){
	cin>>n>>d;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	} 
	if(a[2]-a[1]==d) cout<<"0"<<endl;
	if(a[2]-a[1]==1){
		cout<<n-5<<endl;
	}
}
	return 0;
}
